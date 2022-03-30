#include <iostream>
#include <cmath>

using namespace std;

// Task 1

class Power {
    int mass = 2;
    int speed = 3;
public:
    void set(int mass, int speed) {
        this->mass = mass;
        this->speed = speed;
    }

    void calculate(){
        cout << pow(mass, speed) << endl;
    }
};


// Task 2

class RGBA {
    uint8_t m_red = 0;
    uint8_t m_green = 0;
    uint8_t m_blue = 0;
    uint8_t m_alpha = 255;

public:
    RGBA(uint8_t m_red, uint8_t m_green, uint8_t m_blue, uint8_t m_alpha) {
        this->m_red = m_red;
        this->m_green = m_green;
        this->m_blue = m_blue;
        this->m_alpha = m_alpha;
    }

    void print() {
        cout
        << to_string(m_red) << " "
        << to_string(m_green) << " "
        << to_string(m_blue) << " "
        << to_string(m_alpha) <<
        endl;
    }
};


// Task 3

class Stack {
    int stackLength = 0;
    int stackArray[10];
    int maxLength = 10;

public:
    void reset() {
        for (int i = 0; i < maxLength; i++) {
            stackArray[i] = 0;
        }
        stackLength = 0;
    }

    bool push(int n) {
        if(stackLength == maxLength){
            return false;
        }

        stackArray[stackLength] = n;
        stackLength++;

        return true;
    }

    string pop() {
        string removedEl;

        removedEl = to_string(stackArray[stackLength]);
        stackArray[stackLength] = 0;
        stackLength--;

        return removedEl;
    }

    void print() {
        for (int i = 0; i < stackLength; i++) {
            cout << stackArray[i] << " ";
        }
        cout << endl;
    }

};


int main() {

    // Task 1
    Power pw;

    pw.calculate();

    pw.set(3, 3);
    pw.calculate();

    // Task 2
    RGBA pixel(22, 231, 26, 28);

    pixel.print();

    // Task 3
    Stack stack;

    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return 0;
}
