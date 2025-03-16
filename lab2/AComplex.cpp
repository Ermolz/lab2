#include "AComplex.h"
#include "TComplex.h"
#include <cmath>

AComplex::AComplex(double r, double i) : re(r), im(i) {}

TComplex AComplex::toTComplex() const {
    double radius = sqrt(re * re + im * im);
    double angle = (radius == 0) ? 0 : atan2(im, re);
    return TComplex(radius, angle);
}

AComplex& AComplex::operator+=(const AComplex& other) {
    re += other.re;
    im += other.im;
    return *this;
}

AComplex& AComplex::operator-=(const AComplex& other) {
    re -= other.re;
    im -= other.im;
    return *this;
}

AComplex& AComplex::operator*=(const AComplex& other) {
    TComplex t1 = this->toTComplex();
    TComplex t2 = other.toTComplex();
    t1 *= t2;
    AComplex result = t1.toAComplex();
    re = result.re;
    im = result.im;
    return *this;
}

AComplex& AComplex::operator/=(const AComplex& other) {
    TComplex t1 = this->toTComplex();
    TComplex t2 = other.toTComplex();
    t1 /= t2;
    AComplex result = t1.toAComplex();
    re = result.re;
    im = result.im;
    return *this;
}

AComplex operator+(const AComplex& a, const AComplex& b) {
    return AComplex(a.re + b.re, a.im + b.im);
}

AComplex operator-(const AComplex& a, const AComplex& b) {
    return AComplex(a.re - b.re, a.im - b.im);
}

AComplex operator*(const AComplex& a, const AComplex& b) {
    AComplex result = a;
    result *= b;
    return result;
}

AComplex operator/(const AComplex& a, const AComplex& b) {
    AComplex result = a;
    result /= b;
    return result;
}

ostream& operator<<(ostream& os, const AComplex& a) {
    os << "(" << a.re << (a.im >= 0 ? " + " : " - ") << fabs(a.im) << "i)";
    return os;
}
