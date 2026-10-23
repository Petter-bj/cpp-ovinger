

//  Hvilke forutsetninger gjør du?
//  Jeg forutser at typene støtter += i tilegg til + og >

#include <iostream>
template <typename Type1, typename Type2>
class Pair {
public:
  Type1 first;
  Type2 second;

  Pair(Type1 first, Type2 second): first(first), second(second) {}

  Pair operator+(const Pair &other) {
    Pair pair = *this;
    pair.first += other.first;
    pair.second += other.second;
    return pair;
  }

  bool operator>(const Pair &other) {
    Pair pair = *this;
    auto sumP1 = pair.first + pair.second;
    auto sumP2 = other.first + other.second;
    if (sumP1 > sumP2) {
      return true;
    }
    return false;
  }
};


int main() {
  Pair<double, int> p1(3.5, 14);
  Pair<double, int> p2(2.1, 7);
  std::cout << "p1: " << p1.first << ", " << p1.second << std::endl;
  std::cout << "p2: " << p2.first << ", " << p2.second << std::endl;

  if (p1 > p2)
    std::cout << "p1 er størst" << std::endl;
  else
    std::cout << "p2 er størst" << std::endl;

  auto sum = p1 + p2;
  std::cout << "Sum: " << sum.first << ", " << sum.second << std::endl;
}

