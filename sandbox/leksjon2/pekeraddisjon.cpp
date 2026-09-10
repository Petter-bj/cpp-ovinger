#include <iostream>

using namespace std;

int main() {
  const int m = 5;
  int ints[m];
  double floats[m];

  cout << "heltallsadresser:\n";
  for (int i = 0; i < m; i++) {
    cout << (ints + i) << endl;
  }

  cout << "\nflyttalladresser:\n";
  for (int i = 0; i < m; i++) {
    cout << (floats + i) << endl;
  }
}