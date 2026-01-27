#include "miruka.hpp"
#include <iostream>



Miruka::Miruka(int id) :Perso(id){
    
    nom="Miruka";
    
    speed.x=0;
    speed.y=0;
    in_air=true;
    crouch=false;
    ground_speed=5;
    air_speedmax=4;
    air_acceleration=0.5;
    jump_height=10;
    pourcentage=0;
    
    if(!T.loadFromFile("../miruka.jpg"))
        std::cout<<"erreur"<<std::endl;
    Sprite.setTexture(T);
    Sprite.setScale(0.1,0.1);
    Sprite.setPosition(100,50);
    hitbox_perso.left = Sprite.getPosition().x;
    hitbox_perso.top = Sprite.getPosition().y;
    hitbox_perso.width = T.getSize().x*Sprite.getScale().x;
    hitbox_perso.height = T.getSize().y*Sprite.getScale().y;
    
    
}

void Miruka::is_crouching()
{
    if (crouch)
    {
        Sprite.setScale(0.13,0.05);
    }
    else
    {
        
        Sprite.setScale(0.1,0.1);
    }
    
}

void Miruka::Jab() {
    int dir;
    if(direction==1)
        dir=30;
    else
        dir=-30;
    {
        sf::FloatRect jabHitbox(dir,0,20,20);
        Hitbox jab;
        jab.hitbox=jabHitbox;
        jab.duration=5;
        jab.damage=5;
        jab.puissance_ejec=0.2;
        jab.direction=sf::Vector2f(2.5*direction,-1.5);
        Hitboxs_attaque.push(jab);
        // Hitbox lent;
        // lent.duration=0;
        // Hitboxs_attaque.push(lent);
        // speed.x=0;
        // speed.y=0;
    }

}
void Miruka::Ftilt() {
    int dir;
    if(direction==1)
        dir=30;
    else
        dir=-48;
    {
        sf::FloatRect coupHitbox(dir,0,40,15);
        Hitbox coup;
        coup.hitbox=coupHitbox;
        coup.duration=1;
        coup.damage=10;
        coup.puissance_ejec=0.3;
        coup.direction=sf::Vector2f(2.5*direction,-1.5);
        Hitboxs_attaque.push(coup);
        Hitbox lent;
        lent.duration=15;
        Hitboxs_attaque.push(lent);
        
        speed.x=0;
        speed.y=0;
    }
}
void Miruka::Utilt() {
    {
        sf::FloatRect coupHitbox(-10,-20,40,15);
        Hitbox coup;
        coup.hitbox=coupHitbox;
        coup.duration=5;
        coup.damage=5;
        coup.puissance_ejec=0.2;
        

        coup.direction=sf::Vector2f(0,-1);
        Hitboxs_attaque.push(coup);
        Hitbox lent;
        lent.duration=10;
        Hitboxs_attaque.push(lent);
        speed.x=0;
        speed.y=0;
    }
}
void Miruka::Dtilt() {
    int dir;
    if(direction==1)
        dir=30;
    else
        dir=-25;
    {
        sf::FloatRect coupHitbox(dir,15,15,10);
        Hitbox coup;
        coup.hitbox=coupHitbox;
        coup.duration=1;
        coup.damage=2;
        coup.puissance_ejec=0.1;
        coup.direction=sf::Vector2f(0,-1);
        Hitboxs_attaque.push(coup);
        coup.hitbox.height=20;
        coup.hitbox.top=5;
        Hitboxs_attaque.push(coup);
        coup.hitbox.height=30;
        coup.hitbox.top=-5;
        Hitboxs_attaque.push(coup);
        coup.hitbox.height=40;
        coup.damage=15;
        coup.puissance_ejec=0.3;
        coup.hitbox.top=-15;
        Hitboxs_attaque.push(coup);
    
        
        
        Hitbox lent;
        lent.duration=20;
        Hitboxs_attaque.push(lent);
        speed.x=0;
        speed.y=0;
    }
}
void Miruka::Fair() {
    int dir;
    if(direction==1)
        dir=30;
    else
        dir=-25;
    {
        sf::FloatRect coupHitbox(dir,-15,15,30);
        Hitbox coup;
        coup.hitbox=coupHitbox;
        coup.duration=1;
        coup.damage=8;
        coup.puissance_ejec=0.2;
        coup.direction=sf::Vector2f(1*direction,-2);
        Hitboxs_attaque.push(coup);
        Hitbox lent;
        lent.duration=5;
        Hitboxs_attaque.push(lent);
    }
}
void Miruka::Bair() {
    int dir;
    if(direction==1)
        dir=30;
    else
        dir=-25;
    
    {
        sf::FloatRect coupHitbox(-dir,0,15,40);
        Hitbox coup;
        coup.hitbox=coupHitbox;
        coup.duration=1;
        coup.damage=15;
        coup.puissance_ejec=0.4;
        coup.direction=sf::Vector2f(-direction,-2);
        Hitboxs_attaque.push(coup);
        Hitbox lent;
        lent.duration=8;
        Hitboxs_attaque.push(lent);
    }
}
void Miruka::Nair() {
    int dir;
    if(direction==1)
        dir=30;
    else
        dir=-25;
    
        for (size_t i = 0; i < 15; i++)
        {
            sf::FloatRect coupHitbox(-12,-12,45,45);
            Hitbox coup;
            coup.hitbox=coupHitbox;
            coup.duration=1;
            coup.damage=2;
            coup.puissance_ejec=0.2;
            coup.direction=sf::Vector2f(speed.x,-1.25);
            Hitboxs_attaque.push(coup);
        }
        Hitboxs_attaque.back().puissance_ejec=0.6;
        
        
        Hitbox lent;
        lent.duration=15;
        Hitboxs_attaque.push(lent);
    
}
void Miruka::Upair() {
    {
        sf::FloatRect coupHitbox(5,-20,20,15);
        Hitbox coup;
        coup.hitbox=coupHitbox;
        coup.duration=1;
        coup.damage=12;
        coup.puissance_ejec=0.3;
        coup.direction=sf::Vector2f(0,-1);
        Hitboxs_attaque.push(coup);
        Hitbox lent;
        lent.duration=10;
        Hitboxs_attaque.push(lent);
    }
}
void Miruka::Dair() {
    {
        for (size_t i = 0; i < 10; i++)
        {
            sf::FloatRect coupHitbox(5,30,15,25);
            Hitbox coup;
            coup.hitbox=coupHitbox;
            coup.damage=15;
            coup.duration=1;
            coup.puissance_ejec=0.3;
            coup.direction=sf::Vector2f(0,1);
            Hitboxs_attaque.push(coup);
            speed.y=10;
        }
        
        
        
        
        Hitbox lent;
        lent.duration=10;
        Hitboxs_attaque.push(lent);
    }
}

void Miruka::NeutralB(std::vector<Arrow> &Arrows,sf::Texture &T)
{
    Arrow fleche(T);
    fleche.sprite.setPosition(direction*30+Sprite.getPosition().x,Sprite.getPosition().y-10);
    fleche.sprite.setScale(0.5,0.5);
    fleche.belonging=ID;
    Arrows.push_back(fleche);
    Hitbox lent;
    lent.duration=10;
    Hitboxs_attaque.push(lent);
}