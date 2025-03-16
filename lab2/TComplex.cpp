#include "TComplex.h"
#include "AComplex.h"
#include <cmath>

TComplex::TComplex(double radius, double angle) : r(radius), theta(angle) {}

AComplex TComplex::toAComplex() const {
    return AComplex(r * cos(theta), r * sin(theta));
}

TComplex& TComplex::operator*=(const TComplex& other) {
    r *= other.r;
    theta += other.theta;
    return *this;
}

TComplex& TComplex::operator/=(const TComplex& other) {
    r /= other.r;
    theta -= other.theta;
    return *this;
}

TComplex& TComplex::operator+=(const TComplex& other) {
    AComplex a = this->toAComplex() + other.toAComplex();
    *this = a.toTComplex();
    return *this;
}

TComplex& TComplex::operator-=(const TComplex& other) {
    AComplex a = this->toAComplex() - other.toAComplex();
    *this = a.toTComplex();
    return *this;
}

TComplex operator+(const TComplex& a, const TComplex& b) {
    AComplex result = a.toAComplex() + b.toAComplex();
    return result.toTComplex();
}

TComplex operator-(const TComplex& a, const TComplex& b) {
    AComplex result = a.toAComplex() - b.toAComplex();
    return result.toTComplex();
}

TComplex operator*(const TComplex& a, const TComplex& b) {
    TComplex result = a;
    result *= b;
    return result;
}

TComplex operator/(const TComplex& a, const TComplex& b) {
    TComplex result = a;
    result /= b;
    return result;
}

ostream& operator<<(ostream& os, const TComplex& t) {
    os << "[" << t.r << " * (cos(" << t.theta << ") + i*sin(" << t.theta << "))]";
    return os;
}
