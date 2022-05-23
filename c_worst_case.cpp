struct Rectangle {
    int length;
    int breadth;
};

void fun()
{
    auto* p = new Rectangle();
    // p wird hier vernichtet, allerdings wird sein Speicher im Heap nicht freigegeben (memory leak).
}

int main()
{
    // Infinite Loop, welcher immer wieder neuen Speicher im Heap allokiert, aber nicht freigibt,
    // so kann der "verbrauchte" Speicher nicht erneut genutzt werden und der Speicher läuft voll.
    while (true) {
        fun();
    }
}
















