

using namespace std;

const double pi = 3.141592;

class Circle {
  public:
    Circle(double radius_); //legg inn stor C
    double get_area() const; // endret fra int til double
    double get_circumference() const;
private:
  double radius;
};   //la til ; etter }


// ==> Implementasjon av klassen Circle

Circle::Circle(double radius_) : radius(radius_) {} //var før radius_(radius)

double Circle::get_area() const { //endret til double fra int og endret til const for ingen data endres
  return pi * radius * radius;
}

double Circle::get_circumference() const { // legg inn double som returtype
  return 2.0 * pi * radius; //ingen variabel som heter circumfrence så bare returnerer verdien direkte
}