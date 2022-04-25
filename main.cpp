#include <iostream>

// Task 1
template <typename T1, typename T2> float division(T1 a, T2 b) try {
    if (b == 0)
        throw std::runtime_error("DivisionByZero!");

    return a / b;
} catch (std::exception& e) {
    throw std::runtime_error(dynamic_cast<std::runtime_error &>(e));
}

// Task 2
class Ex {
    int x;
public:
    Ex(const int _num) : x(_num) { };

    void setNum(const int _num) {
        this->x = _num;
    }

    const int getNum() const {
        return this->x;
    }

    int operator+ (const Ex& ex) {
        return ex.x;
    }

    virtual ~Ex(){}
};

class Bar {
    int y;
public:
    Bar(const int _num = 0) : y(_num) {};

    void setNum(const int _num) {
        this->y = _num;
    }

    const int getNum() {
        return this->y;
    }

    int set(const int a) {
        std::cout << "sum - " << this->y + a << std::endl;
        if(this->y + a > 100) {
            throw Ex(this->y * a);
        }
        setNum(a);
    }

    virtual ~Bar(){}
};

// Task 3

class OffTheField {
    const int _x;
    const int _y;
    const int _newX;
    const int _newY;
public:
    OffTheField(const int x, const int y, const int newX, const int newY) : _x(x), _y(y), _newX(newX), _newY(newY){ }
    std::string getError() const {
        return "OffTheField. Robot can't leave grid from pos "
               + std::to_string(_x) + " " + std::to_string(_y)
               + " to " + std::to_string(_newX) + " " + std::to_string(_newY);
    }
};

class IllegalCommand {
    const int _newX;
    const int _newY;
public:
    IllegalCommand(const int newX, const int newY) : _newX(newX), _newY(newY){ }
    std::string getError() const {
        return "IllegalCommand. Values must be integer in range from -1 to 1, not: " + std::to_string(_newX) + " " + std::to_string(_newY);
    }
};

class Robot{
    int posX;
    int posY;
public:
    Robot(int x, int y) : posX(x), posY(y) {}

    void setX(const int &x){
        this->posX = x;
    };

    void setY(const int &y){
        this->posY = y;
    };

    void moveTo(const int &newX, const int &newY) {

        if(newX > 1 || newX < -1 || newY > 1 || newY < -1) {
            throw IllegalCommand(newX, newY);
        }

        int tempX = posX + newX;
        int tempY = posY + newY;

        if(0 > tempX || tempX > 10 || 0 > tempY || tempY > 10) {
            throw OffTheField(posX, posY, tempX, tempY);
        } else {
            std::cout << "Moving to " << tempX << ' ' << tempY << '\n';
        }

        setX(tempX);
        setY(tempY);
    }

    virtual ~Robot(){};
};

int main() {

    // Task 1
    std::cout << division(10, 2) << std::endl;

    // Task 2
    Ex ex1(3);
    Bar bar1(2);

    int b;

    try {
        while (b != 0) {
            std::cout << "Enter num ";
            std::cin >> b;

            bar1.set(b);
        }
    } catch (const Ex e) {
        std::cout << e.getNum() << "\n";
    }

    // Task 3
    Robot r2d2(0, 0);
    int userKeyX;
    int userKeyY;

    while (true) {
        std::cout << "Enter new X location(-1/0/1)";
        std::cin >> userKeyX;

        std::cout << "Enter new Y location(-1/0/1)";
        std::cin >> userKeyY;
        try {
            r2d2.moveTo(userKeyX, userKeyY);
        } catch (const OffTheField& exeption) {
            std::cout << exeption.getError() << std::endl;
            break;
        } catch (const IllegalCommand& exeption) {
            std::cout << exeption.getError() << std::endl;
            break;
        }
    }

    return 0;
}