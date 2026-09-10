#include <iostream>

using namespace std;

int main() {
  double number;
  double *p = &number;
  double &refrence = number;

  *p = 3;
  cout << number << endl;

  refrence = 2;
  cout << number << endl;

  number = 1;
  cout << number << endl;

  return 0;
}
