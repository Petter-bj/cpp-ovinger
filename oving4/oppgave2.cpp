#include <gtkmm.h>

class Window : public Gtk::Window {
public:
  Gtk::Box box;
  Gtk::Label first_name_label;
  Gtk::Entry first_name_entry;
  Gtk::Label last_name_label;
  Gtk::Entry last_name_entry;
  Gtk::Button button;
  Gtk::Label label;


  Window() : box(Gtk::Orientation::ORIENTATION_VERTICAL) {
    set_title("Øving 4"); // setter tittel til vinduet
    first_name_label.set_text("First name");
    last_name_label.set_text("Last name"); // definerer label tekst

    box.pack_start(first_name_label);
    box.pack_start(first_name_entry);

    box.pack_start(last_name_label);
    box.pack_start(last_name_entry);

    button.set_label("Combine names");

    box.pack_start(button); // Add the widget button to box
    box.pack_start(label);  // Add the widget label to box


    add(box);   // Add vbox to window
    show_all(); // Show all widgets

    button.set_sensitive(false); //setter knappen til at den ikke kan trykeks ved oppstart

    auto update_button = [this]() {   //auto oppdaterer knappen som sjekker om det er tekst eller ikke i feltene
      button.set_sensitive(
        !first_name_entry.get_text().empty() &&
        !last_name_entry.get_text().empty()
        );
    };

    first_name_entry.signal_changed().connect(update_button);
    last_name_entry.signal_changed().connect(update_button);


    button.signal_clicked().connect([this]() {
      label.set_text(
        "Names combined: " + first_name_entry.get_text()
        + " " + last_name_entry.get_text()
        );
    });
  }
};

int main() {
  auto app = Gtk::Application::create();
  Window window;
  return app->run(window);
}