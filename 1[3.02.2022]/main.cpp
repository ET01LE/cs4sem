#include <stdio.h>
#include <iostream>
#include "math.h"

using namespace Math;

int main()
{
    Vector a(1.0, 1.0, 0.0);
    Vector b(0.0, 0.0, 1.0);
    Vector c = a.plus(b);
    Vector d = a.minus(b);
    Vector e = a.mul(-1.0);
    Vector f = a.cross_prod(b);

    std::cout << "a = " << a.get_x() << " " << a.get_y() << " " << a.get_z() << std::endl; // just testing iostream
    std::cout << "b = " << b.get_x() << " " << b.get_y() << " " << b.get_z() << std::endl;
    printf("abs(a) = %.2f\n", a.abs());
    printf("a + b = c = ");     c.print();      printf("\n");
    printf("a - b = d = ");     d.print();      printf("\n");
    printf("-a = e = ");        e.print();      printf("\n");
    printf("(a, e) = %.2f\n", a.dot_prod(e));
    printf("[a, b] = f = "),    f.print();      printf("\n\n");

    c = a + b;
    d = a - b;
    e = c * -1.0;
    e = a ^ b;
    printf("a + b = c = ");     c.print();      printf("\n");
    printf("a - b = d = ");     d.print();      printf("\n");
    printf("-a = e = ");        e.print();      printf("\n");
    printf("(a, e) = %.2f\n", a * e);
    printf("[a, b] = f = "),    f.print();      printf("\n\n");
    
    Matrix E(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
    Vector v(1.0, 2.0, 3.0);
    Vector v1 = E * v;
    Vector v2 = v * E;
    Matrix M(0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0);
    Matrix N = M * 7;
    Matrix Msqrd = M * M;
    Matrix K(7.0, 0.0, 0.0, 0.0, 2.0, 3.0, 0.0, 1.0, 2.0);

    printf("v = ");             v.print();      printf("\n");
    printf("E = \n");           E.print();      printf("\n");
    printf("E * v = ");         v1.print();     printf("\n");
    printf("v * E = ");         v2.print();     printf("\n");
    printf("M = \n");           M.print();      printf("\n");
    printf("N = 7M = \n");      N.print();      printf("\n");
    printf("Msqrd = M^2 = \n"); Msqrd.print();  printf("\n");
    printf("K = \n");           K.print();      printf("\n");
    printf("det(K) = %.0f\n\n", K.det());    

    Vector h;
    Vector g = h++;
    h.print();                  printf("\n");     
    g.print();                  printf("\n");
    g = ++h;
    h.print();                  printf("\n");     
    g.print();                  printf("\n\n");
    Matrix S;
    Matrix T = S++;
    S.print();                  printf("\n\n");     
    T.print();                  printf("\n\n");
    T = ++S;
    S.print();                  printf("\n\n");     
    T.print();                  printf("\n\n");

    return 0;
}