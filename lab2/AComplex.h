#ifndef ACOMPLEX_H
#define ACOMPLEX_H

#include <iostream>
using namespace std;
class TComplex;
class AComplex {
public:
    double re, im;
    AComplex(double r = 0, double i = 0);
    TComplex toTComplex() const;
    AComplex& operator+=(const AComplex& other);
    AComplex& operator-=(const AComplex& other);
    AComplex& operator*=(const AComplex& other);
    AComplex& operator/=(const AComplex& other);
};

AComplex operator+(const AComplex& a, const AComplex& b);
AComplex operator-(const AComplex& a, const AComplex& b);
AComplex operator*(const AComplex& a, const AComplex& b);
AComplex operator/(const AComplex& a, const AComplex& b);
ostream& operator<<(ostream& os, const AComplex& a);

#endif // ACOMPLEX_H
