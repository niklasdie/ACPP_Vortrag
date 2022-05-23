#include <memory>
#include <iostream>

struct X { };

void b01()
{
    std::unique_ptr<X> up1 { new X };            // unique_ptr Ownership, nicht empfohlen
    std::shared_ptr<X> sp1 { new X };            // shared_ptr Ownership, nicht empfohlen
    auto up2 = std::make_unique<X>();  // unique_ptr Ownership, empfohlen zur ausdrücklichen Verwendung "new"
    auto sp2 = std::make_shared<X>();  // shared_ptr Ownership, empfohlen zur ausdrücklichen Verwendung "new"
}

void b02_bad()
{
    auto sp = std::make_shared<X>();
    // nur locale Nutzung, der Refcount wird nie höher als 1
    // besser unique_ptr verwenden
}

void b02()
{
    auto up = std::make_unique<X>();
    // nur locale Nutzung
}


// b03
// Akzeptiert nur ints, für die man das Ownership übertragen möchten
void g(std::unique_ptr<int>);

// Akzeptiert nur ints, für die Sie bereit sind, das Ownership zu teilen
void g(std::shared_ptr<int>);

// Ändert das Ownership nicht, erfordert aber einen bestimmten Besitz des Aufrufers
void h(const std::unique_ptr<int>&);


// b04
void sink(std::unique_ptr<X>);          // bekommt Ownership über X
// Bei unique_ptr möchte man in der Regel das Ownership mitgeben.

void uses(X*);                          // nutzt einfach nur X


// b05
void reseat(std::unique_ptr<X>&);       // "wird" oder "könnte" Pointer einem anderen Objekt zuweisen
void reseat(std::shared_ptr<X>&);       // "

// bad
void thinko(const std::unique_ptr<X>&); // sollte man nicht benutzen


// b06
class X_user
{
public:
    explicit X_user(std::shared_ptr<X> x) noexcept:
            my_x {std::move(x)} { }
    // X_user teilt das Ownership über x
private:
    std::shared_ptr<X> my_x;
};


// b07
void share(std::shared_ptr<X>);             // "wird" Refcount beibehalten

void reseat2(std::shared_ptr<X>&);          // "könnte" Pointer einem anderen Objekt zuweisen

void may_share(const std::shared_ptr<X>&);  // "könnte" Refcount beibehalten


















