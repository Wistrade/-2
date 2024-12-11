#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

using namespace std;

class Complex
{
    double re, im;

public:
    Complex();
    Complex(const int&);
    Complex operator^ (int exponent);
    friend ostream& operator<< (ostream&, Complex);
    friend istream& operator>> (istream&, Complex&);
    Complex operator* (Complex);
    Complex operator+ (Complex);
    bool operator!= (Complex);
    Complex operator/ (Complex);
    Complex operator- ();
    Complex operator- (Complex);
};

#endif // COMPLEX_H