#include<iostream>
#include<SFML/Graphics.hpp>
#include<vector>
#include<cmath>
class Hitbox
{
    public: 

    sf::FloatRect hitbox;
    float duration;
    float damage;
    float puissance_ejec;
    sf::Vector2f direction;
};
class Perso
{
private:

public:
    bool spaceRelease=false;
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
    int direction=1;
    sf::Texture T;
    sf::FloatRect hitbox_perso;
    std::vector<Hitbox> Hitboxs_attaque;
  




    virtual void Jab()=0;

    virtual void Ftilt()=0;

    virtual void Utilt()=0;

    virtual void Dtilt()=0;

    // virtual void Fsmash()=0;

    // virtual void Usmash()=0;

    // virtual void Dsmash()=0;

    void move(){
        Sprite.move(speed);
        hitbox_perso.left = Sprite.getPosition().x;
        hitbox_perso.top = Sprite.getPosition().y;
        hitbox_perso.width = T.getSize().x*Sprite.getScale().x;
        hitbox_perso.height = T.getSize().y*Sprite.getScale().y;
    }
    sf::RectangleShape get_drawableHitbox()
    {
        sf::RectangleShape drawbox(sf::Vector2f(hitbox_perso.width, hitbox_perso.height));
        drawbox.setPosition(hitbox_perso.left, hitbox_perso.top);
        drawbox.setFillColor(sf::Color::Transparent);
        drawbox.setOutlineThickness(2);
        drawbox.setOutlineColor(sf::Color::Red);
        return drawbox;
    }

    void Check_touched(std::vector<Hitbox> Hitboxs_attaque_ennemis)
    {
        for(Hitbox hitbox : Hitboxs_attaque_ennemis)
            if (hitbox.hitbox.intersects(hitbox_perso))        
            {
                float distance=std::sqrt(hitbox.direction.x*hitbox.direction.x +hitbox.direction.y*hitbox.direction.y);
                sf::Vector2f normalized(hitbox.direction.x/distance,hitbox.direction.y/distance);
                speed.x= hitbox.puissance_ejec*pourcentage*normalized.x;
                speed.y= hitbox.puissance_ejec*pourcentage*normalized.y;
                pourcentage=hitbox.damage;
            }
        
    }

};
void input(Perso &j1 ,Perso &j2)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)and !j1.crouch)
    {
        if (!j1.in_air)
        {
            j1.direction=1;
            j1.speed.x=j1.ground_speed;
        }
        else
        {
            
            j1.speed.x=j1.air_speed;
        }
        
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)and !j1.crouch)
    {
        if (!j1.in_air)
        {
            j1.direction=-1;
            j1.speed.x=-j1.ground_speed;
        }
        else
        {
            
            j1.speed.x=-j1.air_speed;
        }
        
    }
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Q) and !sf::Keyboard::isKeyPressed(sf::Keyboard::D) or j1.crouch)
        j1.speed.x=0;
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and j1.in_air)
        j1.spaceRelease=true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if (!j1.in_air)
        {
            j1.speed.y=-j1.jump_height;
            j1.in_air=true;
            j1.crouch=false;
        }
        else
        {
            if (j1.dbjump and j1.spaceRelease)
            {
                j1.speed.y=-j1.jump_height;
                j1.dbjump=false;
                j1.spaceRelease=false;
            }
        }
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if (!j1.in_air)
        {
            j1.crouch=true;
        }
    }else
    j1.crouch=false;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
    {
        if(!j1.in_air)
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                j1.Ftilt();
            }
            else
            if (j1.crouch)
            {
                j1.Dtilt();
            }
            else
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) and !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                j1.Utilt();
            }
            else
                j1.Jab();
    }


    //Joueur 2

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)and !j2.crouch)
    {
        if (!j2.in_air)
        {
            j2.direction=1;
            j2.speed.x=j2.ground_speed;
        }
        else
        {
            j2.speed.x=j2.air_speed;
        }
        
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)and !j2.crouch)
    {
        if (!j2.in_air)
        {
            j2.direction=-1;
            j2.speed.x=-j2.ground_speed;
        }
        else
        {
            
            j2.speed.x=-j2.air_speed;
        }
        
    }
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) and !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) or j2.crouch)
        j2.speed.x=0;
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) and j2.in_air)
        j2.spaceRelease=true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
    {
        if (!j2.in_air)
        {
            j2.speed.y=-j2.jump_height;
            j2.in_air=true;
            j2.crouch=false;
        }
        else
        {
            if (j2.dbjump and j2.spaceRelease)
            {
                j2.speed.y=-j2.jump_height;
                j2.dbjump=false;
                j2.spaceRelease=false;
            }
        }
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (!j2.in_air)
        {
            j2.crouch=true;
        }
    }else
    j2.crouch=false;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        if(!j2.in_air)
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                j2.Ftilt();
            }
            else
            if (j2.crouch)
            {
                j2.Dtilt();
            }
            else
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and !sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                j2.Utilt();
            }
            else
                j2.Jab();
    }
    
}
void affiche pourcentage(sf::RenderWindow window,sf::Font &font,Perso P)
{
    sf::Text text;
    text.setFont(font);
    text.setText(P.pourcentage);
    window.draw(text)
}
class Miruka : public Perso
{


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
        Sprite.setScale(0.1,0.1);
        Sprite.setPosition(100,50);
        hitbox_perso.left = Sprite.getPosition().x;
        hitbox_perso.top = Sprite.getPosition().y;
        hitbox_perso.width = T.getSize().x*Sprite.getScale().x;
        hitbox_perso.height = T.getSize().y*Sprite.getScale().y;
        
        
    }

    void is_crouching()
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
    
    void Jab() override{
        int dir;
        if(direction==1)
            dir=30;
        else
            dir=-30;
        {
            sf::FloatRect jabHitbox(Sprite.getPosition().x+dir,Sprite.getPosition().y,20,20);
            Hitbox jab;
            jab.hitbox=jabHitbox;
            jab.duration=1;
            jab.damage=5;
            jab.puissance_ejec=1;
            jab.direction=sf::Vector2f(1.3*direction,-1.5);
            Hitboxs_attaque.push_back(jab);
            speed.x=0;
            speed.y=0;
        }

    }
    void Ftilt() override{
        int dir;
        if(direction==1)
            dir=30;
        else
            dir=-48;
        {
            sf::FloatRect coupHitbox(Sprite.getPosition().x+dir,Sprite.getPosition().y,40,15);
            Hitbox coup;
            coup.hitbox=coupHitbox;
            coup.duration=1;
            coup.damage=10;
            coup.puissance_ejec=1.2;
            coup.direction=sf::Vector2f(1*direction,-1.5);
            Hitboxs_attaque.push_back(coup);
            speed.x=0;
            speed.y=0;
        }
    }
    void Utilt() override{
        {
            sf::FloatRect coupHitbox(Sprite.getPosition().x-10,Sprite.getPosition().y-20,40,15);
            Hitbox coup;
            coup.hitbox=coupHitbox;
            coup.duration=1;
            coup.damage=5;
            coup.puissance_ejec=1.1;
            coup.direction=sf::Vector2f(0,-1);
            Hitboxs_attaque.push_back(coup);
            speed.x=0;
            speed.y=0;
        }
    }
    void Dtilt() override{
        int dir;
        if(direction==1)
            dir=30;
        else
            dir=-25;
        {
            sf::FloatRect coupHitbox(Sprite.getPosition().x+dir,Sprite.getPosition().y-15,15,40);
            Hitbox coup;
            coup.hitbox=coupHitbox;
            coup.duration=1;
            coup.damage=15;
            coup.puissance_ejec=1.8;
            coup.direction=sf::Vector2f(0.3,-1);
            Hitboxs_attaque.push_back(coup);
            speed.x=0;
            speed.y=0;
        }

    }
};


int main()
{
    Miruka j1,j2;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::Event event;
    sf::Font font;
    font.loadFromFile()
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
            input(j1,j2);
            j1.move();
            j2.move();
            j1.is_crouching();
            j2.is_crouching();
            j1.speed.y+=0.5;
            j2.speed.y+=0.5;
            j1.Check_touched(j2.Hitboxs_attaque);
            j2.Check_touched(j1.Hitboxs_attaque);
            
            if (j1.Sprite.getPosition().y>300)
            {
                j1.Sprite.setPosition(j1.Sprite.getPosition().x,300);
                j1.speed.y=0;
                j1.in_air=false;
                j1.dbjump=true;
                j1.spaceRelease=false;
            }
            window.clear(sf::Color::Black);
            window.draw(j1.Sprite);
            window.draw(j1.get_drawableHitbox());
            if (j2.Sprite.getPosition().y>300)
            {
                j2.Sprite.setPosition(j2.Sprite.getPosition().x,300);
                j2.speed.y=0;
                j2.in_air=false;
                j2.dbjump=true;
                j2.spaceRelease=false;
            }
            window.draw(j2.Sprite);
            window.draw(j2.get_drawableHitbox());
            for(Hitbox &hitbox :j1.Hitboxs_attaque )
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
                    j1.Hitboxs_attaque.erase(j1.Hitboxs_attaque.begin()+i);
                }
                else
                    ++i;
                
            }
            for(Hitbox &hitbox :j2.Hitboxs_attaque )
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
                    j2.Hitboxs_attaque.erase(j2.Hitboxs_attaque.begin()+i);
                }
                else
                    ++i;
                
            }
            window.display();
    }

}





