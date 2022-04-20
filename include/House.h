#ifndef GB_C_OOP_HOUSE_H
#define GB_C_OOP_HOUSE_H

#include "GenericPlayer.h"

class House : public GenericPlayer {
public:
    House(const std::string& name = "House");
    virtual ~House();
    virtual bool needMore() const;
    void flipTopCard();
};

#endif //GB_C_OOP_HOUSE_H
