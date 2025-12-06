#include"Calcules.h"
struct Mob{
    float x,y,v;
    float vx,vy;
    sf::Texture image;
    float hp;
    sf::RectangleShape hitbox;
    int ID;
};
void update_position_collisions(std::vector<Bullet> &bullets,std::vector<Mob>&zombies,Perso &joueur,sf::Clock &InvicibleClock,weapon arme );
void zombie_spawn(std::vector<Mob> &zombies,Perso joueur,int ID);
void zombie_accompagnement(Mob &zombie,Perso joueur);
