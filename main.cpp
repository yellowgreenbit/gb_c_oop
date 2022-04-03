#include <iostream>

class Animal{
protected:
    int age;
    std::string name;
    std::string color;
    Animal(){}
public:

    Animal(std::string name, std::string color, int age) {
        this->name = name;
        this->color = color;
        this->age = age;
    }

    ~Animal(){
        std::cout << "Animal left us..." << std::endl;
    }

    void setAge(int a){ age = a; }
    void setName(std::string n) { name = n; }
    void setColor(std::string n) { color = n; }
    int getAge () const { return age; }

    std::string getName() const { return name; }
    std::string getColor() const { return color; }

    void move(){ std::cout << name << " walks on paws" << std::endl; }
    void info() {
        printf("%s is %s and %d years of age\n", name.c_str(), color.c_str(), age);
    }
};


class Cat : public Animal{
public:
    Cat(std::string name, std::string color, int age) : Animal(name, color, age) {}

    virtual ~Cat(){ std::cout << "Cat left us..." << std::endl; }

    void voice(){ std::cout << name << " meow" << std::endl; }
};


class Dog : public Animal{
public:
    Dog(std::string name, std::string color, int age) {
        this->name = name;
        this->color = color;
        this->age = age;
    }

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
    void voice(){ std::cout << name << " tweet" << std::endl; }
};

class Parrot : public Bird/*, public Cat*/{
public:
    //Parrot(std::string name, std::string color, int age, int height) : Animal(name, color, age), flyHeight(height) {}
    Parrot(std::string name, std::string color, int age, int height) : Bird(name, color, age, height) {}
    virtual ~Parrot(){ std::cout << "Parrot left us..." << std::endl; }
    void speak(){ std::cout << "polly wanna cracker" << std::endl; }
};


int main() {

    Cat c0("Barsik", "Black", 2);
    Cat c1("Tuzik", "Gray", 3);
    Dog d0("Sharik", "White", 4);
    Dog d1("Bobik", "Blue", 1);
    Bird b0("Chijik", "Yellow", 1, 5);
    Parrot p1("Polly", "Green", 2, 3);

    Animal * zoo[] = {&c0, &c1, &d0, &d1, &b0, &p1};
    for (int i = 0; i < 6; i++) {
        zoo[i]->info();

    }

    //typecast
    Parrot* pp = static_cast<Parrot*>(zoo[5]);

    pp->speak();

    static_cast<Parrot *> (zoo[5])->speak();

    ((Parrot *) zoo[5])->speak();

    p1.speak();
    return 0;
}
