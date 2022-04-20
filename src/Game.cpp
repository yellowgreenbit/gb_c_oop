#include "../include/Game.h"

Game::Game(const std::vector<std::string>& names) {
    for (const std::string &name : names) {
        Player p(name);
        players.push_back(p);
    }
};
Game::~Game() = default;

void Game::play() {
    std::vector<Player>::iterator pPlayer;

    for (pPlayer = players.begin(); pPlayer != players.end(); ++pPlayer) {
        deck.deal(*pPlayer);
        deck.deal(*pPlayer);
    }

    deck.deal(house);
    deck.deal(house);
    house.flipTopCard();

    for (pPlayer = players.begin(); pPlayer != players.end(); ++pPlayer) {
        std::cout << *pPlayer << std::endl;
    }
    std::cout << house << std::endl;

    for (pPlayer = players.begin(); pPlayer != players.end(); ++pPlayer) {
        deck.addCards(*pPlayer);
    }
    house.flipTopCard();
    std::cout << house << std::endl;
    deck.addCards(house);

    if (house.isOverburdened()) {
        // все, кто остался в игре, побеждают
        for (pPlayer = players.begin(); pPlayer != players.end(); ++pPlayer)
            if (!(pPlayer->isOverburdened()))
                std::cout << std::endl;
                pPlayer->win();
    } else {
        // сравнивает суммы очков всех оставшихся игроков с суммой очков дилера
        for (pPlayer = players.begin(); pPlayer != players.end(); ++pPlayer) {
            if (!(pPlayer->isOverburdened())) {
                if (pPlayer->getPoints() > house.getPoints()) {
                    pPlayer->win();
                } else if (pPlayer->getPoints() < house.getPoints()) {
                    pPlayer->lose();
                } else {
                    pPlayer->draw();
                }
            }
        }
    }
    for (pPlayer = players.begin(); pPlayer != players.end(); ++pPlayer) {
        pPlayer->clear();
    }
    house.clear();
};