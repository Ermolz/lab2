#ifndef TCOMPLEX_H
#define TCOMPLEX_H

#include <iostream>
using namespace std;
class AComplex;
class TComplex {
public:
    double r, theta;
    TComplex(double radius = 0, double angle = 0);
    AComplex toAComplex() const;
    TComplex& operator*=(const TComplex& other);
    TComplex& operator/=(const TComplex& other);
    TComplex& operator+=(const TComplex& other);
    TComplex& operator-=(const TComplex& other);
};

TComplex operator+(const TComplex& a, const TComplex& b);
TComplex operator-(const TComplex& a, const TComplex& b);
TComplex operator*(const TComplex& a, const TComplex& b);
TComplex operator/(const TComplex& a, const TComplex& b);
ostream& operator<<(ostream& os, const TComplex& t);

#endif // TCOMPLEX_H
