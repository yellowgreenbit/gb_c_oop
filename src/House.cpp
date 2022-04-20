#include "../include/House.h"

House::House(const std::string& name) : GenericPlayer(name) {};
House::~House() = default;
bool House::needMore() const {
    return (getPoints() <= 16);
};
void House::flipTopCard(){
    if (!(cards.empty())) {
        cards[0]->flip();
    } else {
        std::cout << "no cards" << std::endl;
    }
};