#include <iostream>
#include <cassert>
#include <vector>


// Task 1

class Container {
    int* data;
    int size;
    int capacity;
    int& operator[](int idx) {
        return data[idx];
    }

public:
    Container(): size(0), data(nullptr), capacity(0) { }
    Container( int _size) : size(_size) {
        if (_size == 0){
            Container();
        } else if (_size < 0) {
            std::cout << "Bad thing" << std::endl;
        } else {
            data = new int[_size];
            capacity = 0;
        }
    }

    virtual ~Container() {
        delete[] data;
    }

    void setData(int idx, int value) {
        assert(idx >=0 && idx < size);
        capacity++;
        this->data[idx] = value;
    }

    int getData(int idx) {
        assert(idx >=0 && idx < size);
        //capacity--;
        return this->data[idx];
    }

    int getCapacity() {
        return this->capacity;
    }

    int getSize() {
        return this->size;
    }

    void split(int from, int to) {
        if (from < 0 || from > to || from >= size) {
            from = 0;
        }

        if (to <= from || to < 0 || to > size) {
            to = (to > size) ? to : size;
        }

        int elemToCopy = size - from;
        int arraySize = to - from;

        int* newData = new int[arraySize]{0};

        if (size > 0) {
            for (int idx = 0; idx < elemToCopy; idx++) {
                newData[idx] = data[idx + from];
            }
        }

        delete[] data;
        data = newData;
        size = arraySize;
    }

    void resize(int newLength) {
        split(0, newLength);
    }

    void erase() {
        capacity = 0;
        for (int idx = 0; idx < size; idx++) {
            data[idx] = 0;
        }
    }

    int pop_back() {
        split(0, size - 1);
        return data[size];
    }

    int pop_front() {
        split(1, size);
        return data[0];
    }

    void print() {
        for (int idx = 0; idx < size; idx++) {
            std::cout << data[idx] << " ";
        }
        std::cout << "\n";
    }

    void sort() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if(data[i] < data[j]){
                    int temp = data[j];
                    data[j] = data[i];
                    data[i] = temp;
                }
            }
        }
    }
};

// Task 2 in block main

// Task 3

enum ECardSuit { SPADES, CLUBS, DIAMONDS, HEARTS };
enum ECardValue {
    ACE   = 1,
    TWO   = 2,
    THREE = 3,
    FOUR  = 4,
    FIVE  = 5,
    SIX   = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE  = 9,
    TEN   = 10,
    JACK  = 10,
    QUEEN = 10,
    KING  = 10,
    ACE_SOFT = 11
};

class Card {
    ECardSuit suit;
    ECardValue value;
    bool isCoverUp;
public:
    Card(ECardSuit _suit, ECardValue _value) : suit(_suit), value(_value) {
        isCoverUp = true;
    }

    void flip() {
        isCoverUp = !isCoverUp;
    }
    ECardValue getValue(bool soft = true) const {
        if (soft && (value == ECardValue::ACE)){
            return ECardValue::ACE_SOFT;
        }
        return value;
    }
};

class Hand {
    std::vector<Card> cardCollection;
public:
    void add(Card card) {
        cardCollection.push_back(card);
    }
    void clear() {
        cardCollection.clear();
    }
    int calcSum(bool soft) {
        int sumValues{0};
        std::vector<Card>::iterator cardIter;

        cardIter = cardCollection.begin();

        while (cardIter != cardCollection.end()) {
            sumValues += cardIter->getValue(soft);
            ++cardIter;
        }
        return sumValues;
    }
    int getValue() {
        int sum = calcSum(true);
        if (sum <= 21){
            return sum;
        } else {
            return calcSum(false);
        }
    }
};

int main() {

    // Task 1

    Container c0(4);
    c0.erase();

    c0.setData(0, 10);
    c0.setData(1, 2);
    c0.setData(2, 33);
    c0.setData(3, 4);

    std::cout << c0.getData(0) << std::endl;
    std::cout << c0.getSize() << std::endl;

    c0.resize(3);

    std::cout << c0.getSize() << std::endl;
    std::cout << c0.getCapacity() << std::endl;

    c0.pop_back();
    c0.pop_front();

    c0.sort();

    c0.print();

    // Task 2

    std::vector<int> arr = {1, 2, 3, 2, 4, 3, 5, 1, 7, 11, 3, 2};
    std::vector<int> uniqueArr;

    std::vector<int>::iterator arrIter;
    std::vector<int>::iterator uniqueArrIter;

    arrIter = arr.begin();

    while (arrIter != arr.end()) {
        bool unique = true;
        uniqueArrIter = uniqueArr.begin();

        while (uniqueArrIter != uniqueArr.end()) {
            if(*arrIter == *uniqueArrIter) {
                unique = false;
                break;
            }
            ++uniqueArrIter;
        }

        if (unique){
            uniqueArr.push_back(*arrIter);
        }
        ++arrIter;
    }

    for (int i = 0; i < uniqueArr.size(); i++) {
        std::cout << uniqueArr[i] << " ";
    }

    // Task 3

    Hand hand;

    Card card0(SPADES, ACE);
    Card card1(SPADES, KING);
    Card card2(SPADES, TEN);

    hand.add(card0);
    hand.add(card1);
    hand.add(card2);

    std::cout << hand.getValue() << std::endl;

    hand.clear();
    std::cout << hand.getValue() << std::endl;
    return 0;
}