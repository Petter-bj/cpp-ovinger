#include <iostream>

using namespace std;

int main() {
  int i = 3;
  int j = 5;
  int *p = &i;
  int *q = &j;

  cout << "i: " << i << endl;
  cout << "&i: " << &i << endl;
  cout << "j: " << j << endl;
  cout << "&j: " << &j << endl;
  cout << "*p: " << *p << endl;
  cout << "p: " << p << endl;
  cout << "&p: " << &p << endl;
  cout << "*q: " << *q << endl;
  cout << "q: " << q << endl;
  cout << "&q: " << &q << endl;



  *p = 7;                 // endre i via p
  *q += 4;                // endre j via q
  *q = *p + 1;            // endre j igjen
  p = q;                  // p peker nå også på j
  cout << *p << " " << *q << endl;

  return 0;
}
