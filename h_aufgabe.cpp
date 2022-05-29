#include <memory>
#include <iostream>

enum Marken {
    VW, Porsche
};

struct Reifen
{
    int breite;
    int hoehe;
    int zoll;

    Reifen(int breite, int hoehe, int zoll): breite{breite}, hoehe{hoehe}, zoll{zoll} {}
    Reifen(const Reifen& reifen1): hoehe{reifen1.hoehe}, breite{reifen1.breite}, zoll{reifen1.zoll} {}
};

struct Car
{
    Marken marke;
    std::string model;
    int ps;
    long fin; // Fahrzeug-Identifikationsnummer
    Reifen reifen;

    Car(Marken marke, std::string model, int ps, long fin, Reifen reifen) :
            marke{marke}, model{model}, ps{ps}, fin{fin}, reifen{reifen} {}
};

int reichweite_berechnen(Car car) {
    return 700 - car.ps / 2;    // irgendeine Berechnung
}

int main()
{
    Reifen reifen_a = *new Reifen(255, 35, 20);
    Reifen reifen_b = *new Reifen(205, 45, 17);

    Car vw_golf = *new Car(Marken::VW, "Golf", 130, 15574685135248658, reifen_b);
    Car vw_polo = *new Car(Marken::VW, "Polo", 110, 54896123845972584, reifen_b);
    Car porsche_911 = *new Car(Marken::Porsche, "911", 640, 45861587596328452, reifen_a);

    std::cout << "VW Golf Reichweite: " << reichweite_berechnen(vw_golf) << " km\n";
    std::cout << "VW Golf Reichweite: " << reichweite_berechnen(vw_polo) << " km\n";
    std::cout << "Porsche 911 Reichweite: " << reichweite_berechnen(porsche_911) << " km\n";
}
