#include <iostream>

using namespace std;

const int length = 5;

int main() {
    double temperatur;
    int antallOver = 0;
    int antallUnder = 0;
    int antallMellom = 0;

    cout << "Du skal skrive inn 5 temperaturer.\n";

    for (int i = 0; i < length; i++) {
        cout << "Temperatur nr " << i + 1 << ": ";
        cin >> temperatur;

        if (temperatur > 20) {
            antallOver++;
        } else if (temperatur < 10) {
            antallUnder++;
        } else {
            antallMellom++;
        }
    }

    cout << "Antall under 10 er " << antallUnder << endl;
    cout << "Antall mellom 10 og 20 er " << antallMellom << endl;
    cout << "Antall over 20 er " << antallOver << endl;

    return 0;
}
