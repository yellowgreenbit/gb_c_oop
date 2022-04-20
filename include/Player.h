#ifndef GB_C_OOP_PLAYER_H
#define GB_C_OOP_PLAYER_H

#include "GenericPlayer.h"

class Player : public GenericPlayer {
public:
    Player(const std::string& _name = "");
    virtual ~Player();
    virtual bool needMore() const;
    void win() const;
    void lose() const;
    void draw() const;
};


#endif //GB_C_OOP_PLAYER_H
