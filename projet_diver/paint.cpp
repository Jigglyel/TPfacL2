#include<iostream>
#include<array>
#include<cstdlib>
#include<ctime>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<string>
const int NC=1280;
const int NL=720;
using Tligne=std::array<uint8_t ,NC>;
using Timage=std::array<Tligne,NL>;


void init (sf::VertexArray & pixels)
{
                    for (size_t i = 0; i < NL; i++)
                    {
                        for (size_t j = 0; j < NC; j++)
                        {
                            pixels[i * NC + j].position = sf::Vector2f(j, i);
                            pixels[i * NC + j].color = sf::Color(255,255,255);
                        }
                    }
}
int main()
{    
    sf::VertexArray pixels(sf::Points,NC*NL);
    
    init(pixels);
    int brushSize = 3;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML window");
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
        }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                int x= sf::Mouse::getPosition(window).x;
                int y= sf::Mouse::getPosition(window).y;
                  // taille du pinceau (demi-largeur)
                for (int dy = -brushSize; dy <= brushSize; ++dy)
                    for (int dx = -brushSize; dx <= brushSize; ++dx)
                    {
                        int nx = x + dx;
                        int ny = y + dy;
                        if (nx >= 0 && nx < NC && ny >= 0 && ny < NL)
                            pixels[ny * NC + nx].color = sf::Color::Black;
                    }
    
            }
            window.clear(sf::Color::White);
            window.draw(pixels);
            window.display();
        
 
        
    }
}