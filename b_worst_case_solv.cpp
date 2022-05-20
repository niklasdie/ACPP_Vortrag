#include <memory>       // Hier liegen die Smart Pointer.

struct Rectangle {
    int length;
    int breadth;
};

void fun()
{
    auto p = std::unique_ptr<Rectangle>(new Rectangle());
    auto p2 = std::make_unique<Rectangle>(); // bevorzugte Art
    // p wird hier automatisch vernichtet und jetzt wird auch der Speicher im Heap freigegeben.
}

int main()
{
    // Infinite Loop, welcher immer wieder neuen Speicher allokiert, aber auch wieder freigibt,
    // so kann der Speicher nicht voll laufen.
    while (1) {
        fun();
    }
}