#include<iostream>
#include<array>
#include<cstdlib>
#include<ctime>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<string>
#include<cmath>
#include<vector>
#include<stack>
const int NC=1280;
const int NL=720;
using Tligne=std::array<uint8_t ,NC>;
using Timage=std::array<Tligne,NL>;


struct action{
    sf::Color couleur;
    sf::Vector2i pos;
};
struct maillon{
    std::vector<action> val;
    maillon* suiv;
};

using pile=maillon*;

pile init_pile()
{
    return nullptr;
}

void empiler(pile& P, std::vector<action> a)
{
    if (P!=nullptr)
    {
        maillon *tier=P;
        P=new maillon;
        P->val=a;
        P->suiv=tier;
    }
    else
    {
        P=new maillon;
        P->val=a;
        P->suiv=nullptr;
    }
}

std::vector<action> pop(pile &P)
{
    pile resu=P;
    std::vector<action> resu2=resu->val;
    P=P->suiv;
    delete resu;
    return resu2;
}
std::vector<action> consulte(pile &P)
{
    return P->val;
}


void init (sf::VertexArray & pixels)
{
    for (size_t i = 50; i < NL; i++)
    {
        for (size_t j = 0; j < NC; j++)
        {
            pixels[i * NC + j].position = sf::Vector2f(j, i);
            pixels[i * NC + j].color = sf::Color(255,255,255);
        }
    }
}
void efface (sf::VertexArray & pixels,pile &P)
{
    action tache;
    std::vector<action> taches;
    for (size_t i = 50; i < NL; i++)
    {
        for (size_t j = 0; j < NC; j++)
        {
            tache.couleur=pixels[i * NC + j].color;
            tache.pos=sf::Vector2i(pixels[i * NC + j].position);
            if (tache.couleur!=sf::Color::White)
            {
                taches.push_back(tache);
            }  
            pixels[i * NC + j].color = sf::Color(255,255,255);
        }
    }
    empiler(P,taches);
}
void redo(sf::VertexArray &pixels,pile &P)
{
    std::vector<action> taches=pop(P);
    for(action tache : taches)
    {
       
        pixels[tache.pos.y*NC+tache.pos.x].color=tache.couleur;
    }
}
void peint_pixel(sf::VertexArray &pixels,int x,int y,int brushSize,sf::Color couleur,std::vector<action>& taches)
{
    action tache;
    for (int dy = -brushSize; dy <= brushSize; ++dy)
        for (int dx = -brushSize; dx <= brushSize; ++dx)
        {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < NC && ny >= 50 && ny < NL and pixels[ny * NC + nx].color!=couleur)
            {
                tache.couleur=pixels[ny * NC + nx].color;
                tache.pos=sf::Vector2i(nx,ny);
                pixels[ny * NC + nx].color = couleur;
                
                taches.push_back(tache);
            }
        }
}
void peint_ligne(sf::VertexArray &pixels,sf::Vector2f curent,sf::Vector2f old,int brushSize,sf::Color couleur,std::vector<action> &taches)
{
    float dx= curent.x-old.x;
    float dy= curent.y-old.y;
    float distance=std::sqrt(dx*dx+dy*dy);
    if(distance==0)
        distance=1;
    float x=old.x, y=old.y;
    for(int i=0 ;i<distance;++i)
    {
        peint_pixel(pixels,x,y,brushSize,couleur,taches);
        x+=dx/distance;
        y+=dy/distance;
    }
}
void touche(sf::Event event,sf::VertexArray & pixels,int &brushSize,pile &P,bool& full_mode,std::vector<action>& taches)
{
    if (event.key.code==sf::Keyboard::Space)
    {
        if (!taches.empty())
        {
            empiler(P,taches);
        }
        
        
        efface(pixels,P);
    } 
    if (event.key.code==sf::Keyboard::Add)
    {
        brushSize++;
    }
    if (event.key.code==sf::Keyboard::Subtract)
    {
        brushSize--;
    }
    if (event.key.code==sf::Keyboard::LControl)
    {
        if (P!=nullptr)
        {
            redo(pixels,P);
        }
    }
    if (event.key.code==sf::Keyboard::R)
        full_mode=!full_mode;
    
}
void remplissage(sf::VertexArray & pixels,sf::Color couleur,sf::Vector2i pos,std::vector<action> &taches)
{
    std::stack<action> P;
    action dou;
    dou.pos.x=pos.x;
    dou.pos.y=pos.y;
    dou.couleur=couleur;
    action redo;
    redo.couleur=pixels[(pos.y)*NC +pos.x].color;
    P.push(dou);
    
    
    while (!P.empty())
    {   dou=P.top();
        P.pop();
        if(dou.pos.x >= 0 && dou.pos.x < NC && dou.pos.y >= 50 && dou.pos.y < NL and pixels[dou.pos.y*NC +dou.pos.x].color==redo.couleur and redo.couleur!=couleur)
        {
            redo.pos.x=dou.pos.x;
            redo.pos.y=dou.pos.y;
            taches.push_back(redo);
            pixels[dou.pos.y*NC +dou.pos.x].color=dou.couleur;
            dou.pos.x=dou.pos.x+1;
            P.push(dou);
            dou.pos.x=dou.pos.x-2;
            P.push(dou);
            dou.pos.x=dou.pos.x+2;
            dou.pos.y=dou.pos.y+1;
            P.push(dou);
            dou.pos.y=dou.pos.y-2;
            P.push(dou);
        }
    }
    
}
void HUD(sf::RenderWindow &window,sf::RectangleShape* &couleurs)
{
    couleurs= new sf::RectangleShape[10];
    
    couleurs[0].setFillColor(sf::Color::Black);
    couleurs[1].setFillColor(sf::Color::White);
    couleurs[2].setFillColor(sf::Color::Blue);
    couleurs[3].setFillColor(sf::Color::Red);
    couleurs[4].setFillColor(sf::Color::Yellow);
    couleurs[5].setFillColor(sf::Color::Green);
    couleurs[6].setFillColor(sf::Color::Cyan);
    couleurs[7].setFillColor(sf::Color::Magenta);
    couleurs[8].setFillColor(sf::Color::Transparent);
    couleurs[9].setFillColor(sf::Color(rand()%256,rand()%256,rand()%256));
    for(int i=0;i<10;++i)
    {
        couleurs[i].setSize(sf::Vector2f(30,30));
        couleurs[i].setPosition(40*i,10);
        window.draw(couleurs[i]);
    }
    
}

void selectCouleur(sf::RenderWindow &window, sf::Color &couleur,int x,int y,sf::RectangleShape* couleurs)
{
    for(int i=0;i<10;++i)
    {
        if(couleurs[i].getGlobalBounds().contains(sf::Vector2f(x,y)))
            switch(i)
            {
                case 0:
                    couleur=sf::Color::Black;
                    break;
                case 1:
                    couleur=sf::Color::White;
                    break;
                case 2:
                    couleur=sf::Color::Blue;
                    break;
                case 3:
                    couleur=sf::Color::Red;
                    break;
                case 4:
                    couleur=sf::Color::Yellow;
                    break;
                case 5:
                    couleur=sf::Color::Green;
                    break;
                case 6:
                    couleur=sf::Color::Cyan;
                    break;
                case 7:
                    couleur=sf::Color::Magenta;
                    break;
                case 8:
                    couleur=sf::Color::Transparent;
                    break;
                case 9:
                    couleur=couleurs[i].getFillColor();
                    break;
            }
        
    }
}
int main()
{    
    sf::VertexArray pixels(sf::Points,NC*NL);
    sf::Color couleur = sf::Color::Black;
    init(pixels);
    int brushSize = 3;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML window");
    sf::RectangleShape* couleurs;
    sf::Vector2f oldPos;
    std::vector<action> taches;
    pile P =init_pile();
    bool first_time=true;
    bool full_mode=false;
    window.clear(sf::Color::White);
    window.setFramerateLimit(300);
    
        while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();


            if (event.type==sf::Event::KeyPressed)
            {
                touche(event,pixels,brushSize,P,full_mode,taches); 
            }
        }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {   
                float x=sf::Mouse::getPosition(window).x;
                float y=sf::Mouse::getPosition(window).y;
                selectCouleur(window,couleur,x,y,couleurs);
                if (full_mode)
                {
                    remplissage(pixels,couleur,sf::Vector2i(x,y),taches);
                }
                else
                {
                    if(first_time)
                    {
                        peint_ligne(pixels,sf::Vector2f(x,y),sf::Vector2f(x,y),brushSize,couleur,taches);
                        first_time=false;
                    }
                    else
                        peint_ligne(pixels,sf::Vector2f(x,y),oldPos,brushSize,couleur,taches);
                    oldPos={x,y};
                }
                
            }
            else
            {
                first_time=true;
                if (!taches.empty())
                {
                    empiler(P,taches);
                    taches.clear();
                }
                
            }
            
            window.clear(sf::Color::White);
            
            window.draw(pixels);
            HUD(window,couleurs);
            window.display();
        
 
        
    }
    return 0;
}