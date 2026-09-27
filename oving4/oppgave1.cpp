#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<double> numbers{1,2,3,4,5}; //opretter vektor

  for (double number : numbers) { // skriv ut tallene i vektoren
    std::cout << number << ' ';
  }
  std::cout << '\n';

  std::cout << "front() = " << numbers.front() << " back() = "
  << numbers.back() << '\n';

  numbers.emplace(numbers.begin() + 1, 5); // setter inn 5 etter første tall i vektoren
  std::cout << "front() = " << numbers.front() << '\n';

  auto it = std::find(numbers.begin(), numbers.end(), 5);

  if (it != numbers.end()) { // sjekker om returverdien er lik end() visst den ikke er det har den funnet noe og vi printer det.
    std::cout << "Fant tallet: " << *it << '\n';
  } else {
    std::cout << "Tallet finnes ikke\n";
  }
}