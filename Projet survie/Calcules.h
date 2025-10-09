#include "SFML/Graphics.hpp"
#include <cmath>
#include <iostream>
struct objet{
    float x, y;
    sf::Texture image;
};
struct Perso{
    int faim;
    float x, y,v;
    sf::Texture image;
    float hp;
    sf::RectangleShape hitbox;
    bool invincible;
    
};
struct Bullet{
    float x,y,v;
    float vx,vy;
    sf::Texture image;
    bool on_screen;
    int count;
    sf::RectangleShape hitbox;
};
struct Zombie{
    float x,y,v;
    float vx,vy;
    sf::Texture image;
    float hp;
    sf::RectangleShape hitbox;
};
struct cercle_faim{
    int taille;
    sf::RectangleShape* pixels;
};
sf::RectangleShape* get_cercle_faim(objet feu, int taille_cercle,sf::RenderWindow &window);
void zombie_spawn(std::vector<Zombie> &zombies,Perso joueur);
void zombie_accompagnement(Zombie &zombie,Perso joueur);
void get_balle(int x_joueur, int y_joueur,int x_souris,int y_souris,std::vector<Bullet> &balles,sf::View &camera,sf::RenderWindow &window);
void balle_accompagnement(Bullet &balle);
void update_position_collisions(std::vector<Bullet> &bullets,std::vector<Zombie>&zombies,Perso &joueur,sf::Clock &InvicibleClock );
sf::RectangleShape get_indicator_fire(objet feu,sf::RenderWindow &window,sf::View &camera);
