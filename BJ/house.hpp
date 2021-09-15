#pragma once
#include <string>

class House : public Generic_Player {
public:
    House(const std::string& name = "House");
    ~House();
    virtual bool Is_Hitting() const;
    void Flip_First_Card();
};
