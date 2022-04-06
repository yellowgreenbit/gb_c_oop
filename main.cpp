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
// Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2). Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
//математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
//унарный оператор (-)
//логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
//
//Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте перегрузить один через другой.
//
//Продемонстрировать использование перегруженных операторов.

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



/*
//pastebin
//interface
class IAnimal {
public:
// pure virtual function
    virtual void voice() = 0;
    virtual void move() = 0;
    virtual void info() const = 0;
};

//abstract class
class Animal : public IAnimal{
protected:
    int age;
    std::string name;
    std::string color;
public:
    Animal(std::string name, std::string color, int age) {
        this->name = name;
        this->color = color;
        this->age = age;
    }

    ~Animal(){
        std::cout << "Animal left us..." << std::endl;
    }

    void move() override { std::cout << name << " walks on paws" << std::endl; }
    void info() const override { printf("%s is %s and %d years of age\n", name.c_str(), color.c_str(), age); }

    //overloading
    friend std::ostream& operator<< (std::ostream &s, const Animal &a);

    //Animal& operator+(const Animal &al, const Animal &ar){
        //return new Animal();
    //}
};

std::ostream& operator<< (std::ostream &s, const Animal &a){
    s << "Animal " << a.name
    << " of color " << a.color
    << " and " << a.age << " year of age";
    return s;
}


class Cat : public Animal{
public:
    Cat(std::string name, std::string color, int age) : Animal(name, color, age) {}

    virtual ~Cat(){ std::cout << "Cat left us..." << std::endl; }
    void voice() override { std::cout << name << " meow" << std::endl; }
};

class Snake : public Animal{
public:
    Snake(std::string name, std::string color, int age) : Animal(name, color, age) {}

    virtual ~Snake(){ std::cout << "Snake left us..." << std::endl; }
    void voice() override { std::cout << name << " shshsh" << std::endl; }
    void move() override { std::cout << name << " crawls" << std::endl; }
};


class Dog : public Animal{
public:
    Dog(std::string name, std::string color, int age) : Animal(name, color, age) {}

    virtual ~Dog(){ std::cout << "Dog left us..." << std::endl; }
    void voice() override { std::cout << name << " woof" << std::endl; }
};


class Bird : public Animal{
protected:
    int flyHeight;
public:
    Bird(std::string name, std::string color, int age, int flyHeight) : Animal(name, color, age) {
        this->flyHeight = flyHeight;
    }
    virtual ~Bird(){ std::cout << "Bird left us..." << std::endl; }
    void voice() override { std::cout << name << " tweet" << std::endl; }
};

class Parrot : public Bird{
public:
    Parrot(std::string name, std::string color, int age, int height) : Bird(name, color, age, height) {}
    virtual ~Parrot(){ std::cout << "Parrot left us..." << std::endl; }
    void speak() { std::cout << "polly wanna cracker" << std::endl; }
};
*/

int main() {

    //Task 1
/*
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


*/
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

/*
    //Animal a0("Amoba", "Gray", 1);

    Cat c0("Barsik", "Black", 2);
    Cat c1("Tuzik", "Gray", 3);
    Dog d0("Sharik", "White", 4);
    Dog d1("Bobik", "Blue", 1);
    Bird b0("Chijik", "Yellow", 1, 5);
    Parrot p1("Polly", "Green", 2, 3);
    Snake s1("Kaa", "Brown", 10);

    IAnimal * zoo[] = {&c0, &c1, &d0, &d1, &b0, &p1, &s1};
    for (int i = 0; i < 7; i++) {
        zoo[i]->info();
        zoo[i]->move();
        zoo[i]->voice();
    }

    Cat c2("Cat", "Orange", 1);
    std::cout << c2 << std::endl;
*/
    return 0;
}
