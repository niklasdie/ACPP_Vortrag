#include <iostream>

template<class T>
class shared_ptr
{
    unsigned int* counter; // Reference Counter
    T* ptr; // Raw Pointer

public:
    // Konstruktor
    explicit shared_ptr(T *p = NULL)
    {
        ptr = p;
        *counter = 0;
        if (ptr)
        {
            (*counter)++;
        }
    }

    // Copy Konstruktor
    shared_ptr(shared_ptr<T>& sp)
    {
        ptr = sp.ptr;
        counter = sp.counter;
        (*counter)++;
    }

    // Destruktor
    ~shared_ptr()
    {
        (*counter)--;
        if (*counter == 0)
        {
            delete counter;
            delete ptr;
        }
    }

    // Überladung des Dereferenzierungsoperator
    T &operator*() { return *ptr; }

    // Überladung Pfeiloperator,
    // so kann man auf die Attribute
    // von ptr zugreifen.
    T *operator->() { return ptr; }
};