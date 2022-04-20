#include "../include/Player.h"

Player::Player(const std::string& name) : GenericPlayer(name) {};
Player::~Player() = default;

bool Player::needMore() const {
    std::cout << name << ", do you whant a hit (y/n)? ";
    char response;

    std::cin >> response;

    return (response == 'y');

};
void Player::win() const {
    std::cout << name << " WIN" << std::endl;
};

void Player::lose() const {
    std::cout << name << " LOSE" << std::endl;
};

void Player::draw() const {
    std::cout << name << " DRAW" << std::endl;
};