#include <iostream>
#include <math.h>

// Task 1

class IFigure {
public:
    // pure virtual
    virtual float calculateArea() const = 0;
};


class Circle : public IFigure {
protected:
    float radius;
public:
    Circle(float radius) {
        setRadius(radius);
    }

    void setRadius(const float length) {
        this->radius = length;
    }

    float getRadius() const {
        return radius;
    }

    float calculateArea() const override {
        return M_PI * pow(radius, 2);
    }

    virtual ~Circle() {
        std::cout << "Circle has been destroyed..." << std::endl;
    }
};

class Parallelogram : public IFigure {
protected:
    uint16_t sideAB, sideBC, height; // opposite sides are equals
public:
    Parallelogram(const uint16_t sideAB, const uint16_t sideBC, const uint16_t height){
        setSideAB(sideAB);
        setSideBC(sideBC);
        setHeight(height);
    }

    void setSideAB(const uint16_t length) {
        this->sideAB = length;
    }

    void setSideBC(const uint16_t length) {
        this->sideBC = length;
    }

    void setHeight(const uint16_t length) {
        this->height = length;
    }

    uint16_t getsideAB() const {
        return this->sideAB;
    }

    uint16_t getSideBC() const {
        return this->sideBC;
    }

    uint16_t getHeight() const {
        return this->height;
    }

    float calculateArea() const override {
        return sideBC * height;
    }

    ~Parallelogram() {
        std::cout << "Parallelogram has been destroyed..." << std::endl;
    }
};

class Rectangle : public Parallelogram {
public:
    Rectangle(uint16_t sideAB, uint16_t sideBC) : Parallelogram(sideAB, sideBC, sideAB) {}

    // equal parent function, but such a task condition
    float calculateArea() const override {
        return sideAB * sideBC;
    }

    virtual ~Rectangle() {
        std::cout << "Rectangle has been destroyed..." << std::endl;
    }
};

class Square : public Parallelogram {
public:
    Square(uint16_t sideAB, uint16_t sideBC) : Parallelogram(sideAB, sideBC, sideAB) {}

    // equal parent function, but such a task condition
    float calculateArea() const override {
        return sideAB * sideBC;
    }

    virtual ~Square() {
        std::cout << "Square has been destroyed..." << std::endl;
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(uint16_t sideAB, uint16_t sideBC, uint16_t height) : Parallelogram(sideAB, sideBC, height) {}

    virtual ~Rhombus() {
        std::cout << "Rhombus has been destroyed..." << std::endl;
    }

    // equal parent function, but such a task condition
    float calculateArea() const override {
        return sideBC * height;
    }
};


// Task 2

class Car {
private:
    std::string company, model;
public:
    Car(const std::string company, const std::string model) {
        this->company = company;
        this->model = model;
        std::cout << "Car is ready..." << std::endl;
    }

    void setCompany(const std::string company) {
        this->company = company;
    }

    void setModel(const std::string model) {
        this->model = model;
    }

    std::string getCompany() const {
        return company;
    }

    std::string getModel() const {
        return model;
    }

    void print() {
        std::cout << "Car model is " << model
                  << "and company did it is " << company
                  << std::endl;
    }

    ~Car() {
        std::cout << "Car is unmounted..." << std::endl;
    }
};

class PassengerCar : public Car {
public:
    PassengerCar(std::string company, std::string model) : Car(company, model) {
        std::cout << "PassengerCar is ready..." << std::endl;
    }

    virtual ~PassengerCar() {
        std::cout << "PassengerCar is unmounted..." << std::endl;
    }
};

class Bus : public Car {
public:
    Bus(std::string company, std::string model) : Car(company, model) {
        std::cout << "Bus is ready..." << std::endl;
    }

    virtual ~Bus() {
        std::cout << "Bus is unmounted..." << std::endl;
    }
};

class Minivan : public PassengerCar, public Bus {
public:
    Minivan(std::string company, std::string model) : PassengerCar(company, model), Bus(company, model) {
        std::cout << "Minivan is ready..." << std::endl;
    }
    virtual ~Minivan(){
        std::cout << "Minivan is unmounted..." << std::endl;
    }
};


// Task 3

class Fraction {
private:
    uint8_t numerator, denominator;
public:
    Fraction(const uint8_t numerator, const uint8_t denominator) {
        if (!denominator) {
            std::cout << "ERROR! Denominator must be greater than 0" << std::endl;
            exit(-1);
        }
        setNumerator(numerator);
        setDenominator(denominator);
    }

    void setNumerator(const uint8_t value) {
        this->numerator = value;
    }

    void setDenominator(const uint8_t value) {
        this->denominator = value;
    }

    uint8_t getNumerator() const {
        return this->numerator;
    }

    uint8_t getDenominator() const {
        return this->denominator;
    }

    float getFloatFraction() const {
        return static_cast < float > (numerator) / static_cast < float > (denominator);
    }

    ~Fraction() {
        std::cout << "Fraction is removed" << std::endl;
    }

    friend float operator+ (const Fraction &first, const Fraction &second) {
        return first.getFloatFraction() + second.getFloatFraction();
    }

    friend float operator- (const Fraction &first, const Fraction &second) {
        return first.getFloatFraction() - second.getFloatFraction();
    }

    friend float operator* (const Fraction &first, const Fraction &second) {
        return first.getFloatFraction() * second.getFloatFraction();
    }

    friend float operator/ (const Fraction &first, const Fraction &second) {
        return first.getFloatFraction() / second.getFloatFraction();
    }

    friend float operator- (const Fraction &first) {
        return -first.getFloatFraction();
    }

    friend bool operator== (const Fraction &first, const Fraction &second) {
        return first.getFloatFraction() == second.getFloatFraction();
    }

    friend bool operator!= (const Fraction &first, const Fraction &second) {
        return first.getFloatFraction() != second.getFloatFraction();
    }

    friend bool operator< (const Fraction &first, const Fraction &second) {
        return first.getFloatFraction() < second.getFloatFraction();
    }

    friend bool operator> (const Fraction &first, const Fraction &second) {
        return first.getFloatFraction() > second.getFloatFraction();
    }

    friend bool operator<= (const Fraction &first, const Fraction &second) {
        return first.getFloatFraction() <= second.getFloatFraction();
    }

    friend bool operator>= (const Fraction &first, const Fraction &second) {
        return first.getFloatFraction() >= second.getFloatFraction();
    }
};


// Task 4

enum Suit {
    DIAMOND,
    HEART,
    CLUB,
    SPADE
};

enum CardValue {
    ACE = 1,
    TWO = 2,
    THREE = 2,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    JACK = 10,
    QUEEN = 10,
    KING = 10,
};

class Card {
private:
    Suit _cardSuit;
    CardValue _cardValue;
    bool _opened = false;
public:
    Card(Suit suit, CardValue value){
        this->_cardSuit = suit;
        this->_cardValue = value;
        this->_opened = false;
    }

    void setSuit(Suit const value) {
        this->_cardSuit = value;
    }

    void setValue(CardValue const value) {
        this->_cardValue = value;
    }

    void setOpened(bool const open) {
        this->_opened = open;
    }

    Suit getSuit() const {
        return this->_cardSuit;
    }

    CardValue getValue() const {
        return this->_cardValue;
    }

    bool getOpened() const {
        return this->_opened;
    }

    void flip() {
        setOpened(!getOpened());
    }

    void print() {
        std::cout << "Card suit: " << _cardSuit << ", card value: " << _cardValue << ", card is open: " << _opened << std::endl;
    }

    ~Card() {
        std::cout << "Card has been removed" << std::endl;
    }
};

int main() {

    //Task 1

    Circle c0(2);
    Parallelogram p0(2,3,2);
    Square square0(4,5);
    Rhombus rhombus0(3,2,5);
    Rectangle rect0(7,4);

    IFigure* figures[] = {&c0, &p0, &square0, &rhombus0, &rect0};

    for (int i = 0; i < 5; ++i) {
        std::cout << figures[i]->calculateArea() << std::endl;
    }


    // Task 2

    Bus bus("PAZ","Pazik");
    PassengerCar car("VAZ","Lada");

    car.print();

    Minivan minivan("GAZ","Galelle");

    //minivan.print(); //Non-static member 'print' found in multiple base-class subobjects of type 'Car'


    // Task 3

    Fraction fr1(4,2);
    Fraction fr2(6,3);

    std::cout << fr1 + fr2 << std::endl;
    std::cout << fr1 - fr2 << std::endl;
    std::cout << fr1 * fr2 << std::endl;
    std::cout << fr1 / fr2 << std::endl;
    std::cout << -fr1 << std::endl;
    std::cout << (fr1 == fr2) << std::endl;
    std::cout << (fr1 != fr2) << std::endl;
    std::cout << (fr1 < fr2) << std::endl;
    std::cout << (fr1 > fr2) << std::endl;
    std::cout << (fr1 <= fr2) << std::endl;
    std::cout << (fr1 >= fr2) << std::endl;


    // Task 4

    Card myCard(Suit::CLUB, CardValue::FOUR);

    myCard.print();
    myCard.flip();
    myCard.print();
    std::cout << myCard.getSuit() << std::endl;
    std::cout << myCard.getValue() << std::endl;

    return 0;
}
