#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class ChessBoard {
public:
  enum class Color { WHITE,
                     BLACK };

  class Piece {
  public:
    Piece(Color color) : color(color) {}
    virtual ~Piece() {}

    Color color;
    std::string color_string() const {
      if (color == Color::WHITE)
        return "white";
      else
        return "black";
    }

    /// Return color and type of the chess piece
    virtual std::string type() const = 0;

    /// Returns true if the given chess piece move is valid
    virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;

    /// Text representation of the chess pieces
    virtual std::string print() const = 0;
  };


  class King : public Piece {
  public:
    King(Color color)
      : Piece(color) {}

    string type() const override {
      return "King";
    }

    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      int dx = from_x - to_x;  // distanse flyttet x
      int dy = from_y - to_y;  // distanse flytte y

      if (dy == 0 && dx == 0) {                // brikken må flytte seg for å være et godkjent trekk
        return false;
      }
      if (abs(dx) > 1 || abs(dy) > 1) {       // Kongen kan kun flytte seg 1 plass i y og x reting
        return false;
      }

      return true;
    }

    string print() const override {
      if (color_string() == "white") {
        return "wK ";
      }
      return "bK ";
    }

  };




  class Knight : public Piece {
  public:
    Knight(Color color)
      : Piece(color){}

    string type() const override {
      return "Knight";
    }

    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      int dx = from_x - to_x;
      int dy = from_y - to_y;

      if ((abs(dx) == 2 && abs(dy) ==1) || (abs(dy) == 2 && abs(dx) == 1)) {   //kan bevege seg i L form kun 2 + 1
        return true;
      }
      return false;
    }


    string print() const override {
      if (color_string() == "white") {
        return "wKN";
      }
      return "bKN";
    }
  };



  ChessBoard() {
    // Initialize the squares stored in 8 columns and 8 rows:
    squares.resize(8);
    for (auto &square_column : squares)
      square_column.resize(8);
  }

  function<void(const Piece &piece, const string &from, const string &to)> on_piece_move;
  function<void(const Piece &piece, const string &square)> on_piece_removed;
  function<void(Color color)> on_lost_game;
  function<void(const Piece &piece, const string &from, const string &to)> on_piece_move_invalid;
  function<void(const string &square)> on_piece_move_missing;
  function<void()> after_piece_move;   // ekstra: kjøres ETTER et utført trekk

  /// 8x8 squares occupied by 1 or 0 chess pieces
  vector<vector<unique_ptr<Piece>>> squares;

  /// Move a chess piece if it is a valid move.
  /// Does not test for check or checkmate.
  bool move_piece(const std::string &from, const std::string &to) {
    int from_x = from[0] - 'a';
    int from_y = stoi(string() + from[1]) - 1;
    int to_x = to[0] - 'a';
    int to_y = stoi(string() + to[1]) - 1;

    auto &piece_from = squares[from_x][from_y];
    if (piece_from) {
      if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
        if (on_piece_move)                                   // lagt til on piece move fjernet cout
          on_piece_move(*piece_from, from, to);
        auto &piece_to = squares[to_x][to_y];
        if (piece_to) {
          if (piece_from->color != piece_to->color) {
            if (on_piece_removed)                     // Visst man slår ut en brikke fjernet cout
              on_piece_removed(*piece_to, to);
            if (auto king = dynamic_cast<King *>(piece_to.get()))
              if (on_lost_game)                       // visst kongen blir slått ut
                on_lost_game(king->color);
          } else {
            // piece in the from square has the same color as the piece in the to square
            if (on_piece_move_invalid)
              on_piece_move_invalid(*piece_from, from, to);
            return false;
          }
        }
        piece_to = std::move(piece_from);
        if (after_piece_move)
            after_piece_move();
        return true;
      } else {
        if (on_piece_move_invalid)
          on_piece_move_invalid(*piece_from, from, to);
        return false;
      }
    } else {
      if (on_piece_move_missing)
        on_piece_move_missing(from);
      return false;
    }
  }

  /// print function to print the board
  void print() {
    for (int y = 7; y >= 0; --y) {                     // starter på y = 7 for å gjøre det visuelt likt et sjakk brett med svart på topp
      for (int x = 0; x < 8; ++x) {                    // går gjennom kolonnene a-h i denne raden
        if (squares[x][y]) {
          cout << squares[x][y]->print();              // henter ut brikkens korte symbol hvis det står en brikke på ruten
        } else {
          cout << " . ";
        }
      }
      cout << endl;                                    // linje skifte når raden er ferdig
    }
  }
};

class ChessBoardPrint {
public:
  ChessBoardPrint(ChessBoard &board_) {
    board_.on_piece_move = [](const ChessBoard::Piece &piece,
      const string &from, const string &to) {
      cout << piece.type() << " is moving from " << from << " to " << to << endl;
    };

    board_.on_piece_removed = [](const ChessBoard::Piece &piece,
      const string &square) {
      cout << piece.type() << " is being removed from " << square << endl;
    };

    board_.on_lost_game = [](const ChessBoard::Color color) {
      string color_name;
      if (color == ChessBoard::Color::WHITE) {
        color_name = "White";
      } else {
          color_name = "Black";
      }
      cout <<color_name << " lost the game" << endl;
    };

    board_.on_piece_move_invalid = [](const ChessBoard::Piece &piece,
      const string &from, const string &to) {
      cout << "can not move " << piece.type() << " from " << from << " to " << to << endl;
    };

    board_.on_piece_move_missing = [](const string &square) {
      cout << "no piece at " << square << endl;
    };

    board_.after_piece_move = [&board_]() {
      board_.print();
    };

  }
};

int main() {  
  ChessBoard board;
  ChessBoardPrint printer(board);

  board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
  board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
  board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

  board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
  board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
  board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

    cout << "Invalid moves:" << endl;
    board.move_piece("e3", "e2");
    board.move_piece("e1", "e3");
    board.move_piece("b1", "b2");
    cout << endl;

  cout << "A simulated game:" << endl;
  board.move_piece("e1", "e2");
  board.move_piece("g8", "h6");
  board.move_piece("b1", "c3");
  board.move_piece("h6", "g8");
  board.move_piece("c3", "d5");
  board.move_piece("g8", "h6");
  board.move_piece("d5", "f6");
  board.move_piece("h6", "g8");
  board.move_piece("f6", "e8");
}