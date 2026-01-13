#include<iostream>
#include<SFML/Graphics.hpp>
#include<vector>


class Perso
{

public:
    sf::Sprite Sprite;
    std::string nom;
    bool dbjump=true;
    bool in_air=true;
    int pourcentage=0;
    sf::Vector2f speed;
    float ground_speed;
    float air_speed;
    bool crouch=false;
    int jump_height;
    char direction;
  




    virtual void Jab()=0;

    // virtual void Ftilt()=0;

    // virtual void Utilt()=0;

    // virtual void Dtilt()=0;

    // virtual void Fsmash()=0;

    // virtual void Usmash()=0;

    // virtual void Dsmash()=0;

    void move(){
        Sprite.move(speed);
    }
    void input(sf::Event event)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)and !crouch)
        {
            if (!in_air)
            {
                speed.x=ground_speed;
            }
            else
            {
                direction='d';
                speed.x=air_speed;
            }
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)and !crouch)
        {
            if (!in_air)
            {
                speed.x=ground_speed;
            }
            else
            {
                direction='g';
                speed.x=-air_speed;
            }
            
        }
        else
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            if (!in_air)
            {
                speed.y-=jump_height;
                in_air=true;
                crouch=false;
            }
            else
            {
                if (dbjump)
                {
                    speed.y-=jump_height;
                    dbjump=false;
                }
            }
        }
        else
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if (!in_air)
            {
                crouch=true;
            }
        }
        else
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                //Ftilt();
            }
            else
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) and !sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            {
                //Dtilt();
            }
            else
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) and !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                //Utilt();
            }
            else
                Jab();
        }
    }

};

struct Hitbox
{
    sf::FloatRect hitbox;
    float duration;
};

class Miruka : public Perso
{
    public:
    Miruka(){
        nom="Miruka";
        
        speed.x=300;
        speed.y=100;
        in_air=true;
        crouch=false;
        ground_speed=8;
        air_speed=5;
        jump_height=20;
        pourcentage=0;
        sf::Texture T;
        T.loadFromFile("../../miruka.jpg");
        Sprite.setTexture(T);
        Sprite.setPosition(0,0);
    }


    std::vector<Hitbox> Hitboxs;
    void Jab() override{
        sf::FloatRect jabHitbox(Sprite.getPosition().x+10,Sprite.getPosition().y+10,20,20);
        Hitbox jab;
        jab.hitbox=jabHitbox;
        jab.duration=1;
        Hitboxs.push_back(jab);
    }
};


int main()
{
    Miruka miruka;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::Event event;

// tant qu'il y a des évènements à traiter...
while (window.pollEvent(event))
{
    // on regarde le type de l'évènement...
    switch (event.type)
    {
        // fenêtre fermée
        case sf::Event::Closed:
            window.close();
            break;
        // on ne traite pas les autres types d'évènements
        default:
            break;
    }
    miruka.speed.y+=2;
    if (miruka.Sprite.getPosition().y>500)
    {
        miruka.Sprite.setPosition(miruka.Sprite.getPosition().x,500);
        miruka.speed.y=0;
    }
    
    window.clear(sf::Color::White);
    window.draw(miruka.Sprite);
    for(Hitbox &hitbox :miruka.Hitboxs )
    {
        int i=0;
        sf::RectangleShape rect(sf::Vector2f(hitbox.hitbox.width, hitbox.hitbox.height));
            rect.setPosition(hitbox.hitbox.left, hitbox.hitbox.top);
            rect.setFillColor(sf::Color::Transparent);
            rect.setOutlineThickness(2);
            rect.setOutlineColor(sf::Color::Red);
            window.draw(rect);
        hitbox.duration--;
        if (hitbox.duration<0)
        {
            miruka.Hitboxs.erase(miruka.Hitboxs.begin()+i);
        }
        else
            ++i;
        
    }
    window.display();
}

}





