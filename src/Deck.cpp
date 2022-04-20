#include "../include/Deck.h"

using Suit = Card::ECardSuit;
using Value = Card::ECardValue;

Deck::Deck() {
    generate();
};

Deck::~Deck() {
    clear(cards);
};

void Deck::clear(std::vector<Card *>& cards) {
    for (auto it = cards.begin(); it != cards.end(); ++it) {
        delete *it;
    }
};

void Deck::generate() {
    clear(cards);
    for (int suit = Suit::SPADES; suit <= Suit::HEARTS; ++suit) {
        for (int value = Value::ACE; value <= Value ::KING; ++value) {
            cards.push_back(new Card(static_cast<Suit>(suit), static_cast<Value>(value)));
        }
    }
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
};

void Deck::deal(Hand& hand) {
    if(!cards.empty()) {
        hand.add(cards.back());
        cards.pop_back();
    } else {
        std::cout << "Out of cards. Cannot deal!";
    }
};

void Deck::addCards(GenericPlayer& player) {
    std::cout << std::endl;
    while (!(player.isOverburdened()) && player.needMore()){
        deal(player);

        std::cout << player << std::endl;

        if (player.isOverburdened()) {
            player.bust();
        }
    }
};