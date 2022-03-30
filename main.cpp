#include <iostream>

class Cat {
    int age;
    mutable std::string name;
    std::string color;

public:
    Cat() : age(0) {
        color = "Peachy";
        std::cout << " MEOW" << std::endl;
    };

    Cat(std::string name, std::string color, int age) {
        this->name = name;
        this->color = color;
        this->age = age;
    }

    //Copy constructor
    Cat(Cat& c)
        : name(c.name), color(c.color), age(c.age) {}

    ~Cat(){
        std::cout << "Cat left us..." << std::endl;
    }

    void voice(){
        std::cout << name << " meow" << std::endl;
    }

    void move(){
        std::cout << name << " walks on paws" << std::endl;
    }

    void setAge(int a){
        age = a;
    }

    void setName(std::string n) const {
        name = n;
    }

    void const setColor(std::string n){
        color = n;
    }

    int getAge(){
        return age;
    }

    std::string getName(){
        return name;
    }

    std::string getColor(){
        return color;
    }

    void info() {
        printf("%s is %s and %d years of age\n", name.c_str(), color.c_str(), age);
    }
};

void makeCatMove(Cat* c){
    (*c).move();
}

void makeCatMove(Cat& c){
    c.move();
}

int main() {
    // classes vs objects
    Cat c0("Barsik", "White", 5);

    c0.info();

    Cat c1("Murzik", "Black", 2);

    c1.info();
//    c0.setAge(2);
//    c0.setName("Murzik");
//    c0.setColor("Black");

    c0.voice();
    c0.move();

    Cat c2;
    c2.setName("Kotik");
    c2.info();

    Cat* c2p = &c2;

    c2p->setName("pointer");
    c2.info();

    Cat c4(c1);
    c4.info();

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
