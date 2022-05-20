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

std::unique_ptr<Rectangle> swap(std::unique_ptr<Rectangle> rec)
{
    int tmp = rec->breadth;
    rec->breadth = rec->length;
    rec->length = tmp;
    return rec;
}

int main()
{
    {
        auto up = std::make_unique<Rectangle>();

        std::cout << up.get() /* gibt den Pointer */ << std::endl;
        // 0x55938ee9aeb0

        up->length = 7;
        up->breadth = 12;
        std::cout << up.operator*() /* dereferenzieren */ << std::endl;
        // Rectangle: {length: 7, breadth: 12}

        up = swap(std::move(up));
        // unique_ptr müssen zusammen mit ihrem Ownership übergeben (gemoved) werden.

        std::cout << up.operator*() << std::endl;
        // Rectangle: {length: 12, breadth: 7}

        std::cout << up.get();
        // 0x55938ee9aeb0
        // kann sonst wie ein normaler Pointer benutzt werden
    }

    // std::cout << p.get();
    // Scope von p ist zu ende, deshalb ist p von unique_ptr gelöscht worden.
}