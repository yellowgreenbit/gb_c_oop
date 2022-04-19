#include <iostream>
#include <string>
#include <vector>

using namespace std;


// Task 1

void inputNum() {
    string buf;
    bool correctNum = false;

    while( !correctNum ) {
        cout << "Please, print int " << endl;
        cin >> buf;

        for (int i = 0; i < buf.length(); i++) {
            if(!isdigit(buf[i])){
                cin.clear();
                cin.sync();
                cout << "Error: invalid argument(s)" << endl;
                correctNum = false;
                break;
            };
            correctNum = true;
        }
        if(correctNum) {
            cout << "Success, number is " << buf << endl;
            break;
        }
    }
}


// Task 2

ostream &endll(ostream &stream)
{
    stream << "\n\n";
    return stream.flush();
}


// Task 3, 4, 5

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

    virtual void flip() {
        isCoverUp = !isCoverUp;
    }

    bool getCoverUp() const {
        return isCoverUp;
    }

    ECardSuit getSuit() const {
        return suit;
    }

    ECardValue getValue(bool soft = true) const {
        if (soft && (value == ECardValue::ACE)){
            return ECardValue::ACE_SOFT;
        }
        return value;
    }

    friend ostream& operator<< (ostream &out, const Card &card);
};

ostream& operator<< (ostream &out, const Card &card) {
    if(card.getCoverUp()){
        out << "XX" << "\n";
    } else {
        out << "Suit " << card.getSuit() << ", value " << card.getValue() << "\n";
    }
    return out;
}

class Hand {
    vector<Card*> cardCollection;
public:
    void add(Card &card) {
        cardCollection.push_back(&card);
    }
    virtual Card* get(int index) const {
        return cardCollection[index];
    }
    int getCount() const {
        return cardCollection.size();
    }
    void clear() {
        for (int i = 0; i < cardCollection.size(); i++) {
            delete [] cardCollection[i];
        }
        cardCollection.clear();
    }
    int calcSum(bool soft) {
        int sumValues{0};
        vector<Card*>::iterator cardIter;

        cardIter = cardCollection.begin();

        while (cardIter != cardCollection.end()) {

            if ( !(*cardIter)->getCoverUp() ){
                sumValues += (*cardIter)->getValue(soft);
            }
            ++cardIter;
        }
        return sumValues;
    }
    virtual int getValue() {
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

    virtual string getName() const {
        return this->name;
    }

    virtual bool isHitting() = 0;

    virtual bool isBoosted() {
        return (getValue() > 21);
    };

    virtual void bust(){
        if(isBoosted()) {
            cout << "Player " << getName() << " is boosted, " << "count = " << getValue() << endl;
        } else {
            cout << "Player " << getName() << " is NOT boosted, " << "count = " << getValue() << endl;
        }

    };

    friend ostream& operator<< (ostream &out, GenericPlayer &gp);

    virtual ~GenericPlayer(){ }
};

ostream& operator<< (ostream &out, GenericPlayer &gp) {
    out << "Name: " << gp.getName() << ", sum value: "<< gp.getValue() << "\n";

    for (int i = 0; i < gp.getCount(); i++) {
        out << *gp.get(i) << "\n";
    }
    return out;
}

class Player : public GenericPlayer {
public:
    Player(string _name) : GenericPlayer(_name){
    };
    virtual ~Player(){ };

    virtual bool isHitting() override {
        char answer;
        cout << "Add card? (y/n) " << endl;
        cin >> answer;
        return (answer == 'y');
    }

    void Win() const {
        cout << "Player " << getName() << " WIN!" << endl;
    }

    void Lose() const {
        cout << "Player " << getName() << " LOSE!" << endl;
    }

    void Push() const {
        cout << "Player " << getName() << " PUSH!" << endl;
    }
};

class House : public GenericPlayer {
public:
    House(string _name) : GenericPlayer(_name){
    };
    virtual ~House(){ };

    //isHitting - can't be const -> getValue -> calcSum function has changable members
    virtual bool isHitting() {
        return (getValue() < 16);
    }

    void flipFirstCard() {
        get(0)->flip();
    }
};

int main() {

    // Task 1
    inputNum();

    // Task 2
    cout << "begin" << endll;
    cout << "end" << endl;

    // Task 3, 4, 5

    Player Bob("Bob");

    Bob.isHitting();
    Bob.Win();

    Card card1(HEARTS, TEN);
    House Dealer("Dealer");

    Dealer.add(card1);
    Dealer.flipFirstCard();

    cout << card1;
    cout << Dealer;

    return 0;
}
