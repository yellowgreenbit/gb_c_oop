#include <iostream>

// Task 1

class Person {
protected:
    std::string name;
    int age;
    float weight;
public:
    Person(std::string name = "Неизвестный", int age = 0, float weight = .0f) {
        this->setName(name);
        this->setAge(age);
        this->setWeight(weight);
    }

    void setName(std::string name) {
        this->name = name;
    }
    void setAge(int age) {
        this->age = age;
    }
    void setWeight(float weight) {
        this->weight = weight;
    }
    void print() {
        std::cout
            << "Name: " << name.c_str()
            << " Age: " << age
            << " Weight: " << weight
            << std::endl;
    }
};

class Student : public Person {
protected:
    int yearEducation;
    void setStudentsCount() {
        static int studentsCount{0};
        studentsCount++;
        std::cout << "Count students: " << studentsCount << std::endl;
    }
public:
    Student(std::string name, int age, float weight, int beginEducation) : Person(name, age, weight) {
        this->yearEducation = beginEducation;
        setStudentsCount();
    }

    ~Student(){}

    void setYearEducation(int year) {
        this->yearEducation = year;
    }

    int getYearEducation() const {
        return yearEducation;
    }

    void incrementYearEducation() {
        this->yearEducation++;
    }

    void print(){
        std::cout
                << "Name: " << name.c_str()
                << " Age: " << age
                << " Weight: " << weight
                << " yearEducation: " << yearEducation
                << std::endl;
    }
};


// Task 2

class Fruit {
protected:
    std::string color, name;
public:
    Fruit(std::string color = "", std::string name = ""){
        setName(name);
        setColor(color);
    }

    ~Fruit() {
        std::cout << "the fruit was eaten..." << std::endl;
    }

    void setName(std::string name) {
        this->name = name;
    }
    void setColor(std::string color) {
        this->color = color;
    }
    std::string getName() const {
        return name;
    }
    std::string getColor() const {
        return color;
    }
    void print() {
        std::cout << name << " " << color << std::endl;
    }
};

class Apple : public Fruit{
public:
    Apple( std::string color = "yellow", std::string name = "apple") : Fruit(color, name){}
};

class GrannySmith : public Apple{
public:
    GrannySmith( std::string color = "green", std::string name = "Granny Smith apple") : Apple(color, name){}
};

class Banana : public Fruit{
public:
    Banana(std::string color = "yellow", std::string name = "banana") : Fruit(color, name){}
};


int main() {

// Task 1

    Person Vasya("Vasya", 33, 65.4f);
    Vasya.print();

    Student Nikolai("Nikolai", 22, 51.2f, 2022);

    Nikolai.print();
    Nikolai.incrementYearEducation();
    Nikolai.print();

    Student Misha("Misha", 23, 52.2f, 2021);
    Misha.print();

    Student Maria("Maria", 24, 54.2f, 2020);
    Maria.print();

// Task 2

    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}

// Task 3
// 1. Класс PockerGame - содержит основной цикл и проверки на выигрыш / проигрыш, очередность хода.
// 2. Класс Player, который содержит поля имя, очередь хода и карты (массив).
// 2.1 Класс PlayerAI. Тут что-то с логикой AI. Решения брать / не брать карту.
// 2.1 Класс Gamer. Здесь можно прикрутить интерфейс общения пользователя с программой.
// 3. Класс набор карт.
// 3.1. Производный класс Колода. Содержит массив карт, с возможностью рандомной выборки карты из колоды.
// 3.2. Производный Класс набор игрока. Содержит массив карт, с методом который добавляет карту, возможно, определяет сумму очков.