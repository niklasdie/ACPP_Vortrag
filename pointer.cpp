#include <iostream>

struct Rectangle {
    int length;
    int breadth;
};

int main()
{
    auto* p = new Rectangle();
    // Pointer ist einfach gesagt eine Zahl die auf eine bestimmte Speicherstelle verweist.

    std::cout << p << std::endl;
    // 0x55d33554aeb0 (Zahl in hex Schreibweise)

    int num = 5;
    void* v_p = &num;
    // Pointer haben keinen Typen.
    // Typen von Pointern helfen nur die Daten vom Pointer zu verstehen.

    std::cout << v_p;
    // 0x7fffc2324194

    // std::cout << *v_p;
    // geht nicht, da keine Typinformation vom Pointer vorliegt

    delete p;
}
