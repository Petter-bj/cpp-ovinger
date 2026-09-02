#include <climits>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  const char filename[] = "toerpot.dat";
  ofstream file;
  file.open(filename);
  if (!file) {
    cout << "Feil ved åpning av utfil" << endl;
    exit(EXIT_FAILURE);
  }

  long int product = 1L;
  int exponent = 0;
  while (product <= LONG_MAX / 2L) {
    exponent++;
    product *= 2L;
    file << "2 opphøyd i" << setw(4) << exponent
         << " er" << product << endl;
  }
  file.close();
}
