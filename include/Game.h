#ifndef GB_C_OOP_GAME_H
#define GB_C_OOP_GAME_H

#include <vector>
#include "Deck.h"
#include "House.h"
#include "Player.h"

class Game {
    Deck deck;
    House house;
    std::vector<Player> players;
public:
    static constexpr int points_to_win = 21;
    Game(const std::vector<std::string>& names);
    virtual ~Game();

    void play();
};


#endif //GB_C_OOP_GAME_H
