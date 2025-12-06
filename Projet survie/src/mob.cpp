#include"mob.h"
//fait spawn un zombie aléatoirement autour du joueur

void zombie_spawn(std::vector<Mob> &zombies,Perso joueur,int ID)
{
    Mob zombie;
    zombie.ID=ID;
    int pif =rand()%1000;
    if (ID==0)
    {
        zombie.x=joueur.x+cos(pif)*200;
        zombie.y=joueur.y+sin(pif)*200;
    }
    else
    {
        zombie.x=joueur.x+cos(pif)*400;
        zombie.y=joueur.y+sin(pif)*400;
    }
    if(ID==0)
    {
        zombie.hp=20;
        zombie.v=1;
    }
    else{
        zombie.hp=50;
        zombie.v=0.5;
    }
    zombie.hitbox.setSize(sf::Vector2f(7,25));
    zombie.hitbox.setPosition(zombie.x-13,zombie.y-18);
    zombies.push_back(zombie);
}
void CheckMobSpawn(std::vector<Mob> mobs,Perso joueur,sf::Clock ZombieSpawnClock,sf::Clock sorcièreSpawnClock,int spawn_rate)
{
    if (ZombieSpawnClock.getElapsedTime().asMilliseconds()>spawn_rate)
        {
            ZombieSpawnClock.restart();
            zombie_spawn(mobs,joueur,0);
        }
    if (sorcièreSpawnClock.getElapsedTime().asMilliseconds()>spawn_rate)
        {
            sorcièreSpawnClock.restart();
            zombie_spawn(mobs,joueur,1);
        }
    
}
//s'occupe d'accompagner un zombie
void zombie_accompagnement(Mob &zombie,Perso joueur)
{
    float dx,dy,distance;
    dx = joueur.x - zombie.x;
    dy =  joueur.y- zombie.y;
    distance = sqrt(dx*dx + dy*dy);

    zombie.vx = zombie.v * dx / distance;
    zombie.vy = zombie.v * dy / distance;
    zombie.x+=zombie.vx;
    zombie.y+=zombie.vy;
    zombie.hitbox.setPosition(zombie.x-3,zombie.y-10);
}
void sorcière_accompagnement(Mob &sorcière,Perso joueur,sf::Clock & Shoot_witch_clock,std::vector<Bullet> &balles)
{
    float dx,dy,distance;
    dx = joueur.x - sorcière.x;
    dy =  joueur.y- sorcière.y;
    distance = sqrt(dx*dx + dy*dy);
    Bullet balle;
    if (distance<200 and Shoot_witch_clock.getElapsedTime().asSeconds()>5)
    {
        balle_sorcière(balle,joueur);
        balle.x=sorcière.x;
        balle.y=sorcière.y;
        balle.count=0;
        balle.v=3;
        balles.push_back(balle);
        sorcière.vx=0;
        sorcière.vy=0;
    }
    else
    {
        sorcière.vx = sorcière.v * dx / distance;
        sorcière.vy = sorcière.v * dy / distance;
    }
}
void update_position_collisions(std::vector<Bullet> &bullets,std::vector<Zombie>&zombies,Perso &joueur,sf::Clock &InvicibleClock,weapon arme )
{

    int i=0;
    
    for ( Zombie &zombie:zombies)
    {
        zombie_accompagnement(zombie,joueur);
    }
    
    while (i<bullets.size())
    {   balle_accompagnement(bullets[i]);
        int j=0;
        bool bullet_destroyed=false;
        bool zombie_destroyed=false;
        while (j<zombies.size() and not bullet_destroyed)
        {
            if(bullets[i].hitbox.getGlobalBounds().intersects(zombies[j].hitbox.getGlobalBounds()))
            {
                
                bullets.erase(bullets.begin()+i);
                bullet_destroyed=true;
                zombies[j].hp=zombies[j].hp-arme.dégats;
                if (zombies[j].hp<=0)
                {
                    zombies.erase(zombies.begin()+j);
                }
                
            }
            if (not zombie_destroyed)
            { 
                ++j;
            }

            
                
        }
        if (not bullet_destroyed and bullets[i].count>200)
        {
            bullets.erase(bullets.begin()+i);
            bullet_destroyed=true;
        } 
        if (not bullet_destroyed)
        {
            ++i;
        }
    }
    if(not joueur.invincible)
    {
        bool joueur_touché=false;
        for (int j = 0; j < zombies.size(); j++)
        {
            if(joueur.hitbox.getGlobalBounds().intersects(zombies[j].hitbox.getGlobalBounds()) and not joueur_touché)
                {   std::cout<<"collision detectee"<<j<<std::endl;
                    joueur.hp=joueur.hp-5;
                    joueur.invincible=true;
                    joueur_touché=true;
                    InvicibleClock.restart();   
                }
        }
    }
}
