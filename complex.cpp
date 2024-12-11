#include <iostream>
#include <complex>
#include <cmath>
#include "complex.h"
#include "number.h"

Complex::Complex() : re(0), im(0)
{
    
}

Complex::Complex(const int& r)
{
    re = r;
    im = 0;
}

Complex Complex::operator^(int exponent)
{
    if (exponent == 2) {
        Complex result;
        result.re = re * re - im * im;
        result.im = 2 * re * im;
        return result;
    }
}

bool Complex::operator!=(Complex c)
{
    if ((re == c.re) && (im == c.im)) return false;
    else return true;
}

Complex Complex::operator/(Complex c)
{
    Complex t;
    t.re = (re * c.re + im * c.im) / (c.re * c.re + c.im * c.im);
    t.im = (im * c.re - re * c.im) / (c.re * c.re + c.im * c.im);
    return t;
}

Complex Complex::operator-()
{
    Complex t;
    t.re = -1 * re;
    t.im = -1 * im;
    return t;
}

Complex Complex::operator- (Complex c)
{
    Complex t;
    t.re = re - c.re;
    t.im = im - c.im;
    return t;
}

Complex Complex::operator*(Complex c)
{
    Complex t;
    t.re = re * c.re - im * c.im;
    t.im = re * c.im + im * c.re;
    return t;
}

Complex Complex::operator+(Complex c)
{
    Complex t;
    t.re = re + c.re;
    t.im = c.im + im;
    return t;
}

ostream& operator<< (ostream& os, Complex c)
{
    os << "(" << c.re << "+" << c.im << "i)";
    return os;
}

istream& operator>> (istream& is, Complex& c)
{
    is >> c.re >> c.im;
    return is;
}