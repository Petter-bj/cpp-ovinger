#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string word;

  cout << "Srkiv ord, et på hver linje, avslutt med \"x\":" << endl;

  cin >> word;

  while (word != "x" && word != "X") {
    cout << word;
    for (size_t i = 0; i < word.length(); i++) {
      word[i] = toupper(word[i]);
    }

    cout << " Omformet: " << word << endl;
    cin >> word;
  }
}
