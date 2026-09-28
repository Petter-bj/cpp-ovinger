#include <iostream>

using namespace std;

int main() {
    // 1. Lager en vanlig variabel
    int number = 42;

    cout << "=== Steg 1: Vanlig variabel ===" << endl;
    cout << "Verdien til number: " << number << endl;
    cout << "Adressen til number: " << &number << endl;  // & = "adressen til"
    cout << endl;

    // 2. Lager en pointer som peker på number
    int *pointer = &number;  // pointer lagrer ADRESSEN til number

    cout << "=== Steg 2: Pointer peker på number ===" << endl;
    cout << "Verdien til pointer (adressen den lagrer): " << pointer << endl;
    cout << "Adressen til pointer selv: " << &pointer << endl;
    cout << "Verdien pointer peker på (*pointer): " << *pointer << endl;  // * = "gå til adressen"
    cout << endl;

    // 3. Endrer verdien via pointeren
    *pointer = 6;  // Gå til adressen pointer peker på, og legg inn 6

    cout << "=== Steg 3: Endret via pointer ===" << endl;
    cout << "Verdien til number ETTER *pointer = 6: " << number << endl;
    cout << "Verdien via *pointer: " << *pointer << endl;
    cout << endl;

    // 4. Endrer number direkte
    number = 99;

    cout << "=== Steg 4: Endret number direkte ===" << endl;
    cout << "number: " << number << endl;
    cout << "*pointer: " << *pointer << endl;
    cout << "(Samme verdi fordi begge refererer til samme minnecelle!)" << endl;
    cout << endl;

    // 5. Nullpointer (peker ingenting sted)
    int *nullPointer = nullptr;
    cout << "=== Steg 5: Nullpointer ===" << endl;
    cout << "nullPointer peker på: " << nullPointer << endl;
    // cout << *nullPointer;  // KJØRER DETTE = CRASH!
    cout << "(Dereferering av nullpointer kræsjer programmet)" << endl;

    return 0;
}
