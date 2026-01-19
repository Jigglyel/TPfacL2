#include "Death_Particules.hpp"

    void Death_particules::apply_forces()
    {
        
            speed.y+=0.5;
    }

    void Death_particules::rebondit(sf::RenderWindow &window)
    {
        if (tri.getPosition().x<0)
        {
            tri.setPosition(0,tri.getPosition().y);
            speed.x=-speed.x;
        }
        if (tri.getPosition().x>window.getSize().x)
        {
            tri.setPosition(window.getSize().x,tri.getPosition().y);
            speed.x=-speed.x;
        }
        if (tri.getPosition().y<0)
        {
            tri.setPosition(tri.getPosition().x,0);
            speed.y=-speed.y;
        }
        if (tri.getPosition().y>window.getSize().y)
        {
            tri.setPosition(tri.getPosition().x,window.getSize().y);
            speed.y=-speed.y;
        }
        
    }
    void Death_particules::move()
    {
        tri.move(speed);
        durée--;
    }
    void Death_particules::affiche(sf::RenderWindow &window)
    {
        window.draw(tri);
    }
    


