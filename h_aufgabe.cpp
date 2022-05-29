#include <memory>
#include <iostream>

enum Automarke {
    VW, Porsche
};

struct Reifen
{
    int breite;
    int hoehe;
    int zoll;

    Reifen(int breite, int hoehe, int zoll): breite{breite}, hoehe{hoehe}, zoll{zoll} { }
    Reifen(const Reifen& reifen1): hoehe{reifen1.hoehe}, breite{reifen1.breite}, zoll{reifen1.zoll} { }
};

struct Car
{
    Automarke marke;
    std::string model; // TODO
    int ps;
    long fin; // Fahrzeug-Identifikationsnummer // TODO
    Reifen reifen; // TODO
    std::string besitzer; // TODO

    Car(Automarke marke, std::string model, int ps, long fin, Reifen reifen) :
            marke{marke}, model{model}, ps{ps}, fin{fin}, reifen{reifen} { } // TODO

    void set_besitzer(std::string besitzer) { // TODO
        this->besitzer = besitzer;
    }

    [[nodiscard]] std::string get_besitzer() const { // TODO
        return besitzer;
    }
};

int reichweite_berechnen(const Car& car) { // TODO
    return 700 - car.ps / 2;    // irgendeine Berechnung
}

Car reifen_wechseln(Car car, Reifen reifen) { // TODO
    car.reifen = reifen;
    return std::move(car);
}

int main()
{
    // shared_ptr
    Reifen reifen_a = *new Reifen(255, 35, 20); // TODO
    Reifen reifen_b = *new Reifen(205, 45, 17); // TODO

    // unique_ptr
    Car vw_golf =
            *new Car(Automarke::VW, "Golf", 130, 15574685135248658, reifen_b); // TODO
    Car vw_polo =
            *new Car(Automarke::VW, "Polo", 110, 54896123845972584, reifen_b); // TODO
    Car porsche_911 =
            *new Car(Automarke::Porsche, "911", 640, 45861587596328452, reifen_a); // TODO

    std::cout << "VW Golf Reichweite: " << reichweite_berechnen(vw_golf) << " km\n"; // TODO
    std::cout << "VW Golf Reichweite: " << reichweite_berechnen(vw_polo) << " km\n"; // TODO
    std::cout << "Porsche 911 Reichweite: " << reichweite_berechnen(porsche_911) << " km\n\n"; // TODO

    vw_golf = reifen_wechseln(vw_golf, reifen_a); // TODO
    porsche_911 = reifen_wechseln(porsche_911, reifen_b); // TODO

    std::cout << "VW Golf Reifen: " << vw_golf.reifen.breite << " / " << vw_golf.reifen.hoehe // TODO
              << " " << vw_golf.reifen.zoll << "\n"; // TODO
    std::cout << "Porsche 911 Reifen: " << porsche_911.reifen.breite << " / " << porsche_911.reifen.hoehe // TODO
              << " " << porsche_911.reifen.zoll << "\n"; // TODO
}
