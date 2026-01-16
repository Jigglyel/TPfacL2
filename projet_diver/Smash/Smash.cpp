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
    bool hitstun=false;
    int direction=1;
    sf::Texture T;
    sf::FloatRect hitbox_perso;
    int ID;
    int vies=3;
    std::vector<Hitbox> Hitboxs_attaque;
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
        if(std::sqrt(speed.x*speed.x+speed.y*speed.y)>10)
            hitstun=true;
        else
            hitstun=false;
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
                sf::Vector2f normalized;
                if(distance==0)
                     normalized=sf::Vector2f(0,0);
                else
                    normalized=sf::Vector2f(hitbox.direction.x/distance,hitbox.direction.y/distance);
                speed.x= hitbox.puissance_ejec*pourcentage*normalized.x;
                speed.y= hitbox.puissance_ejec*pourcentage*normalized.y;
                pourcentage+=hitbox.damage;
                crouch=false;
                in_air=true;
            }
        
    }
    void draw_hitboxs(sf::RenderWindow &window)
    {
        for(Hitbox &hitbox :Hitboxs_attaque )
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
                    Hitboxs_attaque.erase(Hitboxs_attaque.begin()+i);
                }
                else
                    ++i;
                
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
                speed.x+=0.2;
            else
                speed.x-=0.2;
            if(speed.y<0)
                speed.y+=0.2;
            else
                speed.y-=0.2;
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
        //mort
    }
    void check_Death(sf::RenderWindow &window)
    {
        if(!(Sprite.getPosition().x<window.getSize().x and Sprite.getPosition().x>0 and Sprite.getPosition().y<window.getSize().y and Sprite.getPosition().y>0))
        {
            respawn();
        }
    }
 
};
void input(Perso &j1 )
{
    sf::Keyboard::Key Up,Down,Left,Right,NormalAttack,Jump;
    if(j1.ID==0)
    {
        Up=sf::Keyboard::Z;
        Down=sf::Keyboard::S;
        Left=sf::Keyboard::Q;
        Right=sf::Keyboard::D;
        NormalAttack=sf::Keyboard::O;
        Jump=sf::Keyboard::Space;
    }
    if(j1.ID==1)
    {
        Up=sf::Keyboard::Up;
        Down=sf::Keyboard::Down;
        Left=sf::Keyboard::Left;
        Right=sf::Keyboard::Right;
        NormalAttack=sf::Keyboard::Enter;
        Jump=sf::Keyboard::RShift;
    } 








    if (sf::Keyboard::isKeyPressed(Right)and !j1.crouch)
    {
        if (!j1.in_air)
        {
            j1.direction=1;
            j1.speed.x=j1.ground_speed;
        }
        else if(!j1.hitstun)
        {
            j1.speed.x=j1.air_speed;
        }
        
    }

    if (sf::Keyboard::isKeyPressed(Left)and !j1.crouch)
    {
        if (!j1.in_air)
        {
            j1.direction=-1;
            j1.speed.x=-j1.ground_speed;
        }
        else if(!j1.hitstun)
        {
            
            j1.speed.x=-j1.air_speed;
        }
        
    }
    if(!sf::Keyboard::isKeyPressed(Left) and !sf::Keyboard::isKeyPressed(Right) and !j1.in_air or j1.crouch)
        j1.speed.x=0;
    if(!sf::Keyboard::isKeyPressed(Jump) and j1.in_air)
        j1.spaceRelease=true;
    if (sf::Keyboard::isKeyPressed(Jump) and !j1.hitstun)
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
    
    if (sf::Keyboard::isKeyPressed(Down))
    {
        if (!j1.in_air)
        {
            j1.crouch=true;
        }
    }else
    j1.crouch=false;
    
    if (sf::Keyboard::isKeyPressed(NormalAttack))
    {
            
            if (j1.crouch or sf::Keyboard::isKeyPressed(Down))
            {
                if(!j1.in_air)
                    j1.Dtilt();
                else
                    j1.Dair();
            }
            else
            if (sf::Keyboard::isKeyPressed(Up) and !sf::Keyboard::isKeyPressed(Down))
            {
                if(!j1.in_air)
                    j1.Utilt();
                else
                    j1.Upair();
            }
            else
            if (sf::Keyboard::isKeyPressed(Right) or sf::Keyboard::isKeyPressed(Left))
            {
                if(!j1.in_air)
                    j1.Ftilt();
                else
                    if(j1.direction==1)
                        j1.Fair();
                    else
                        j1.Bair();
            }
            else
                if(!j1.in_air)
                    j1.Jab();
                else
                    j1.Nair();
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
        air_speed=4;
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
            jab.puissance_ejec=0.2;
            jab.direction=sf::Vector2f(2.5*direction,-1.5);
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
            coup.puissance_ejec=0.3;
            coup.direction=sf::Vector2f(2.5*direction,-1.5);
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
            coup.puissance_ejec=0.2;
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
            coup.puissance_ejec=0.3;
            coup.direction=sf::Vector2f(0,-1);
            Hitboxs_attaque.push_back(coup);
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
            sf::FloatRect coupHitbox(Sprite.getPosition().x+dir,Sprite.getPosition().y-15,15,30);
            Hitbox coup;
            coup.hitbox=coupHitbox;
            coup.duration=1;
            coup.damage=8;
            coup.puissance_ejec=0.2;
            coup.direction=sf::Vector2f(1*direction,-2);
            Hitboxs_attaque.push_back(coup);
        }
    }
    void Bair() override{
        int dir;
        if(direction==1)
            dir=30;
        else
            dir=-25;
        
        {
            sf::FloatRect coupHitbox(Sprite.getPosition().x-dir,Sprite.getPosition().y,15,40);
            Hitbox coup;
            coup.hitbox=coupHitbox;
            coup.duration=1;
            coup.damage=15;
            coup.puissance_ejec=0.4;
            coup.direction=sf::Vector2f(-direction,-2);
            Hitboxs_attaque.push_back(coup);
        }
    }
    void Nair() override{
        int dir;
        if(direction==1)
            dir=30;
        else
            dir=-25;
        {
            sf::FloatRect coupHitbox(Sprite.getPosition().x,Sprite.getPosition().y,40,40);
            Hitbox coup;
            coup.hitbox=coupHitbox;
            coup.duration=1;
            coup.damage=9;
            coup.puissance_ejec=0.2;
            coup.direction=sf::Vector2f(speed.x,-1.25);
            Hitboxs_attaque.push_back(coup);
        }
    }
    void Upair() override{
        {
            sf::FloatRect coupHitbox(Sprite.getPosition().x-10,Sprite.getPosition().y-20,20,15);
            Hitbox coup;
            coup.hitbox=coupHitbox;
            coup.duration=1;
            coup.damage=12;
            coup.puissance_ejec=0.3;
            coup.direction=sf::Vector2f(0,-1);
            Hitboxs_attaque.push_back(coup);
        }
    }
    void Dair() override{
        {
            sf::FloatRect coupHitbox(Sprite.getPosition().x+10,Sprite.getPosition().y+20,20,20);
            Hitbox coup;
            coup.hitbox=coupHitbox;
            coup.duration=1;
            coup.damage=15;
            coup.puissance_ejec=0.3;
            coup.direction=sf::Vector2f(0,1);
            Hitboxs_attaque.push_back(coup);
            speed.y=10;
        }
    }
};


int main()
{
    Miruka j1(0),j2(1);
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::Event event;
    sf::Font font;
    if(!font.loadFromFile("/usr/share/fonts/type1/urw-base35/P052-Italic.t1"))
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
            std::cout<<j1.crouch<<std::endl;
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





