#include "time.hpp"

int main()
{
    Time t1;
    std::cout << t1-- << std::endl;
    std::cout << t1 << std::endl;
    std::cout << ++t1 << std::endl;

    t1.set_days(7.0);
    t1.set_months(7);
    t1.set_years(7);
    std::cout << t1 << std::endl;
    std::cout << t1.get_days()   << "d ";
    std::cout << t1.get_months() << "m ";
    std::cout << t1.get_years()  << "y\n";

    Time t2 = t1 + t1;
    std::cout << t2 << std::endl;

    t1.set_full_days(360.0);
    std::cout << t1 << std::endl;

    return 0;
}