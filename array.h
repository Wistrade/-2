#ifndef ARRAY_H
#define ARRAY_H
#include "number.h"
#include <iostream>
using namespace std;

class Array
{
    unsigned int n;
    number* A;

public:
    Array(unsigned int);
    ~Array();

    friend ostream& operator<< (ostream&, Array&);

    void update(unsigned int newSize);
    void copy(unsigned int newN, Array& other);
    void set(unsigned int i, number val);
    number middle() const;
    number sko() const;
    void sortIncreas() const;
    void sortDecreas() const;
    void changeElement(unsigned int i, number x);
};

#endif // ARRAY_H
