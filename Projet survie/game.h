#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Calcules.h"



struct weapon{
    float dégats;
    float tear_rate;
    int id;

};

void jeu(Perso joueur,sf::RenderWindow &window);