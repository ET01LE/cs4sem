#include <cmath>
#include <stdio.h>
#include "math.h"

using namespace Math;

Vector::Vector()
{
    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;
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
    return this->x;
}

double Vector::get_y()
{
    return this->y;
}

double Vector::get_z()
{
    return this->z;
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

double Vector::abs()
{
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

Vector Vector::plus(Vector v)
{
    return Vector(this->x + v.x, this->y + v.y, this->z + v.z);
}

Vector Vector::minus(Vector v)
{
    return Vector(this->x - v.x, this->y - v.y, this->z - v.z);
}

Vector Vector::mul(double a)
{
    return Vector(a * this->x, a * this->y, a * this->z);
}

double Vector::dot_prod(Vector v)
{
    return this->x * v.x + this->y * v.y + this->z * v.z;
}

Vector Vector::cross_prod(Vector v)
{
    Vector res;
    res.x = this->y * v.z - this->z * v.y;
    res.y = this->z * v.x - this->x * v.z;
    res.z = this->x * v.y - this->y * v.x;
    return res;
}

void Vector::print()
{
    printf("%5.1f %5.1f %5.1f", this->x, this->y, this->z);
    return;
}

Vector Vector::operator+(Vector v)
{
    return Vector(this->x + v.x, this->y + v.y, this->z + v.z);
}

Vector Vector::operator-(Vector v)
{
    return Vector(this->x - v.x, this->y - v.y, this->z - v.z);
}

Vector Vector::operator*(double a)
{
    return Vector(a * this->x, a * this->y, a * this->z);
}

double Vector::operator*(Vector v)
{
    return this->x * v.x + this->y * v.y + this->z * v.z;
}

Vector Vector::operator^(Vector v) // cross product
{
    Vector res;
    res.x = this->y * v.z - this->z * v.y;
    res.y = this->z * v.x - this->x * v.z;
    res.z = this->x * v.y - this->y * v.x;
    return res;
}

Vector Vector::operator *(Matrix M)
{
    return Vector(*this * M.get_e1(), *this * M.get_e2(), *this * M.get_e3());
}

Matrix::Matrix(){}

Matrix::Matrix(Vector e1, Vector e2, Vector e3)
{
    this->e1 = e1;
    this->e2 = e2;
    this->e3 = e3;
}

Matrix::Matrix(double x11, double x12, double x13, double x21, double x22, double x23, double x31, double x32, double x33)
{
    this->e1 = Vector(x11, x21, x31);
    this->e2 = Vector(x12, x22, x32);
    this->e3 = Vector(x13, x23, x33);
}

Matrix::~Matrix(){}

Vector Matrix::get_e1()
{
    return this->e1;
}

Vector Matrix::get_e2()
{
    return this->e2;
}

Vector Matrix::get_e3()
{
    return this->e3;
}

void Matrix::set_e1(Vector e1)
{
    this->e1 = e1;
    return;
}

void Matrix::set_e2(Vector e2)
{
    this->e2 = e2;
    return;
}

void Matrix::set_e3(Vector e3)
{
    this->e3 = e3;
    return;
}

Matrix Matrix::transpose()
{
    Matrix M = *this;
    M.e1.set_y(this->e2.get_x());
    M.e2.set_x(this->e1.get_y());
    M.e1.set_z(this->e3.get_x());
    M.e3.set_x(this->e1.get_z());
    M.e2.set_z(this->e3.get_y());
    M.e3.set_y(this->e2.get_z());
    return M;
}

double Matrix::det()
{
    double a[9];
    a[0] = this->e1.get_x();
    a[1] = this->e2.get_x();
    a[2] = this->e3.get_x();
    a[3] = this->e1.get_y();
    a[4] = this->e2.get_y();
    a[5] = this->e3.get_y();
    a[6] = this->e1.get_z();
    a[7] = this->e2.get_z();
    a[8] = this->e3.get_z();
    double det = 0; 
    det += a[0] * a[4] * a[8];
    det += a[1] * a[5] * a[6];
    det += a[3] * a[7] * a[2];
    det -= a[2] * a[4] * a[6];
    det -= a[1] * a[3] * a[8];
    det -= a[5] * a[7] * a[0];
    return det;
}

Matrix Matrix::operator+(Matrix M)
{
    return Matrix(this->e1 + M.e1, this->e2 + M.e2, this->e3 + M.e3);
}

Matrix Matrix::operator-(Matrix M)
{
    return Matrix(this->e1 - M.e1, this->e2 - M.e2, this->e3 - M.e3);
}

Matrix Matrix::operator*(double a)
{
    return Matrix(this->e1 * a, this->e2 * a, this->e3 * a);
}

Vector Matrix::operator*(Vector v)
{
    Matrix M = this->transpose();
    return Vector(M.e1 * v, M.e2 * v, M.e3 * v); 
}

Matrix Matrix::operator*(Matrix M)
{
    Matrix N = this->transpose();
    Matrix Res;
    Res.e1 = Vector(N.e1 * M.e1, N.e2 * M.e1, N.e3 * M.e1);
    Res.e2 = Vector(N.e1 * M.e2, N.e2 * M.e2, N.e3 * M.e2);
    Res.e3 = Vector(N.e1 * M.e3, N.e2 * M.e3, N.e3 * M.e3);
    return Res;
}

void Matrix::print()
{
    Matrix M = this->transpose();
    M.e1.print();
    printf("\n");
    M.e2.print();
    printf("\n");
    M.e3.print();
    return;
}