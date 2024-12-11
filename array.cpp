#include "array.h"
#include <cmath>
#include <iostream>
#include <algorithm>
#include "complex.h"
using namespace std;

Array::Array(unsigned int x)
{
    n = x;
    A = new number[n];

    for (unsigned int i = 0; i < n; i++)
        A[i] = 0;
}

void Array::update(unsigned int newSize) {
    delete[] A;
    n = newSize;
    A = new number[n];
    for (unsigned int i = 0; i < n; i++)
        A[i] = 0;
}

void Array::copy(unsigned int newN, Array& other) {
    number* temp = new number[other.n];
    unsigned int oldSize = other.n;

    for (int i = 0; i < oldSize; ++i)
        temp[i] = other.A[i];

    update(newN);

    for (int i = 0; i < oldSize; ++i)
        A[i] = temp[i];

    delete[] temp;
}

Array::~Array()
{
    delete[] A;
    A = nullptr;

}

void Array::set(unsigned int i, number val)
{
    if (n > 0 && i < n)
    {
        A[i] = val;
    }
}

number Array::sko() const
{
    number d = 0;
    for (unsigned int i = 0; i < n; i++)
        d = d + A[i];
    d = d / n;
    number res = 0;
    for (unsigned int i = 0; i < n; ++i) {
        res = res + ((A[i] - d) ^ 2);
    }
    res = res / (n - 1);
    number skoRes = res ^ 0.5;
    return skoRes;
}

number Array::middle() const
{
    number d = 0;
    for (unsigned int i = 0; i < n; i++)
        d = d + A[i];
    d = d / n;
    return d;
}

void Array::sortIncreas() const
{
    sort(A, A + n);
}

void Array::sortDecreas() const
{
    sort(A, A + n, greater<Complex>());
}

void Array::changeElement(unsigned int i, number x)
{
    if (i - 1 > n)
        cout << endl << "Элемента с указанный номеров не существует." << endl;
    else
        A[i - 1] = x;
}

ostream& operator<<(ostream& os, Array& other) {
    os << "Размер массива: " << other.n << "\n";
    for (unsigned int i = 0; i < other.n; ++i) {
        os << other.A[i] << " ";
    }
    os << endl;
    return os;
}