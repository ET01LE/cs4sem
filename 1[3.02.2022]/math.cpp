#include <cmath>
#include <stdio.h>
#include "math.h"

using namespace Math;

Vector::Vector()
{
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

Vector::Vector(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector::~Vector(){}

double Vector::get_x()
{
    return x;
}

double Vector::get_y()
{
    return y;
}

double Vector::get_z()
{
    return z;
}

void Vector::set_x(double x)
{
    this->x = x;
    return;
}

void Vector::set_y(double y)
{
    this->y = y;
    return;
}

void Vector::set_z(double z)
{
    this->z = z;
    return;
}

void Vector::print()
{
    printf("(%.2f, %.2f, %.2f)", x, y, z);
    return;
}

Vector Vector::plus(Vector add)
{
    Vector res(x + add.get_x(), y + add.get_y(), z + add.get_z());
    return res;
}

Vector Vector::minus(Vector sub)
{
    Vector res(x - sub.get_x(), y - sub.get_y(), z - sub.get_z());
    return res;
}

Vector Vector::mul(double a)
{
    Vector res(a * x, a * y, a * z);
    return res;
}

double Vector::dot_prod(Vector v)
{
    double res = x * v.get_x() + y * v.get_y() + z * v.get_z();
    return res;
}

Vector Vector::cross_prod(Vector v)
{
    Vector res;
    res.set_x(y * v.get_z() - z * v.get_y());
    res.set_y(z * v.get_x() - x * v.get_z());
    res.set_z(x * v.get_y() - y * v.get_x());
    return res;
}

double Vector::abs()
{
    return sqrt(x*x + y*y + z*z);
}
