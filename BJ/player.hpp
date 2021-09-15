#pragma once

class Player : public Generic_Player {
public:
    Player(const std::string &name = "");
    ~Player();
    virtual bool Is_Hitting() const;
    void Win() const;
    void Lose() const;
    void Push() const;
};