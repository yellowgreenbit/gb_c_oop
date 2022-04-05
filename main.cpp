#include <iostream>

class Animal{
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

    void move(){ std::cout << name << " walks on paws" << std::endl; }
    void info() {
        printf("%s is %s and %d years of age\n", name.c_str(), color.c_str(), age);
    }
    void voice(){ std::cout << name << " meow" << std::endl; }
};


class Cat : public Animal{
public:
    Cat(std::string name, std::string color, int age) : Animal(name, color, age) {}

    virtual ~Cat(){ std::cout << "Cat left us..." << std::endl; }
    void voice(){ std::cout << name << " meow" << std::endl; }
};


class Dog : public Animal{
public:
    Dog(std::string name, std::string color, int age) : Animal(name, color, age) {}

    virtual ~Dog(){ std::cout << "Dog left us..." << std::endl; }
    void voice(){ std::cout << name << " woof" << std::endl; }
};


class Bird : public Animal{
protected:
    int flyHeight;
public:
    Bird(std::string name, std::string color, int age, int flyHeight) : Animal(name, color, age) {
        this->flyHeight = flyHeight;
    }
    virtual ~Bird(){ std::cout << "Bird left us..." << std::endl; }
    void voice(){}
};

class Parrot : public Bird/*, public Cat*/{
public:
    Parrot(std::string name, std::string color, int age, int height) : Bird(name, color, age, height) {}
    virtual ~Parrot(){ std::cout << "Parrot left us..." << std::endl; }
    void speak(){ std::cout << "polly wanna cracker" << std::endl; }
};


int main() {


    return 0;
}
