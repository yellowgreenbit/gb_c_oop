#include <iostream>


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

class Parrot : public Bird/*, public Cat*/{
public:
    Parrot(std::string name, std::string color, int age, int height) : Bird(name, color, age, height) {}
    virtual ~Parrot(){ std::cout << "Parrot left us..." << std::endl; }
    void speak() { std::cout << "polly wanna cracker" << std::endl; }
};


int main() {

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

    return 0;
}
