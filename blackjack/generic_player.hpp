#pragma once

class Generic_Player : public Hand {
protected:
    std::string m_name;
public:
    Generic_Player(const std::string& name = "");
    virtual ~Generic_Player();
    virtual bool Is_Hitting() const = 0;
    bool Is_Busted() const;
    void Bust() const;
    friend std::ostream& operator<< (std::ostream &out, const Generic_Player &player);
};