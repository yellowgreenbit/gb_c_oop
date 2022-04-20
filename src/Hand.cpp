#include "../include/Hand.h"

Hand::Hand() {};
Hand::~Hand() {
    clear();
};

void Hand::add(Card* card) {
    cards.push_back(card);
};

void Hand::clear() {
    for (auto it = cards.begin(); it != cards.end(); ++it) {
        delete *it;
    }
};

int Hand::getPoints() const {
    int result = 0;
    int aces = 0;
    for (int i = 0; i < cards.size(); ++i) {
        int value = cards[i]->getValue();

        if (value == Card::ECardValue::ACE){
            ++aces;
        }

        result += value;
    }
    while (aces > 0 && result <= 11){
        result += 10;
        --aces;
    }
    return result;
};