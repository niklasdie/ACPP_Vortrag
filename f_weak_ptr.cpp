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

        std::cout << sp /* gibt den Pointer */ << std::endl;
        // 0x55938ee9aeb0

        sp->length = 7;
        sp->breadth = 12;
        std::cout << *sp /* dereferenzieren */ << std::endl;
        // Rectangle: {length: 7, breadth: 12}
        {
            std::weak_ptr wp = swap(sp);
            // shared_ptr haben kein Ownership, deshalb kann ich diesen einfach so übergeben

            std::cout << *wp.lock() << std::endl;
            // Rectangle: {length: 12, breadth: 7}

            std::cout << wp.lock() << std::endl;
            // 0x55938ee9aeb0


            std::cout << "Reference Count: " << sp.use_count() << std::endl;
            // Reference Count: 1

            sp.reset();
            // Reference reset

            std::cout << "Reference Count: " << sp.use_count() << std::endl;
            // Reference Count: 0

            if (auto tmp = wp.lock())
            {
                std::cout << *tmp << std::endl;
            } else {
                std::cout << "wp is expired\n";
            }
            // weak_ptr bleibt bestehen, da er den Reference Count von dem shared_ptr nicht erhöht.
        }
    }
}
















