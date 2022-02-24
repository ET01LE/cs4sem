#include <iostream>

class Time
{
private:
    int years;
    int months;
    double days;
public:
    Time();
    Time(double days_full);
    Time(int years, int months, double days);
    ~Time();

    void fix();

    double get_days();
    int get_months();
    int get_years();
    double get_full_days();

    void set_days(double days);
    void set_months(int months);
    void set_years(int years);
    void set_full_days(double full_days);

    Time operator +(Time t);
    Time operator -(Time t);
    Time operator *(double a);
    Time operator ++();
    Time operator --();
    Time operator ++(int smth);
    Time operator --(int smth);
    Time operator +=(double a);
    Time operator +=(Time t);
    Time operator -=(double a);
    Time operator -=(Time t);
    bool operator >(Time t);
    bool operator <(Time t);
    bool operator ==(Time t);
    bool operator !=(Time t);
    bool operator >=(Time t);
    bool operator <=(Time t);
    bool operator &&(Time t);
    bool operator ||(Time t);
    bool operator !();
    Time operator -();

    friend std::ostream& operator <<(std::ostream& stream, Time t);
    friend std::ostream& operator >>(std::ostream& stream, Time t);
};

Time operator *(double a, Time t);
std::ostream& operator <<(std::ostream& stream, Time t);
std::ostream& operator >>(std::ostream& stream, Time t);