#include <memory>
#include <iostream>

struct Rectangle
{
    int length;
    int breadth;
};

std::ostream& operator<<(std::ostream& os, const Rectangle& rec)
{
    os << "Rectangle: {length: " << rec.length << ", breadth: " << rec.breadth << "}";
    return os;
}

std::unique_ptr<Rectangle> swap(std::unique_ptr<Rectangle> rec)
{
    int tmp = rec->breadth;
    rec->breadth = rec->length;
    rec->length = tmp;
    return std::move(rec);
    // Wichtig: Den unique_ptr zusammen mit seinem Ownership zurückzugeben.
}

int main()
{
    {
        auto up = std::make_unique<Rectangle>();
        // Stack allokierter Wrapper eines Pointers, welcher die Verantwortung über den Raw Pointer übernimmt.
        // Der Ersteller des unique_ptr ist auch der Besitzer (Ownership).

        std::cout << up.get() /* gibt den Pointer */ << std::endl;
        // 0x55938ee9aeb0

        up->length = 7;
        up->breadth = 12;
        std::cout << up.operator*() /* dereferenzieren */ << std::endl;
        // Rectangle: {length: 7, breadth: 12}

        up = swap(std::move(up));
        // unique_ptr müssen zusammen mit ihrem Ownership übergeben (gemoved) werden.
        // Sie können also nicht kopiert werden.
        /*
               +--------------+              +--------------+
               | unique_ptr 1 |              | unique_ptr 2 |
               +--------------+              +--------------+      Wenn z.B. unique_ptr 2 out of scope läuft,
                              \              /                     löscht er das Objekt und gibt diesen Speicher
                               \            /                      frei. unique_ptr 1 zeigt jetzt auf einen Speicher
                               \/          \/                      der freigegeben wurde (dangling pointer).
                               +------------+
                               |   Object   |
                               +------------+
         */

        std::cout << up.operator*() << std::endl;
        // Rectangle: {length: 12, breadth: 7}

        std::cout << up.get();
        // 0x55938ee9aeb0
        // kann sonst wie ein normaler Pointer benutzt werden
    }

    // std::cout << p.get();
    // Scope von p ist zu ende, deshalb ist p von unique_ptr gelöscht worden.
}

// unique_ptr haben keinen Overhead, deshalb ist die Nutzung zu empfehlen.
