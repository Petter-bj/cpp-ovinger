#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

void read_temperatures(double temperatures[], int length);

int main() {
    const int length = 5;
    double temperatures[length];
    int antallUnder = 0;
    int antallMellom = 0;
    int antallOver = 0;

    read_temperatures(temperatures, length);

    for (int i = 0; i < length; i++) {
        if (temperatures[i] < 10) {
            antallUnder++;
        }
        else if (temperatures[i] <= 20) {
            antallMellom++;
        }
        else {
            antallOver++;
        }
    }

    cout << "Antall under 10 er " << antallUnder << endl;
    cout << "Antall mellom 10 og 20 er " << antallMellom << endl;
    cout << "Antall over 20 er " << antallOver << endl;

    return 0;
}

void read_temperatures(double temperatures[], int length) {
    const char filename[] = "tallfil.dat";
    ifstream file;
    file.open(filename);
    if (!file) {
        cout << "Feil ved åpning av innfil." << endl;
        exit(EXIT_FAILURE);
    }
    int i = 0;
    while (i < length && file >> temperatures[i]) {
        i++;
    }

    if (i < length) {
        cout << "Filen inneholder for få temperaturer." << endl;
        file.close();
        exit(EXIT_FAILURE);
    }

    while (i < length && file >> temperatures[i]) {
        i++;
    }
    file.close();
}
