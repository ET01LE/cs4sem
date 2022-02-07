#include <stdio.h>
#include <iostream>
#include "math.h"

using namespace Math;

int main()
{
    Vector A(1.0, 0.0, 0.0);
    Vector B(0.0, 1.0, 0.0);
    std::cout << "A = (" << A.get_x() << ", " << A.get_y() << ", " << A.get_z() << ")\n";
    std::cout << "B = (" << B.get_x() << ", " << B.get_y() << ", " << B.get_z() << ")\n";
    Vector C = A.plus(B);
    printf("A + B = C = "); C.print(); printf("\n");
    Vector D = A.minus(B);
    printf("A - B = D = "); D.print(); printf("\n");
    printf("abs(C) = %.2f\n", C.abs());
    printf("abs(D) = %.2f\n", D.abs());
    Vector F = C.mul(-1.0);
    printf("-C = F = "); F.print(); printf("\n");
    printf("(C, F) = %.2f\n", C.dot_prod(F));
    Vector E = A.cross_prod(B);
    printf("[A, B] = E = "), E.print(); printf("\n");
    return 0;
}