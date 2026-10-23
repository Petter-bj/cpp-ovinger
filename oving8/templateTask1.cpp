  #include <cmath>
  #include <iostream>

  template <typename Type>
  bool equal(Type a, Type b) {
    if (a != b) {
      std::cout << "Used equal method. False" << std::endl;
      return false;
    }
    std::cout << "Used equal method. True" << std::endl;
    return true;
  }

  bool equal(double a, double b) {
    if (std::fabs(a - b) >= 0.00001) {
      std::cout << "Used the double equal method. False" << std::endl;
      return false;
    }
    std::cout << "Used the double equal method. True" << std::endl;
    return true;
  }


  int main() {
    equal(3, 3);
    equal(4.444444,4.444445);
    equal(3,4);
    equal(4.33333,4.44444);
  }