#include <iostream>
#include <vector>

using namespace std;

// Task 1
template <class T>
class Pair1{
private:
    T *data;
public:
    Pair1(T _first, T _second) {
        this->data = new T(2);

        this->data[0] = _first;
        this->data[1] = _second;
    }

    T getFirst () const {
        return data[0];
    }

    T getSecond () const {
        return data[1];
    }

    ~Pair1() {
        delete [] data;
        data = nullptr;
    }
};


// Task 2

template <class T>
class Pair{
private:
    T first;
    T second;
public:
    Pair(T _first, T _second) : first(_first), second(_second) { }

    T getFirst () const {
        return first;
    }

    T getSecond () const {
        return second;
    }

    ~Pair() { }
};


// Task 3
template <class T>
class Pair{
private:
    string first;
    T second;
public:
    Pair(){}
    Pair(string _first, T _second) : first(_first), second(_second) { }

    string getFirst () const {
        return first;
    }

    T getSecond () const {
        return second;
    }

    virtual ~Pair() { }
};

template <class T>
class StringValuePair : public Pair<int>{
    string first;
    T second;
public:
    StringValuePair(string _first, T _second) : Pair<int>(_first, _second) { }
};


// Task 4

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

    bool getCoverUp() const {
        return isCoverUp;
    }

    ECardValue getValue(bool soft = true) const {
        if (soft && (value == ECardValue::ACE)){
            return ECardValue::ACE_SOFT;
        }
        return value;
    }
};

class Hand {
    vector<Card> cardCollection;
public:
    void add(Card card) {
        cardCollection.push_back(card);
    }
    void clear() {
        cardCollection.clear();
    }
    int calcSum(bool soft) {
        int sumValues{0};
        vector<Card>::iterator cardIter;

        cardIter = cardCollection.begin();

        while (cardIter != cardCollection.end()) {
            if (!cardIter->getCoverUp()){
                sumValues += cardIter->getValue(soft);
            }
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

class GenericPlayer : public Hand {
private:
    string name;
public:
    GenericPlayer(string _name) : name(_name){ }

    virtual bool isHitting() = 0;

    virtual bool isBoosted() {
        return (getValue() > 21);
    };

    virtual void bust(){
        if(isBoosted()) {
            cout << "Player " << name << " is boosted, " << "count = " << getValue() << endl;
        } else {
            cout << "Player " << name << " is NOT boosted, " << "count = " << getValue() << endl;
        }

    };

    virtual ~GenericPlayer(){ }
};

class Player : public GenericPlayer {
public:
    Player(string _name) : GenericPlayer(_name){
    };
    virtual ~Player(){ };
    bool isHitting() override {
        return false;
    }
};

class House : public GenericPlayer {
public:
    House(string _name) : GenericPlayer(_name){
    };
    virtual ~House(){ };
    bool isHitting() override {
        return false;
    }
};

int main()
{

// Task 1
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.getFirst() << ' ' << p1.getSecond() << '\n';

// Task 1
    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.getFirst() << ' ' << p2.getSecond() << '\n';

    const Pair<double> p3(3, 7.8);
    cout << "Pair: " << p3.getFirst() << ' ' << p3.getSecond() << '\n';

// Task 3
    StringValuePair<int> svp("Amazing", 7);
    cout << "Pair: " << svp.getFirst() << ' ' << svp.getSecond() << '\n';


// Task 4

    Player player1("Petr");

    Card card1(DIAMONDS, FOUR);
    card1.flip();
    player1.add(card1);

    Card card2(HEARTS, TEN);
    card2.flip();
    player1.add(card2);

    Card card3(HEARTS, NINE);
    card3.flip();
    player1.add(card3);

    Card card4(HEARTS, ACE);
    card4.flip();
    player1.add(card4);

    player1.bust();

    return 0;
}
