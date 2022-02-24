namespace Math
{
    class Vector;
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

        Vector plus(Vector v);
        Vector minus(Vector v);
        Vector mul(double);
        double dot_prod(Vector v);
        Vector cross_prod(Vector v);
        
        void print();

        Vector operator +(Vector v);
        Vector operator -(Vector v);
        Vector operator *(double a);
        friend Vector operator *(double a, Vector v);
        double operator *(Vector v);
        Vector operator ^(Vector v); // cross product
        Vector operator *(Matrix M);

        Vector operator ++();
        Vector operator ++(int x);
        Vector operator --();
        Vector operator --(int x);

        friend class Matrix;
    };

    Vector operator *(double a, Vector v);

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

        Matrix operator +(Matrix M);
        Matrix operator -(Matrix M);
        Matrix operator *(double a);
        friend Matrix operator *(double a, Matrix M);
        Vector operator *(Vector v);
        Matrix operator *(Matrix M);

        void print();

        Matrix operator ++();
        Matrix operator ++(int x);
        Matrix operator --();
        Matrix operator --(int x);

        friend class Vector;
    };

    Matrix operator *(double a, Matrix M);
}
