#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Material {
public:
  virtual ~Material() = default;   // virtuell destruktør

  string name;
  double price; // per unit

  Material(const string &name_, double price_) : name(name_), price(price_) {}

  virtual void print() const {  // virtual for polymorfi
    cout << "Navn: " << name << endl
         << "Pris: " << price << endl;
  };
};

class Covering : public Material {
public:
  double width; // i meter

  // Prisen er per meter belegg (i lengden)
  Covering(const string &name, double price, double width_)
      : Material(name, price), width(width_) {}

  void print() const override { // override
    Material::print();
    cout << "For belegg" << endl
         << "Bredde: " << width << endl;
  }
};

class Wallpaper : public Material {
public:
  double length; // i meter per rull
  double width;  // i meter per rull

  // Prisen er per rull
  Wallpaper(const string &name, double price, double length_, double width_)
      : Material(name, price), length(length_), width(width_) {}

  void print() const override {
    Material::print();
    cout << "For tapet" << endl
         << "Bredde av rull: " << width << endl
         << "Lengde av rull: " << length << endl;
  }
};

class Paint : public Material {
public:
  int coatings;         // Antall strøk
  double liters_per_m2; // Liter per kvadratmeter

  // Prisen er per liter
  Paint(const string &name, double price, int coatings_, double liters_per_m2_)
      : Material(name, price), coatings(coatings_), liters_per_m2(liters_per_m2_) {}

  void print() const override {
    Material::print();
    cout << "For maling" << endl
         << "Antall strøk: " << coatings << endl
         << "Liter per kvadratmeter: " << liters_per_m2 << endl;
  }
};

int main() {
  Covering covering("Super Duper Dux", 433.50, 4);
  Wallpaper wallpaper("Soldogg", 200, 12, 0.6);
  Paint paint("Extra", 125, 2, 12);

  // unique_ptr + polymorfi: riktig print() velges per objekttype
  vector<unique_ptr<Material>> materials;
  materials.push_back(make_unique<Covering>("Super Duper Dux", 433.50, 4));
  materials.push_back(make_unique<Wallpaper>("Soldogg", 200, 12, 0.6));
  materials.push_back(make_unique<Paint>("Extra", 125, 2, 12));

  for (auto &material : materials) {
    material->print();
    cout << endl;
  }
}
