#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<cstdlib>
#include"miruka.hpp"





void input(Perso &Player,sf::Texture &fleche,std::vector<Arrow> &fleches )
{
    if (Player.Hitboxs_attaque.empty())
    {
        sf::Keyboard::Key Up,Down,Left,Right,NormalAttack,Jump,SpecialAttack;
        if(Player.ID==0)
        {
            Up=sf::Keyboard::Z;
            Down=sf::Keyboard::S;
            Left=sf::Keyboard::Q;
            Right=sf::Keyboard::D;
            NormalAttack=sf::Keyboard::T;
            Jump=sf::Keyboard::Space;
            SpecialAttack=sf::Keyboard::R;
        }
        if(Player.ID==1)
        {
            Up=sf::Keyboard::Up;
            Down=sf::Keyboard::Down;
            Left=sf::Keyboard::Left;
            Right=sf::Keyboard::Right;
            NormalAttack=sf::Keyboard::Enter;
            Jump=sf::Keyboard::RShift;
            SpecialAttack=sf::Keyboard::M;
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
        else
        if (sf::Keyboard::isKeyPressed(SpecialAttack))
        {
            Player.NeutralB(fleches,fleche);
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
    if (vies>=1)
        text_vie.setString(" vie =" + std::to_string(vies));
    else
        text_vie.setString("mort");
    text_vie.setPosition(id*100+290,540);
    text_vie.setFont(font);
    window.draw(text_vie);
}

void gerer_fleches(std::vector<Arrow> &fleches,sf::RenderWindow &window)
{
    for (auto it = fleches.begin(); it != fleches.end(); )
    {
        it->apply_forces();
        it->move();
        if (it->is_ground_collision())
        {
            it = fleches.erase(it); // erase retourne le prochain itérateur VALIDE
        }
        else
        {
            it->refresh_hitbox();
            window.draw(it->sprite);
            ++it;
        }
    }
    
}

int main()
{
    Miruka j1(0),j2(1);
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::Event event;
    sf::Font font;
    std::string police_path;
    std::vector<sf::RectangleShape> particules;
    std::vector<Arrow> fleches;
    sf::Texture flecheImage;
    int r=0, g=0, b=0;
    #ifdef _WIN32
        police_path="C:/Users/mu37/OneDrive/Images/Documents/Image-Line/FL Studio/Settings/Hardware/NI Komplete Kontrol/docs/_static/fonts/Oswald.ttf";
    #else
        police_path="/usr/share/fonts/type1/urw-base35/P052-Italic.t1";
    #endif
    
    if(!flecheImage.loadFromFile("../fleche.jpg"))
        std::cout<<"la fleche n'a pas pu être chargée"<<std::endl;
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
            input(j1,flecheImage,fleches);
            input(j2,flecheImage,fleches);
            j1.is_crouching();
            j2.is_crouching();
           
            j1.apply_forces();
            j2.apply_forces();
            j1.move();
            j2.move();
            gerer_fleches(fleches,window);
            j1.setActivesHitboxes();
            j2.setActivesHitboxes();
            j1.Check_touched(j2.Hitboxs_attaque,fleches);
            j2.Check_touched(j1.Hitboxs_attaque,fleches);
            j1.ground_collisions();
            j2.ground_collisions();
            j1.check_Death(window);
            j2.check_Death(window);
            /////////////////////////////
            //Drawings
            r=100;
            g=190%256;
            b=105%256;
            window.clear(sf::Color(r,g,b));
            window.draw(j1.Sprite);
            window.draw(j1.get_drawableHitbox());
            window.draw(j2.Sprite);
            window.draw(j2.get_drawableHitbox());
            j1.draw_hitboxs(window);
            j2.draw_hitboxs(window);
            j1.move_triangles(window);
            j2.move_triangles(window);
            affiche_pourcentage(window,font,j1.pourcentage,j1.ID,j1.vies);
            affiche_pourcentage(window,font,j2.pourcentage,j2.ID,j2.vies);
            window.display();
    }

}





