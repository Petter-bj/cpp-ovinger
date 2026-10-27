#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
std::vector<int> v2 = {2, 3, 12, 14, 24};

std::ostream &operator<<(std::ostream &out, const std::vector<int> &table) {
  for (auto &e : table)
    out << e << " ";
  return out;
}


int main() {

  auto it = std::find_if(v1.begin(), v1.end(), [](int value) {
    return value > 15;
  });

  if (it != v1.end()) {
    std::cout << "The number " << *it << " is greater than 15." << std::endl;
  } else {
    std::cout << "No numbers greater than 15 were found." << std::endl;
  }

  bool five = std::equal(
    v1.begin(), v1.begin() +5,
    v2.begin(),v2.end(),
    [](int a, int b) {
      return abs(a-b) <= 2;
    }
    );

  bool four = std::equal(
    v1.begin(), v1.begin() +4,
    v2.begin(),v2.begin() +4,
    [](int a, int b) {
      return abs(a-b) <= 2;
    }
    );

  if (five) {
    std::cout << "for v1 + 5 v2 is approximately equal" << std::endl;
  } else {
    std::cout << "for v1 + 5 v2 is not approximately equal" << std::endl;
  }

  if (four) {
    std::cout << "for v1 + 4 v2 is approximately equal" << std::endl;
  } else {
    std::cout << "for v1 + 4 v2 is not approximately equal" << std::endl;
  }

  std::vector<int> copy(v1.size());

  std::replace_copy_if(
    v1.begin(), v1.end(), copy.begin(),
    [](int value) {
        return value % 2 != 0;
    },
    100
);

  std::cout << "copy after replacing odd numbers with 100 from v1: " << copy << std::endl;
}