namespace Math
{
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
        Vector plus(Vector add);
        Vector minus(Vector sub);
        Vector mul(double);
        double dot_prod(Vector v);
        Vector cross_prod(Vector v);
        double abs();
        void print();
    };
}