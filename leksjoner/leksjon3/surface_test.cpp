#include <iostream>
#include <string>

using namespace std;

class Surface {
public:
  Surface(const string &name_, double length_, double width_);
  const string &get_name() const;
  double get_length() const;
  double get_width() const;
  double get_area() const;
  double get_circumference() const;

private:
  string name;
  double length;
  double width;
};

Surface::Surface(const string &name_, double length_, double width_)
  : name(name_), length(length_), width(width_){}

const string &Surface::get_name() const {
  return name;
}

double Surface::get_length() const {
  return length;
}

double Surface::get_width() const {
  return width;
}

double Surface::get_area() const {
  return width * length;
}

double Surface::get_circumference() const {
  return 2 * (length + width);
}

int main() {
  Surface floor("Torils golv", 4.8, 2.3);

  string name = floor.get_name();
  double width = floor.get_width();
  double length = floor.get_length();
  double area = floor.get_area();
  double circumference = floor.get_circumference();

  // Trinn 3: Skriver ut resultatene slik at de kan kontrolleres
  cout << "Data om golvet med navn: " << name << ":" << endl;
  cout << "Bredde: " << width << endl;
  cout << "Lengde: " << length << endl;
  cout << "Areal: " << area << endl;
  cout << "Omkrets: " << circumference << endl;
}
