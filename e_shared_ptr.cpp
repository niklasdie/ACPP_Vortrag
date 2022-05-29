#include <memory>
#include <iostream>

struct Rectangle
{
    int length;
    int breadth;
};

std::ostream &operator<<(std::ostream &os, const Rectangle &rec)
{
    os << "Rectangle: {length: " << rec.length << ", breadth: " << rec.breadth << "}";
    return os;
}

std::shared_ptr<Rectangle> swap(std::shared_ptr<Rectangle> rec)
{
    int tmp = rec->breadth;
    rec->breadth = rec->length;
    rec->length = tmp;
    return rec;
}

int main()
{
    {
        auto outer_sp = std::make_shared<Rectangle>();

        std::cout << outer_sp.get() /* gibt den Pointer */ << std::endl;
        // 0x55938ee9aeb0

        outer_sp->length = 7;
        outer_sp->breadth = 12;
        std::cout << outer_sp.operator*() /* dereferenzieren */ << std::endl;
        // Rectangle: {length: 7, breadth: 12}
        {
            auto inner_sp = swap(outer_sp);
            // shared_ptr haben kein Ownership, deshalb kann ich diesen einfach so übergeben.
            // Sie haben einen Reference Count (RefCount/UseCount) der bei jeder "Kopie" erhöht wird.
            /*
                   +--------------+              +--------------+
                   | shared_ptr 1 |              | shared_ptr 2 |
                   +--------------+              +--------------+      Hier müssen beide shared_ptr out of scope
                                  \              /                     laufen, damit der RefCount auf 0 fällt,
                                   \            /                      erst dann wird das Objekt gelöscht und
                                   \/          \/                      dein Speicher freigegeben. Also gibt es bei
                                   +------------+                      einem shared_ptr keinen Besitzer (Ownership).
                                   |   Object   |
                                   +------------+
            */

            std::cout << inner_sp.operator*() << std::endl;
            // Rectangle: {length: 12, breadth: 7}

            std::cout << inner_sp.get() << std::endl;
            // 0x55938ee9aeb0

            std::cout << "Reference Count: " << outer_sp.use_count() << std::endl;
            // Reference Count: 2
        }

        std::cout << "Reference Count: " << outer_sp.use_count() << std::endl;
        // Reference Count: 1
    }

    // std::cout << "Reference Count: " << outer_sp.use_count() << std::endl;
    // Alle Referenzen von outer_sp sind out of scope (RefCount = 0), daher wird outer_sp gelöscht.
}

// shared_ptr haben sehr wenig Overhead, nie Nutzung ist trotzdem zu empfehlen.
// Aufpassen muss man allerdings, wenn man mit mehreren Threads arbeitet (Thread Safe).
