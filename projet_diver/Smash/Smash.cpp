#include<iostream>
#include<SFML/Graphics.hpp>
#include<vector>

struct Hitbox
{
    sf::FloatRect hitbox;
    float duration;
};
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
    float jump_height;
    char direction='d';
    std::vector<Hitbox> Hitboxs;
  




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
    void input()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)and !crouch)
        {
            if (!in_air)
            {
                direction='d';
                speed.x=ground_speed;
            }
            else
            {
                
                speed.x=air_speed;
            }
            
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)and !crouch)
        {
            if (!in_air)
            {
                direction='g';
                speed.x=-ground_speed;
            }
            else
            {
                
                speed.x=-air_speed;
            }
            
        }
        if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Q) and !sf::Keyboard::isKeyPressed(sf::Keyboard::D) or crouch)
            speed.x=0;
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            if (!in_air)
            {
                speed.y=-jump_height;
                in_air=true;
                crouch=false;
            }
            else
            {
                if (dbjump)
                {
                    speed.y=-jump_height;
                    dbjump=false;
                }
            }
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if (!in_air)
            {
                crouch=true;
            }
        }
        
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



class Miruka : public Perso
{
    private:
    sf::Texture T;

    public:
    Miruka(){
        nom="Miruka";
        
        speed.x=0;
        speed.y=0;
        in_air=true;
        crouch=false;
        ground_speed=2.5;
        air_speed=2;
        jump_height=10;
        pourcentage=0;
        
        if(!T.loadFromFile("../../miruka.jpg"))
            std::cout<<"erreur"<<std::endl;
        Sprite.setTexture(T);
        Sprite.scale(0.1,0.1);
        Sprite.setPosition(100,50);
        
        
    }


    
    void Jab() override{
        if(direction=='d')
        {
            sf::FloatRect jabHitbox(Sprite.getPosition().x+30,Sprite.getPosition().y+10,20,20);
            Hitbox jab;
            jab.hitbox=jabHitbox;
            jab.duration=1;
            Hitboxs.push_back(jab);
        }
        else
        {
            sf::FloatRect jabHitbox(Sprite.getPosition().x-30,Sprite.getPosition().y+10,20,20);
            Hitbox jab;
            jab.hitbox=jabHitbox;
            jab.duration=1;
            Hitboxs.push_back(jab);
        }
    }
};


int main()
{
    Miruka miruka;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::Event event;
    window.setFramerateLimit(30);
    while(window.isOpen())
    {
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
        }
            miruka.input();
            miruka.move();
            miruka.speed.y+=0.5;
            if (miruka.Sprite.getPosition().y>300)
            {
                miruka.Sprite.setPosition(miruka.Sprite.getPosition().x,300);
                miruka.speed.y=0;
                miruka.in_air=false;
                miruka.dbjump=true;
            }
            window.clear(sf::Color::Black);
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





