#include <iostream>
#include <string>

using namespace std;

int main() {
  string word1, word2, word3;

  cout << "Skriv inn ord 1: " << endl;
  cin >> word1;
  cout << "Skriv inn ord 2: " << endl;
  cin >> word2;
  cout << "Skriv inn ord 3: " << endl;
  cin >> word3;

  string sentence = word1 + " " + word2 + " " + word3 + ".";

  cout << "Ordene skjøtet sammen: \n" << sentence << endl;

  int length1 = word1.length();
  int length2 = word2.length();
  int length3 = word3.length();
  int totLength = sentence.length();

  cout << "Ord1 lengde: " << length1 << endl;
  cout << "Ord2 lengde: " << length2 << endl;
  cout << "Ord3 lengde: " << length3 << endl;
  cout << "Total lengde: " << totLength << endl;

  string sentence2 = sentence;


  if (sentence2.length() > 12) {
    for (int i = 10; i <= 12; i++) {
      sentence2[i] = 'x';
    }
  }

  cout << "sentence: " << sentence << endl;
  cout << "sentence2: " << sentence2 << endl;

  if (sentence.length() >= 5) {
    string sentence_start = sentence.substr(0, 5);
    cout << "sentence: " << sentence << endl;
    cout << "sentence_start: " << sentence_start;
    } else {
      cout << "Setningen er for kort må være minst 5 karakterer" << endl;
  }

  size_t pos = sentence.find("hallo");
  if (pos != string::npos) {
    cout << "Inneholder 'hallo' (på posisjon " << pos << ")" << endl;
  } else {
    cout << "Inneholder ikke 'hallo'" << endl;
  }

  while ((pos = sentence.find("er", pos)) != string::npos) {
    cout << "Fant 'er' på posisjon " << pos << endl;
    pos++;
  }
  return 0;
}
