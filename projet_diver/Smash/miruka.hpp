#pragma once
#include "Perso.hpp"
#include <SFML/Graphics.hpp>

class Miruka : public Perso {
public:
    Miruka(int id);

    void Jab() override;
    void Ftilt() override;
    void Utilt() override;
    void Dtilt() override;
    void Fair() override;
    void Bair() override;
    void Nair() override;
    void Upair() override;
    void Dair() override;

    void is_crouching() ;

};
