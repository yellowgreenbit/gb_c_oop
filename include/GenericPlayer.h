#ifndef GB_C_OOP_GENERICPLAYER_H
#define GB_C_OOP_GENERICPLAYER_H

#include <iostream>
#include "Hand.h"

class GenericPlayer : public Hand {
    friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);
protected:
    std::string name;
    GenericPlayer(const std::string& _name); // make it abstract, only children can instantiate
public:
    virtual ~GenericPlayer();
    virtual bool needMore() const = 0;
    bool isOverburdened() const;
    void bust() const;
};


#endif
