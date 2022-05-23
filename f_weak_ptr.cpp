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
            // weak_ptr erhöhen den RefCount von einem shared_ptr nicht.
            /*
                    +------------+              +----------+
                    | shared_ptr |              | weak_ptr |        Ein weak_ptr nicht also nicht geeignet
                    +------------+              +----------+        ihn als shared_ptr Alternative zu nutzen,
                                 \              .                   so kann schnell wieder ein Dangling Pointer
                                  \            .                    entstehen. Allerdings kann man ihn sehr gut als
                                  \/          V                     Observer nutzen, um zu kontrollieren, ob das
                                  +------------+                    Objekt eines shared_ptr noch existiert.
                                  |   Object   |
                                  +------------+
            */

            std::cout << *wp.lock() << std::endl;
            // Rectangle: {length: 12, breadth: 7}
            // Mit weak_ptr.lock() kann man einen shared_ptr erhalten, mit dem man dann wieder gut arbeiten kann,
            // dieser erhöht dann den RefCount.
            // auto sp2 = wp.lock();

            std::cout << wp.lock() << std::endl;
            // 0x55938ee9aeb0


            std::cout << "Reference Count: " << sp.use_count() << std::endl;
            // Reference Count: 1

            sp.reset();
            // Reference reset -> RefCount auf 0

            std::cout << "Reference Count: " << sp.use_count() << std::endl;
            // Reference Count: 0

            if (wp.expired())
            {
                std::cout << "sp is not expired";
            } else {
                std::cout << "sp is expired";
            }
            // weak_ptr bleibt bestehen, da er den Reference Count von dem shared_ptr nicht erhöht.
        }
    }
}
















