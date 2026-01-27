#include "arrow.hpp"


Arrow::Arrow(sf::Texture &T){
    
    speed.y=0;
    sprite.setTexture(T);
    sprite.setScale(sf::Vector2f(0.20,0.2));
    hitbox.damage=6;
    hitbox.decalage=sf::Vector2f(0,0);
    hitbox.duration=1;
    
    hitbox.puissance_ejec=0.05;
}

void Arrow::move(){
    sprite.move(speed);
}

void Arrow::refresh_hitbox(){
    hitbox.hitbox=sprite.getGlobalBounds();
}

void Arrow::apply_forces(){
    speed.y+=0.2;
}

bool Arrow::is_ground_collision(){
    if (sprite.getPosition().y+sprite.getGlobalBounds().height>400)
       return true;
    else 
        return false;
}