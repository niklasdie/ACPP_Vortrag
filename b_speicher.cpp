struct Rectangle {
    int length;
    int breadth;
};

int main()
{
    auto* p = new Rectangle();
    // new allokiert neuen Speicher im Heap für das gegebene Objekt
    // erst danach wird der Konstruktor aufgerufen und dem Speicher zugewiesen

    // ...

    delete p;
    // vernichtet das Objekt und gibt den Speicher des Objekts auf dem Heap frei
}

// Nebenbei: new und delete sind Operatoren wie +, - oder =
