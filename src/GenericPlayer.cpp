#include "../include/GenericPlayer.h"

GenericPlayer::GenericPlayer(const std::string& _name) : name(_name) {

}; // make it abstract, only children can instantiate

GenericPlayer::~GenericPlayer() = default;

bool GenericPlayer::isOverburdened() const {
    return getPoints() > 21;
};

void GenericPlayer::bust() const {
    if (isOverburdened()) {
        std::cout << name << " busted";
    }
};

std::ostream& operator<<(std::ostream& os, const GenericPlayer& player) {
    os << player.name << ": ";

    if(!player.cards.empty()) {
        for (auto pCard = player.cards.begin(); pCard != player.cards.end(); ++pCard) {
            os << * (*pCard) << " ";
        }
    } else {
        os << "no cards";
    }

    return os;
}