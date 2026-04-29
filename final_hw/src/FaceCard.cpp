#include "FaceCard.h"

#include <ostream>

FaceCard::FaceCard(std::string suit, int rank)
    : PlayingCard(std::move(suit), rank) {}

void FaceCard::print(std::ostream& os) const {
    switch (rank_) {
        case 11:
            os << "Jack";
            break;
        case 12:
            os << "Queen";
            break;
        case 13:
            os << "King";
            break;
        default:
            os << PlayingCard::rankToString(rank_);
            break;
    }
    os << " of " << suit_;
}
