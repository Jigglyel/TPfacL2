#include "itsuyo.hpp"
#include<iostream>

Itsuyo::Itsuyo()
{
    nom="Itsuyo";
    
    speed.x=0;
    speed.y=0;
    in_air=true;
    crouch=false;
    ground_speed=5;
    air_speedmax=4;
    air_acceleration=0.5;
    jump_height=11;
    pourcentage=0;
    
    if(!T.loadFromFile("../itsuyo.jpg"))
        std::cout<<"erreur"<<std::endl;
    Sprite.setTexture(T);
    Sprite.setScale(0.1,0.1);
    Sprite.setPosition(100,50);
    hitbox_perso.left = Sprite.getPosition().x;
    hitbox_perso.top = Sprite.getPosition().y;
    hitbox_perso.width = T.getSize().x*Sprite.getScale().x;
    hitbox_perso.height = T.getSize().y*Sprite.getScale().y;
    PositionMemory=Sprite.getPosition();
}


void Itsuyo::Jab() {
    int dir;
    if(direction==1)
        dir=30;
    else
        dir=-30;
    {
        sf::FloatRect jabHitbox(dir,0,30,30);
        Hitbox jab;
        jab.hitbox=jabHitbox;
        jab.duration=5;
        jab.damage=5;
        jab.puissance_ejec=0.4;
        jab.direction=sf::Vector2f(2.5*direction,-1.5);
        Hitboxs_attaque.push(jab);
        Hitbox lent;
        lent.duration=0;
        Hitboxs_attaque.push(lent);
        speed.x=0;
        speed.y=0;
    }
}

void Itsuyo::Ftilt() {
    int dir;
    if(direction==1)
        dir=30;
    else
        dir=-48;
    {
        
        Hitbox coup;
        

        coup.damage=10;
        coup.puissance_ejec=0.3;
        coup.hitbox=sf::FloatRect(dir,0,40,15); 
        coup.direction=sf::Vector2f(2.5*direction,-1.5);
        Hitboxs_attaque.push(coup);


        
        Hitbox lent;
        lent.duration=15;
        Hitboxs_attaque.push(lent);
        
        speed.x=0;
        speed.y=0;
    }
}