#include <iostream>

template<class T>
class unique_ptr
{
    T* ptr; // Raw Pointer

public:
    // Konstruktor
    explicit unique_ptr(T *p = NULL) { ptr = p; }

    // Destruktor
    ~unique_ptr() { delete (ptr); }

    // Überladung des Dereferenzierungsoperator
    T &operator*() { return *ptr; }

    // Überladung Pfeiloperator,
    // so kann man auf die Attribute
    // von ptr zugreifen.
    T *operator->() { return ptr; }
};