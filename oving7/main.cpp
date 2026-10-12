#include "fraction.hpp"
#include "heltallstabell.hpp"

#include <iostream>
#include <string>

using namespace std;

void print(const string &text, const Fraction &broek) {
  cout << text << broek.numerator << " / " << broek.denominator << endl;
}

int main() {
  Fraction a(10, 20);
  Fraction b(3, 4);
  Fraction c;
  c.set(5);
  Fraction d = a / b;

  print("a = ", a);
  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  b += a;
  ++c;
  d *= d;

  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  c = a + b - d * a;
  c = -c;

  print("c = ", c);

  if (a + b != c + d)
    cout << "a + b != c + d" << endl;
  else
    cout << " a + b == c + d" << endl;
  while (b > a)
    b -= a;
  print("b = ", b);

  int x = 10;

  Fraction i = x - b;
  Fraction f = b - x;

  cout << "int - frac: " << x << " - (" << b << ") = " << i << endl;

  cout << "frac - int: " << b << " - (" << x << ") = " << f << endl;

  //heltallstabell print
  Heltallstabell mengde1;
  Heltallstabell mengde2;

  mengde1 += 1;
  mengde1 += 4;
  mengde1 += 3;
  mengde2 += 4;
  mengde2 += 7;

  cout << "mengde1: " << mengde1 << endl;
  cout << "mengde2: " << mengde2 << endl;

  Heltallstabell unionen = mengde1 + mengde2;
  cout << "union:   " << unionen << endl;

  unionen += 4; //dupliakt skal ikke skje noe
  cout << "etter += 4: " << unionen << endl;

  Heltallstabell kopi;
  kopi = unionen;
  cout << "kopi:    " << kopi << endl;

}