#include <iostream>
#include <cassert>
#include "AComplex.h"
#include "TComplex.h"
#include <cmath>
using namespace std;

int main() {
    AComplex a1(3, 4), a2(1, -2);
    TComplex t1 = a1.toTComplex(), t2 = a2.toTComplex();

    // Performing operations in algebraic form
    AComplex add = a1 + a2;
    AComplex sub = a1 - a2;
    AComplex mul = a1 * a2;
    AComplex div = a1 / a2;

    // Expected results for addition
    AComplex expectedAdd(4, 2);
    assert(fabs(add.re - expectedAdd.re) < 1e-6 && fabs(add.im - expectedAdd.im) < 1e-6);

    // Expected results for subtraction
    AComplex expectedSub(2, 6);
    assert(fabs(sub.re - expectedSub.re) < 1e-6 && fabs(sub.im - expectedSub.im) < 1e-6);

    // Expected results for multiplication (using trigonometric form)
    AComplex expectedMul(11, -2);
    assert(fabs(mul.re - expectedMul.re) < 1e-6 && fabs(mul.im - expectedMul.im) < 1e-6);

    // Expected results for division (using trigonometric form)
    AComplex expectedDiv(-1, 2);
    assert(fabs(div.re - expectedDiv.re) < 1e-6 && fabs(div.im - expectedDiv.im) < 1e-6);

    // Performing addition in trigonometric form and converting back to algebraic
    TComplex tAdd = t1 + t2;
    AComplex aAdd = tAdd.toAComplex();
    assert(fabs(aAdd.re - expectedAdd.re) < 1e-6 && fabs(aAdd.im - expectedAdd.im) < 1e-6);

    // Performing subtraction in trigonometric form and converting back to algebraic
    TComplex tSub = t1 - t2;
    AComplex aSub = tSub.toAComplex();
    assert(fabs(aSub.re - expectedSub.re) < 1e-6 && fabs(aSub.im - expectedSub.im) < 1e-6);

    // If all assertions pass, print success message
    cout << "All tests passed." << "\n";
    return 0;
}
