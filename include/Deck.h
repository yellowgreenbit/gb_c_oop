#ifndef GB_C_OOP_DECK_H
#define GB_C_OOP_DECK_H

#include <algorithm>
#include <random>
#include "Hand.h"
#include "GenericPlayer.h"

class Deck /* : public Hand */{
public:
    std::vector<Card *> cards;
    Deck();
    virtual ~Deck();
    void generate();
    void clear(std::vector<Card *>& cards);
    void shuffle();
    void deal (Hand& hand);
    void addCards (GenericPlayer& player);
};



#endif //GB_C_OOP_DECK_H
