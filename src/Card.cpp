#include "../include/Card.h"

Card::Card(ECardSuit _suit, ECardValue _value)
    : suit{_suit}, value(_value), isCoverUp(false) {

}

Card::~Card() = default;

void Card::flip() {
    isCoverUp = !isCoverUp;
}

int Card::getValue() const {
    return (!isCoverUp) ? static_cast<unsigned>(value) : 0;
}

std::ostream& operator<<(std::ostream& os, const Card& aCard) {
    const std::string RANKS[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    const std::string SUITS[] = {"s", "c", "d", "h"};

    if (!aCard.isCoverUp) {
        os << RANKS[aCard.value] << SUITS[aCard.suit];
    } else {
        os << "XX";
    }
    return os;
}