#pragma once

#include "PlayingCard.h"
#include <ostream>

class FaceCard : public PlayingCard {
public:
    FaceCard(std::string suit, int rank);

    void print(std::ostream& os) const override;
};
