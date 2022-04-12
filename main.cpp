#include <iostream>

using namespace std;


// Task 1
template <class T>
class Pair1{
private:
    T *data;
public:
    Pair1(T _first, T _second) {
        this->data = new T(2);

        this->data[0] = _first;
        this->data[1] = _second;
    }

    T getFirst () const {
        return data[0];
    }

    T getSecond () const {
        return data[1];
    }

    ~Pair1() {
        delete [] data;
        data = nullptr;
    }
};


// Task 2
/*
template <class T>
class Pair{
private:
    T first;
    T second;
public:
    Pair(T _first, T _second) : first(_first), second(_second) { }

    T getFirst () const {
        return first;
    }

    T getSecond () const {
        return second;
    }

    ~Pair() { }
};


// Task 3
template <class T>
class Pair{
private:
    string first;
    T second;
public:
    Pair(){}
    Pair(string _first, T _second) : first(_first), second(_second) { }

    string getFirst () const {
        return first;
    }

    T getSecond () const {
        return second;
    }

    virtual ~Pair() { }
};

template <class T>
class StringValuePair : public Pair<int>{
    string first;
    T second;
public:
    StringValuePair(string _first, T _second) : Pair<int>(_first, _second) { }
};
*/

int main()
{
    /*
// Task 1
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.getFirst() << ' ' << p1.getSecond() << '\n';

// Task 1
    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.getFirst() << ' ' << p2.getSecond() << '\n';

    const Pair<double> p3(3, 7.8);
    cout << "Pair: " << p3.getFirst() << ' ' << p3.getSecond() << '\n';

// Task 3
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.getFirst() << ' ' << svp.getSecond() << '\n';
*/
    return 0;
}
