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
    std::unique_ptr<long> fin; // Fahrzeug-Identifikationsnummer
    std::shared_ptr<Reifen> reifen;

    Car(Marken marke, std::string model, int ps, long fin, std::shared_ptr<Reifen> reifen) :
            marke{marke}, model{model}, ps{ps}, fin{std::make_unique<long>(fin)}, reifen{reifen} {}
};

int reichweite_berechnen(int ps) {
    return 700 - ps / 2;   // irgendeine Berechnung
}

std::unique_ptr<Car> reifen_wechseln(std::unique_ptr<Car> car, std::shared_ptr<Reifen> reifen) {
    car->reifen = reifen;
    return std::move(car);
}

int main()
{
    auto reifen_a = std::make_shared<Reifen>(255, 35, 20);
    auto reifen_b = std::make_shared<Reifen>(205, 45, 17);

    auto vw_golf =
            std::make_unique<Car>(Marken::VW, "Golf", 130, 15574685135248658, reifen_b);
    auto vw_polo =
            std::make_unique<Car>(Marken::VW, "Polo", 110, 54896123845972584, reifen_b);
    auto porsche_911 =
            std::make_unique<Car>(Marken::Porsche, "911", 640, 45861587596328452, reifen_a);

    std::cout << "VW Golf Reichweite: " << reichweite_berechnen(vw_golf->ps) << " km\n";
    std::cout << "VW Golf Reichweite: " << reichweite_berechnen(vw_polo->ps) << " km\n";
    std::cout << "Porsche 911 Reichweite: " << reichweite_berechnen(porsche_911->ps) << " km\n";

    vw_golf = reifen_wechseln(std::move(vw_golf), reifen_a);
    porsche_911 = reifen_wechseln(std::move(porsche_911), reifen_b);

    std::cout << "VW Golf Reifen: " << vw_golf->reifen->breite << " / " << vw_golf->reifen->hoehe
        << " " << vw_golf->reifen->zoll << "\n";
    std::cout << "Porsche 911 Reifen: " << porsche_911->reifen->breite << " / " << porsche_911->reifen->hoehe
              << " " << porsche_911->reifen->zoll << "\n";

}
