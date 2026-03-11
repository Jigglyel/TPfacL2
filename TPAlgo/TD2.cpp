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

struct Maillon
{
    int val;
    int nb;
    Maillon*suiv;
};

using Ligne= Maillon*;

using Limage=std::array<Ligne,NL>;

void ajoutfin(Ligne &L,int val,int nb)
{
    if (L==nullptr)
    {
        L=new Maillon;
        L->nb=nb;
        L->val=val;
        L->suiv=nullptr;
    }
    else
    ajoutfin(L->suiv,val,nb);
    
}

Ligne compresseL(Tligne M)
{
    Ligne L=nullptr;
    int val=M[0];
    int count=0;
    for (size_t i = 0; i < NC; i++)
    {
        if (val!=M[i])
        {
            ajoutfin(L,val,count);
            val=M[i];
            count=1;
        }
        else
        {
            count++;
        }
    }
    
    return L;
}

Limage compresse(Timage M)
{
    Limage T;
    for (size_t i = 0; i < NL; i++)
    {
        T[i]=compresseL(M[i]);
    }
    return T;
}

Timage genere()
{
    Timage M;
    int val=rand()%256;
    for (size_t i = 0; i < NL; i++)
    {
        for (size_t j = 0; j < NC; j++)
        {
            if (rand()%100==0)
            {
                val=rand()%256;
            }
            M[i][j]=val;
        }
        
    }
    return M;
}
Timage R,G,B;
int main()
{    

    
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML window");
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
                    window.clear();
                    srand(time(NULL));
                    R=genere();
                    G=genere();
                    B=genere();
                    sf::VertexArray pixels(sf::Points, NC * NL);
                    for (size_t i = 0; i < NL; i++)
                    {
                        for (size_t j = 0; j < NC; j++)
                        {
                            pixels[i * NC + j].position = sf::Vector2f(j, i);
                            pixels[i * NC + j].color = sf::Color(R[i][j], G[i][j], B[i][j]);
                        }
                    }
                    window.draw(pixels);
                    // Update the window
                    window.display();
                }
                
            }
            
        }
 
        
    }
}