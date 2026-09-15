#include <iostream>

using namespace std;

const double pi = 3.141592;

class Circle {
public:
  Circle(double radius_); //legg inn stor C
  double get_area() const;
  double get_circumference() const;
private:
  double radius;
};   //la til ; etter }


// ==> Implementasjon av klassen Circle

Circle::Circle(double radius_) : radius(radius_) {} //var før radius_(radius)

double Circle::get_area() const { //endret til double fra int og endret til const for ingen data endres
  return pi * radius * radius;
}

double Circle::get_circumference() const {
  return 2.0 * pi * radius; //ingen variabel som heter circumfrence så bare returnerer verdien direkte
}


int main() {
  Circle circle(5);

  double area = circle.get_area();
  cout << "Arealet er lik " << area << endl;

  double circumference = circle.get_circumference();
  cout << "Omkretsen er lik " << circumference << endl;
}