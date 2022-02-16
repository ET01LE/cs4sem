namespace Math
{
    class Matrix;

    class Vector
    {
    private:
        double x, y, z;
    public:
        Vector();
        Vector(double x, double y, double z);
        ~Vector();

        double get_x();
        double get_y();
        double get_z();
        void set_x(double x);
        void set_y(double y);
        void set_z(double z);

        double abs();

        Vector plus(Vector add);
        Vector minus(Vector sub);
        Vector mul(double);
        double dot_prod(Vector v);
        Vector cross_prod(Vector v);
        
        void print();

        Vector operator +(Vector v);
        Vector operator -(Vector v);
        Vector operator *(double a); 
        double operator *(Vector v);
        Vector operator ^(Vector v); // cross product

        Vector operator *(Matrix M);
    };

    class Matrix
    {
    private:
        Vector e1, e2, e3;
    public:
        Matrix();
        Matrix(Vector e1, Vector e2, Vector e3);
        Matrix(double x11, double x12, double x13, double x21, double x22, double x23, double x31, double x32, double x33);
        ~Matrix();

        Vector get_e1();
        Vector get_e2();
        Vector get_e3();
        void set_e1(Vector e1);
        void set_e2(Vector e2);
        void set_e3(Vector e3);

        Matrix transpose();
        double det();

        Matrix operator +(Matrix m);
        Matrix operator -(Matrix m);
        Matrix operator *(double a);
        Vector operator *(Vector v);
        Matrix operator *(Matrix m);

        void print();
    };
}
