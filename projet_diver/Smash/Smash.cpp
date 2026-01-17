#include<iostream>
#include<SFML/Graphics.hpp>
#include<vector>
#include<cmath>
#include<queue>
class Hitbox
{
    public: 
    sf::FloatRect hitbox;
    float duration;
    float damage;
    float puissance_ejec;
    sf::Vector2f direction;
    sf::Vector2f decalage;
    Hitbox()
    {
        hitbox.width=0;
        hitbox.height=0;
        duration=1;
        damage=0;
        puissance_ejec=0;
    }
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
    float air_speedmax;
    float air_acceleration;
    bool crouch=false;
    float jump_height;
    bool hitstun=false;
    int direction=1;
    sf::Texture T;
    sf::FloatRect hitbox_perso;
    int ID;
    int vies=3;
    std::queue<Hitbox> Hitboxs_attaque;
    Perso(int id){
        ID=id;

    }




    virtual void Jab()=0;

    virtual void Ftilt()=0;

    virtual void Utilt()=0;

    virtual void Dtilt()=0;

    // virtual void Fsmash()=0;

    // virtual void Usmash()=0;

    // virtual void Dsmash()=0;

    virtual void Fair()=0;

    virtual void Dair()=0;

    virtual void Nair()=0;

    virtual void Upair()=0;

    virtual void Bair()=0;

    void move(){
        Sprite.move(speed);
        hitbox_perso=Sprite.getGlobalBounds();
        if(std::sqrt(speed.x*speed.x+speed.y*speed.y)<10)
            hitstun=false;
    }
    sf::RectangleShape get_drawableHitbox()
    {
        sf::RectangleShape drawbox(sf::Vector2f(hitbox_perso.width, hitbox_perso.height));
        drawbox.setPosition(hitbox_perso.left, hitbox_perso.top);
        drawbox.setFillColor(sf::Color::Transparent);
        drawbox.setOutlineThickness(2);
        if (Hitboxs_attaque.empty())
        {
            drawbox.setOutlineColor(sf::Color::Red);
        }
        else
            drawbox.setOutlineColor(sf::Color::Magenta);
        
        
        return drawbox;
    }

    void Check_touched(std::queue<Hitbox> Hitboxs_attaque_ennemis)
    {
         
        if(!Hitboxs_attaque_ennemis.empty())
        {
            
           Hitbox &hitbox=Hitboxs_attaque_ennemis.front();
            if (hitbox.hitbox.intersects(hitbox_perso))        
            {
                float distance=std::sqrt(hitbox.direction.x*hitbox.direction.x +hitbox.direction.y*hitbox.direction.y);
                sf::Vector2f normalized;
                if(distance==0)
                     normalized=sf::Vector2f(0,0);
                else
                    normalized=sf::Vector2f(hitbox.direction.x/distance,hitbox.direction.y/distance);
                speed.x= hitbox.puissance_ejec*(pourcentage+1)*normalized.x;
                speed.y= hitbox.puissance_ejec*(pourcentage+1)*normalized.y;
                pourcentage+=hitbox.damage;
                crouch=false;
                in_air=true;
                hitstun=true;
            }
        }
    }
    void draw_hitboxs(sf::RenderWindow &window)
    {
          
        if(!Hitboxs_attaque.empty())
        {
           Hitbox &hitbox=Hitboxs_attaque.front();
            
                sf::RectangleShape rect(sf::Vector2f(hitbox.hitbox.width, hitbox.hitbox.height));
                    rect.setPosition(hitbox.hitbox.left, hitbox.hitbox.top);
                    rect.setFillColor(sf::Color::Transparent);
                    rect.setOutlineThickness(2);
                    rect.setOutlineColor(sf::Color::Red);
                    window.draw(rect);
                hitbox.duration--;
                if (hitbox.duration<=0)
                {
                    Hitboxs_attaque.pop();
                }
                
        }
    }

    void ground_collisions()
    {
        if (Sprite.getPosition().y>400)
            {
                Sprite.setPosition(Sprite.getPosition().x,400);
                speed.y=0;
                in_air=false;
                dbjump=true;
                spaceRelease=false;
            }
    }

    void apply_forces()
    {
        if(in_air)
        {
            speed.y+=0.5;
            if(speed.x<0)
                speed.x+=0.1;
            else
                speed.x-=0.1;
            if(speed.y<0)
                speed.y+=0.2;
        }
    }
    void respawn()
    {
        if(vies>0)
        {
            pourcentage=0;
            speed.x=0;
            speed.y=0;
            if(ID==0)
                Sprite.setPosition(100,50);
            else
                Sprite.setPosition(500,50);
            in_air=true;
            crouch=false;
            dbjump=true;
            vies--;
        }
        else
        {
            /* code */
        }
        
    }
    void check_Death(sf::RenderWindow &window)
    {
        if(!(Sprite.getPosition().x<window.getSize().x and Sprite.getPosition().x>0 and Sprite.getPosition().y<window.getSize().y and Sprite.getPosition().y>0))
        {
            respawn();
        }
    }
    void setActivesHitboxes()
    {  
        Hitboxs_attaque.front().hitbox.left+=Sprite.getPosition().x;
        Hitboxs_attaque.front().hitbox.top+=Sprite.getPosition().y;
    } 
 
};
void input(Perso &Player )
{
    if (Player.Hitboxs_attaque.empty())
    {
        sf::Keyboard::Key Up,Down,Left,Right,NormalAttack,Jump;
        if(Player.ID==0)
        {
            Up=sf::Keyboard::Z;
            Down=sf::Keyboard::S;
            Left=sf::Keyboard::Q;
            Right=sf::Keyboard::D;
            NormalAttack=sf::Keyboard::O;
            Jump=sf::Keyboard::Space;
        }
        if(Player.ID==1)
        {
            Up=sf::Keyboard::Up;
            Down=sf::Keyboard::Down;
            Left=sf::Keyboard::Left;
            Right=sf::Keyboard::Right;
            NormalAttack=sf::Keyboard::Enter;
            Jump=sf::Keyboard::RShift;
        } 








        if (sf::Keyboard::isKeyPressed(Right)and !Player.crouch)
        {
            if (!Player.in_air)
            {
                Player.direction=1;
                Player.speed.x=Player.ground_speed;
            }
            else if(!Player.hitstun)
            {
                Player.speed.x+=Player.air_acceleration;
                if (Player.speed.x>=Player.air_speedmax)
                {
                    Player.speed.x=Player.air_speedmax;
                }
                
            }
            
        }

        if (sf::Keyboard::isKeyPressed(Left)and !Player.crouch)
        {
            if (!Player.in_air)
            {
                Player.direction=-1;
                Player.speed.x=-Player.ground_speed;
            }
            else if(!Player.hitstun)
            {
                
                Player.speed.x-=Player.air_acceleration;
                if (Player.speed.x<=-Player.air_speedmax)
                {
                    Player.speed.x=-Player.air_speedmax;
                }
            }
            
        }
        if(!sf::Keyboard::isKeyPressed(Left) and !sf::Keyboard::isKeyPressed(Right) and !Player.in_air or Player.crouch)
            Player.speed.x=0;
        if(!sf::Keyboard::isKeyPressed(Jump) and Player.in_air)
            Player.spaceRelease=true;
        if (sf::Keyboard::isKeyPressed(Jump) and !Player.hitstun)
        {
            if (!Player.in_air)
            {
                Player.speed.y=-Player.jump_height;
                Player.in_air=true;
                Player.crouch=false;
            }
            else
            {
                if (Player.dbjump and Player.spaceRelease)
                {
                    Player.speed.y=-Player.jump_height;
                    Player.dbjump=false;
                    Player.spaceRelease=false;
                }
            }
        }
        
        if (sf::Keyboard::isKeyPressed(Down))
        {
            if (!Player.in_air)
            {
                Player.crouch=true;
            }
        }else
        Player.crouch=false;
        
        if (sf::Keyboard::isKeyPressed(NormalAttack))
        {
                
                if (Player.crouch or sf::Keyboard::isKeyPressed(Down))
                {
                    if(!Player.in_air)
                        Player.Dtilt();
                    else
                        Player.Dair();
                }
                else
                if (sf::Keyboard::isKeyPressed(Up) and !sf::Keyboard::isKeyPressed(Down))
                {
                    if(!Player.in_air)
                        Player.Utilt();
                    else
                        Player.Upair();
                }
                else
                if (sf::Keyboard::isKeyPressed(Right) or sf::Keyboard::isKeyPressed(Left))
                {
                    if(!Player.in_air)
                        Player.Ftilt();
                    else
                    {
                        if (sf::Keyboard::isKeyPressed(Right) )
                        {
                            if (Player.direction==1)
                            {
                                Player.Fair();
                            }
                            else
                                Player.Bair();
                        }
                        else
                        {
                            if (Player.direction==-1)
                            {
                                Player.Fair();
                            }
                            else
                                Player.Bair();
                            
                        }
                        
        
                        
                    }
                }
                else
                    if(!Player.in_air)
                        Player.Jab();
                    else
                        Player.Nair();
        }
    } 
    else if(!Player.in_air)
    {
        Player.speed.x=0;
        Player.speed.y=0;
    }  
}
void affiche_pourcentage(sf::RenderWindow &window,sf::Font &font,float pourcentage,int id,int vies)
{
    sf::Text pourcentext,text_vie;
    pourcentext.setFont(font);
    pourcentext.setString(std::to_string(pourcentage).substr(0,3)+'%');
    pourcentext.setPosition(id*100+300,500);
    window.draw(pourcentext);
    text_vie.setString(" vie =" + std::to_string(vies));
    text_vie.setPosition(id*100+290,540);
    text_vie.setFont(font);
    window.draw(text_vie);
}
class Miruka : public Perso
{


    public:
    Miruka(int id) :Perso(id){
        
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
            sf::FloatRect jabHitbox(dir,0,20,20);
            Hitbox jab;
            jab.hitbox=jabHitbox;
            jab.duration=5;
            jab.damage=5;
            jab.puissance_ejec=0.2;
            jab.direction=sf::Vector2f(2.5*direction,-1.5);
            Hitboxs_attaque.push(jab);
            Hitbox lent;
            lent.duration=10;
            Hitboxs_attaque.push(lent);
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
    void Utilt() override{
        {
            sf::FloatRect coupHitbox(-10,-20,40,15);
            Hitbox coup;
            coup.hitbox=coupHitbox;
            coup.duration=1;
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
    void Dtilt() override{
        int dir;
        if(direction==1)
            dir=30;
        else
            dir=-25;
        {
            sf::FloatRect coupHitbox(dir,-15,15,40);
            Hitbox coup;
            coup.hitbox=coupHitbox;
            coup.duration=1;
            coup.damage=15;
            coup.puissance_ejec=0.3;
            coup.direction=sf::Vector2f(0,-1);
            Hitboxs_attaque.push(coup);
            Hitbox lent;
            lent.duration=20;
            Hitboxs_attaque.push(lent);
            speed.x=0;
            speed.y=0;
        }
    }
    void Fair() override{
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
    void Bair() override{
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
    void Nair() override{
        int dir;
        if(direction==1)
            dir=30;
        else
            dir=-25;
        
            for (size_t i = 0; i < 15; i++)
            {
                sf::FloatRect coupHitbox(0,0,40,40);
                Hitbox coup;
                coup.hitbox=coupHitbox;
                coup.duration=1;
                coup.damage=9;
                coup.puissance_ejec=0.2;
                coup.direction=sf::Vector2f(speed.x,-1.25);
                Hitboxs_attaque.push(coup);
            }
            
            
            Hitbox lent;
            lent.duration=15;
            Hitboxs_attaque.push(lent);
        
    }
    void Upair() override{
        {
            sf::FloatRect coupHitbox(10,-20,20,15);
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
    void Dair() override{
        {
            for (size_t i = 0; i < 10; i++)
            {
                sf::FloatRect coupHitbox(10,30,15,25);
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
};


int main()
{
    Miruka j1(0),j2(1);
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::Event event;
    sf::Font font;
    std::string police_path;
    #ifdef _WIN32
        police_path="C:/Users/mu37/OneDrive/Images/Documents/Image-Line/FL Studio/Settings/Hardware/NI Komplete Kontrol/docs/_static/fonts/Oswald.ttf";
    #else
        police_path="/usr/share/fonts/type1/urw-base35/P052-Italic.t1";
    #endif
    
        
    if(!font.loadFromFile(police_path))
        std::cout<<"la police d'écriture n'a pas pu être chargée"<<std::endl;
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
            input(j1);
            input(j2);
            j1.is_crouching();
            j2.is_crouching();
            j1.setActivesHitboxes();
            j2.setActivesHitboxes();
            j1.Check_touched(j2.Hitboxs_attaque);
            j2.Check_touched(j1.Hitboxs_attaque);
            j1.apply_forces();
            j2.apply_forces();
            j1.move();
            j2.move();
            j1.ground_collisions();
            j2.ground_collisions();
            j1.check_Death(window);
            j2.check_Death(window);
            /////////////////////////////
            //Drawings
            window.clear(sf::Color(30,200,200));
            window.draw(j1.Sprite);
            window.draw(j1.get_drawableHitbox());
            window.draw(j2.Sprite);
            window.draw(j2.get_drawableHitbox());
            j1.draw_hitboxs(window);
            j2.draw_hitboxs(window);
            affiche_pourcentage(window,font,j1.pourcentage,j1.ID,j1.vies);
            affiche_pourcentage(window,font,j2.pourcentage,j2.ID,j2.vies);
            window.display();
    }

}





