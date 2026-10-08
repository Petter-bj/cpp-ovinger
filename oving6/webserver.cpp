#include <boost/asio.hpp>
#include <iostream>
#include <memory>
#include <string>

using namespace std;
using namespace boost::asio::ip;

class WebServer {
private:
  class Connection {
  public:
    tcp::socket socket;
    Connection(boost::asio::io_context &io_context) : socket(io_context) {}
  };

  boost::asio::io_context io_context;

  tcp::endpoint endpoint;
  tcp::acceptor acceptor;

  void handle_request(shared_ptr<Connection> connection) {
    auto read_buffer = make_shared<boost::asio::streambuf>();
    // Read from client until newline ("\r\n")
    async_read_until(connection->socket, *read_buffer, "\r\n", [connection, read_buffer](const boost::system::error_code &ec, size_t) {
      // If not error:
      if (!ec) {
        // Retrieve request line from client, e.g. "GET /en_side HTTP/1.1"
        istream read_stream(read_buffer.get());
        std::string method;
        std::string path;
        std::string version;
        read_stream >> method >> path >> version;

        cout << "Request: " << method << " " << path << " " << version << endl;

        // Choose status and body based on the requested path
        std::string status;
        std::string body;

        if (path == "/") {
          status = "HTTP/1.1 200 OK\r\n";
          body = "Dette er hovedsiden";
        } else if (path == "/en_side") {
          status = "HTTP/1.1 200 OK\r\n";
          body = "Dette er en side";
        } else {
          status = "HTTP/1.1 404 Not Found\r\n";
          body = "404 Not Found";
        }

        // Build the HTTP response: status line, Content-Length header,
        // empty line, then the body
        auto write_buffer = make_shared<boost::asio::streambuf>();
        ostream write_stream(write_buffer.get());

        // Add response to be written to client:
        write_stream << status
                     << "Content-Length: " << body.size() << "\r\n"
                     << "\r\n"
                     << body << "\r\n";

        // Write to client
        async_write(connection->socket, *write_buffer, [connection, write_buffer](const boost::system::error_code &ec, size_t) {
          // If not error:
          if (!ec)
            connection->socket.close(); // response sent, close the connection
        });
      }
    });
  }

  void accept() {
    // The (client) connection is added to the lambda parameter and handle_request
    // in order to keep the object alive for as long as it is needed.
    auto connection = make_shared<Connection>(io_context);

    // Accepts a new (client) connection. On connection, immediately start accepting a new connection
    acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
      accept();
      // If not error:
      if (!ec) {
        handle_request(connection);
      }
    });
  }

public:
  WebServer() : endpoint(tcp::v4(), 8080), acceptor(io_context, endpoint) {}

  void start() {
    accept();

    io_context.run();
  }
};

int main() {
  WebServer web_server;

  cout << "Starting web server" << endl
       << "Connect in a browser with: http://localhost:8080" << endl;

  web_server.start();
}
