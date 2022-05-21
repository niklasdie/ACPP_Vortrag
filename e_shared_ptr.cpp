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
        auto sp = std::make_shared<Rectangle>();

        std::cout << sp.get() /* gibt den Pointer */ << std::endl;
        // 0x55938ee9aeb0

        sp->length = 7;
        sp->breadth = 12;
        std::cout << sp.operator*() /* dereferenzieren */ << std::endl;
        // Rectangle: {length: 7, breadth: 12}
        {
            auto s = swap(sp);
            // shared_ptr haben kein Ownership, deshalb kann ich diesen einfach so übergeben

            std::cout << s.operator*() << std::endl;
            // Rectangle: {length: 12, breadth: 7}

            std::cout << s.get() << std::endl;
            // 0x55938ee9aeb0

            std::cout << "Reference Count: " << sp.use_count() << std::endl;
            // Reference Count: 2
        }

        std::cout << "Reference Count: " << sp.use_count() << std::endl;
        // Reference Count: 1
    }

    // std::cout << "Reference Count: " << p.use_count() << std::endl;
    // Alle Referenzen von p sind out of scope, daher wird p von shared_ptr gelöscht.
}

















