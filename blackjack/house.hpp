#pragma once

class House : public Generic_Player {
public:
    House(const string& name = "House");
    virtual ~House();
    virtual bool Is_Hitting() const;
    void Flip_First_Card();
};