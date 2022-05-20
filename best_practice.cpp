#include <memory>
#include <iostream>

struct X {
    int x;
    X() = default;
    X(int i): x{i} {}
};
struct Base {};
struct Derived {};

void b1()
{
    X x;
    X* p1 { new X };                                   // see also ???
    std::unique_ptr<X> p2 { new X };                // unique ownership; see also ???
    std::shared_ptr<X> p3 { new X };                // shared ownership; see also ???
    auto p4 = std::make_unique<X>();     // unique_ownership, preferable to the explicit use "new"
    auto p5 = std::make_shared<X>();     // shared ownership, preferable to the explicit use "new"
}

void b2_bad()
{
    auto base = std::make_shared<X>();
    // use base locally, without copying it -- refcount never exceeds 1
} // destroy base

void b2()
{
    auto base = std::make_unique<X>();
    // use base locally
} // destroy base

void b3()
{
    std::shared_ptr<X> p1 { new X{2} }; // bad
    auto p = std::make_shared<X>(2);    // good
}