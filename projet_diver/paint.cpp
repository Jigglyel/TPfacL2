#include<iostream>
#include<array>
#include<cstdlib>
#include<ctime>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<string>
#include<cmath>
const int NC=1280;
const int NL=720;
using Tligne=std::array<uint8_t ,NC>;
using Timage=std::array<Tligne,NL>;


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
void peint_pixel(sf::VertexArray &pixels,int x,int y,int brushSize,sf::Color couleur)
{
    for (int dy = -brushSize; dy <= brushSize; ++dy)
        for (int dx = -brushSize; dx <= brushSize; ++dx)
        {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < NC && ny >= 0 && ny < NL)
                pixels[ny * NC + nx].color = couleur;
        }
}
void peint_ligne(sf::VertexArray &pixels,sf::Vector2f curent,sf::Vector2f old,int brushSize,sf::Color couleur)
{
    float dx= curent.x-old.x;
    float dy= curent.y-old.y;
    float distance=std::sqrt(dx*dx+dy*dy);
    if(distance==0)
        distance=1;
    float x=old.x, y=old.y;
    for(int i=0 ;i<distance;++i)
    {
        peint_pixel(pixels,x,y,brushSize,couleur);
        x+=dx/distance;
        y+=dy/distance;
    }
}
void touche(sf::Event event,sf::VertexArray & pixels,int &brushSize)
{
    if (event.key.code==sf::Keyboard::Space)
    {
        // Clear screen
        init(pixels);
    } 
    if (event.key.code==sf::Keyboard::Add)
    {
        brushSize++;
    }
    if (event.key.code==sf::Keyboard::Subtract)
    {
        brushSize--;
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
    bool first_time=true;
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
                touche(event,pixels,brushSize); 
            }
        }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {   
                float x=sf::Mouse::getPosition(window).x;
                float y=sf::Mouse::getPosition(window).y;
                selectCouleur(window,couleur,x,y,couleurs);
                if(first_time)
                {
                    peint_ligne(pixels,sf::Vector2f(x,y),sf::Vector2f(x,y),brushSize,couleur);
                    first_time=false;
                }
                else
                    peint_ligne(pixels,sf::Vector2f(x,y),oldPos,brushSize,couleur);
                oldPos={x,y};
                
            }
            else
            {
                first_time=true;
            }
            
            window.clear(sf::Color::White);
            
            window.draw(pixels);
            HUD(window,couleurs);
            window.display();
        
 
        
    }
    return 0;
}