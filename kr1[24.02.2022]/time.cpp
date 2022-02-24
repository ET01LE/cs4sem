#include "time.hpp"

Time::Time()
{
    this->years = 0;
    this->months = 0;
    this->days = 0.0;
    return;
}

Time::Time(int years, int months, double days)
{
    this->years = years;
    this->months = months;
    this->days = days;
    this->fix();
    return;
}

Time::Time(double days_full)
{
    this->years = 0;
    this->months = 0;
    this->days = days_full;
    this->fix();
    return;
}

Time::~Time(){}

void Time::fix()
{
    int extra_months = (int)this->days / 30;
    this->days -= extra_months * 30;
    if (this->days < 0.0)   // months = 1, days = -7 should be
    {                       // months = 0, days = 23
        extra_months--;
        days += 30;
    }
    this->months += extra_months;
    int extra_years = this->months / 12;
    this->months -= extra_years * 12;
    if (this->months < 0)   // years = 0, months = -7 should be
    {                       // years = -1, months = 5
        extra_years--;
        months += 12;
    }
    this->years += extra_years;
    return;
}

double Time::get_days()
{
    return this->days;
}

int Time::get_months()
{
    return this->months;
}

int Time::get_years()
{
    return this->years;
}

double Time::get_full_days()
{
    return this->days + this->months * 30 + this->years * 360;
}

void Time::set_days(double days)
{
    days -= ((int)days / 30) * 30;
    if (days < 0.0) days += 30; // days = -7 should be days = 23
    this->days = days;
    return;
}

void Time::set_months(int months)
{
    months %= 12;
    if (months < 0) months += 12; // months = -7 should be months = 5
    this->months = months;
    return;
}

void Time::set_years(int years)
{
    this->years = years;
    return;
}

void Time::set_full_days(double full_days)
{
    this->years = 0;
    this->months = 0;
    this->days = full_days;
    this->fix();
    return;
}

Time Time::operator +(Time t)
{
    Time res;
    res.years = this->years + t.years;
    res.months = this->months + t.months;
    res.days = this->days + t.days;
    res.fix();
    return res;
}

Time Time::operator -(Time t)
{
    Time res;
    res.years = this->years - t.years;
    res.months = this->months - t.months;
    res.days = this->days - t.days;
    res.fix();
    return res;
}

Time Time::operator *(double a)
{
    Time res;
    double full_days = a * this->get_full_days();
    res.set_full_days(full_days);
    return res;
}

Time operator *(double a, Time t)
{
    return t * a;
}

Time Time::operator ++()
{
    this->days++;
    this->fix();
    return *this;
}

Time Time::operator --()
{
    this->days--;
    this->fix();
    return *this;
}

Time Time::operator ++(int smth)
{
    Time temp = *this;
    this->days++;
    this->fix();
    return temp;
}

Time Time::operator --(int smth)
{
    Time temp = *this;
    this->days--;
    this->fix();
    return temp;
}

Time Time::operator +=(double a)
{
    this->days += a;
    this->fix();
    return *this;
}

Time Time::operator -=(double a)
{
    this->days -= a;
    this->fix();
    return *this;
}

Time Time::operator +=(Time t)
{
    *this = *this + t;
    return *this;
}

Time Time::operator -=(Time t)
{
    *this = *this - t;
    return *this;
}

bool Time::operator >(Time t)
{
    return this->get_full_days() > t.get_full_days();
}

bool Time::operator <(Time t)
{
    return this->get_full_days() < t.get_full_days();
}

bool Time::operator ==(Time t)
{
    return this->get_full_days() == t.get_full_days();
}

bool Time::operator !=(Time t)
{
    return this->get_full_days() != t.get_full_days();
}

bool Time::operator >=(Time t)
{
    return this->get_full_days() >= t.get_full_days();
}

bool Time::operator <=(Time t)
{
    return this->get_full_days() <= t.get_full_days();
}

bool Time::operator &&(Time t)
{
    return this->years && t.years;
}

bool Time::operator ||(Time t)
{
    return this->years || t.years;
}

bool Time::operator !()
{
    return !this->years;
}

Time Time::operator -()
{
    Time res = *this;
    res.years *= -1;
    return res;
}

std::ostream& operator <<(std::ostream& stream, Time t)
{
    stream <<  t.days << "d " << t.months << "m " << t.years << "y ";
    return stream;
}

std::ostream& operator >>(std::ostream& stream, Time t)
{
    stream >>  t.days >> t.months >> t.years;
    return stream;
}