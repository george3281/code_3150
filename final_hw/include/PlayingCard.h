#pragma once

#include "Card.h"
#include <ostream>
#include <string>

class PlayingCard : public Card {
protected:
    std::string suit_;
    int rank_;

    static std::string rankToString(int rank);

public:
    PlayingCard(std::string suit, int rank);

    int value() const override;
    void print(std::ostream& os) const override;
};
