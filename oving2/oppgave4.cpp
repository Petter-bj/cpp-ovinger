#include <iostream>

using namespace std;

int main() {
  int a = 5;
  int &b = a; // orginal int &b; må referere til noe
  int *c = &a; // original int *c; pointeren trenger å initiliseres.
  //c = &b; gjør det samme som linjen over siden b og a deler adresse
  a = b + *c; // a er en int så kan ikke bruke *a samme gjelder b som er lik a
  b = 2; // &b = 2; vil ikke funke som å sette adresse = 2 det går ikke
  return 0;
}
