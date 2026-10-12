//
// Created by Petter Birkelund-Jensen on 12/10/2026.
//

#include "heltallstabell.hpp"
#include <algorithm>
#include <iostream>
Heltallstabell::Heltallstabell() {
}



// unionen av to tabeller
Heltallstabell Heltallstabell::operator+(const Heltallstabell &other) const {
  Heltallstabell resultat = *this;
  for (int tall : other.tabell) {
    auto it = std::find(resultat.tabell.begin(), resultat.tabell.end(), tall);
    if (it == resultat.tabell.end()) {
      resultat.tabell.emplace_back(tall);
    }
  }
  return resultat;
}

// å legge et nytt tall inn i en mengde. Dersom tallet fins fra før, skal det ikke skje noe.

Heltallstabell &Heltallstabell::operator+=(int tall) {
  auto it = std::find(tabell.begin(), tabell.end(), tall);
  if (it == tabell.end()) {
    tabell.emplace_back(tall);
  }
  return *this;
}

// å sette en mengde lik en annen mengde
Heltallstabell &Heltallstabell::operator=(const Heltallstabell &other) {
  tabell = other.tabell;
  return *this;
}

// å skrive ut en mengde
std::ostream &operator<<(std::ostream &out, const Heltallstabell &heltallstabell) {
  out << "{ ";
  bool first = true;
  for (int tall : heltallstabell.tabell) {
    if (!first) {
      out << ", ";
    }
    out << tall;
    first = false;
  }
  out << " }";
  return out;
}