#include <vector>
#pragma once

class Heltallstabell {
public:
  std::vector<int> tabell;

  Heltallstabell(const Heltallstabell &) = default;

  Heltallstabell();
  Heltallstabell operator+(const Heltallstabell &other) const;
  Heltallstabell &operator+=(int tall);
  Heltallstabell &operator=(const Heltallstabell &other);


};


std::ostream &operator<<(std::ostream &out, const Heltallstabell &heltallstabell);

