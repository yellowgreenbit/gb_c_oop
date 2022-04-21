#include <iostream>
#include <iomanip>
#include <string>


// Task 1
class Date {
    unsigned day;
    unsigned month;
    unsigned year;
public:
    Date(unsigned _day, unsigned _month, unsigned _year) : day(_day), month(_month), year(_year) { };

    unsigned getDay() const { return this->day; }
    unsigned getMonth() const { return this->month; }
    unsigned getYear() const { return this->year; }

    void setDay(int _day) { this->day = _day; }
    void setMonth(int _month) { this->month = _month; }
    void setYear(int _year) { this->year = _year; }

    int getIntValue() {
        std::stringstream result;
        result << std::setfill('0')
              << std::to_string(getYear())
              << std::setw(2) << std::to_string(getMonth())
              << std::setw(2) << std::to_string(getDay());

        return atoi(result.str().c_str());
    }

    friend std::ostream& operator<<(std::ostream& os, const Date& d) {
        os << std::setfill('0')
        << std::setw(2) << std::to_string(d.getDay()) << '.'
        << std::setw(2) << std::to_string(d.getMonth()) << '.'
        << std::to_string(d.getYear())
        << std::endl;
        return os;
    }

    ~Date(){};
};

template <class T>
class Pointer {
    T* point;
public:
    Pointer(T* _point = nullptr) : point(_point) {}

    ~Pointer() {
        //if(point == nullptr){
            delete point;
       //}
    }

    Pointer& operator=(Pointer& p)
    {
        if (&p == this)
            return *this;

        delete point;
        point = p.point;
        p.point = nullptr;

        return *this;
    }

    Pointer(Pointer& p)
    {
        point = p.point;
        p.point = nullptr;
    }

    T& operator*() const {
        return *point;
    }

    T* operator->() const {
        return point;
    }
};


// Task 2

Pointer<Date>& compare(Pointer<Date>& firstDate, Pointer<Date>& secondDate){
    return (firstDate->getIntValue() >= secondDate->getIntValue()) ? firstDate : secondDate;
}

void swap(Pointer<Date>& a, Pointer<Date>& b)
{
    Pointer<Date> temp(a);
    a = b;
    b = temp;
}

int main() {

    // Task 1

    Pointer<Date> today(new Date(20, 4, 2022));

    std::cout << today->getDay() << std::endl;
    std::cout << today->getMonth() << std::endl;
    std::cout << today->getYear() << std::endl;
    std::cout << *today;

    Pointer<Date> date;

    date = today;

    std::cout << "today is " << *today;
    std::cout << "date is " << *date;

    // Task 2

    Pointer<Date> tomorrow(new Date(19, 11, 2021));
    std::cout << *compare(tomorrow, today);

    swap(tomorrow, today);

    std::cout << "today is " << *today;
    std::cout << "tomorrow is " << *tomorrow;
    return 0;
}