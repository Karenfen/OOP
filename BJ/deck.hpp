#pragma once

class Deck : public Hand {
public:
    Deck();
    void Populate();
    void Shuffle();
    void Deal (Hand& aHand);
    void Addltional_Cards (Generic_Player& a_Generlc_Player);
    virtual ~Deck();
};