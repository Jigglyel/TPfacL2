#include "game.h"
//charge les textures
void charge(sf::Texture &mec,sf::Texture &bank,sf::Texture &feu,sf::Texture &bullet,sf::Texture &zombie)
{
    mec.loadFromFile("../sprites/mec.png");
    feu.loadFromFile("../sprites/feu_de_camp.png");
    bank.loadFromFile("../sprites/bank.png");
    bullet.loadFromFile("../sprites/bullet.png");
    zombie.loadFromFile("../sprites/zombie.png");

}


void dessine(Perso joueur,objet bank,objet feu,sf::RenderWindow &window,cercle_faim cercle_f,int money,std::vector<Bullet> bullets,sf::Texture image_balle,std::vector<Zombie>zombies,sf::Texture image_zombie,sf::View camera)
{
    sf::Sprite joueurImage(joueur.image),bankImage(bank.image),feuImage(feu.image),balleImage(image_balle),zombieImage(image_zombie);
    sf::Text text_faim, text_dollar,text_vie;
    sf::Font font;
    if(!font.loadFromFile("../Jersey15-Regular.ttf"))
        std::cout<<"erreur du chargement de la police";
    text_faim.setPosition(1000,100);
    text_faim.setFillColor(sf::Color::Green);
    text_faim.setString(std::to_string(joueur.faim));
    text_faim.setFont(font);
    text_dollar.setPosition(600,800);
    text_dollar.setFillColor(sf::Color::Yellow);
    text_dollar.setString(std::to_string(money));
    text_dollar.setFont(font);
    text_vie.setPosition(200,100);
    text_vie.setFillColor(sf::Color::Red);
    text_vie.setString(std::to_string(static_cast<int>(joueur.hp)));
    text_vie.setFont(font);
    joueurImage.setPosition(joueur.x-16,joueur.y-16);
    bankImage.setPosition(bank.x-16,bank.y-16);
    feuImage.setPosition(feu.x-17,feu.y-20);
    window.clear(sf::Color::Black);
    for (Bullet balle : bullets)
    {
        balleImage.setPosition(balle.x-17,balle.y-17);
        window.draw(balleImage);
        
    }
    for (Zombie zombie : zombies)
    {
        zombie.hitbox.setOutlineColor(sf::Color::Red);
        zombieImage.setPosition(zombie.x-13,zombie.y-18);
        window.draw(zombieImage);
        //window.draw(zombie.hitbox);
        
    }
    joueur.hitbox.setOutlineColor(sf::Color::Red);
    for (size_t i = 0; i < (cercle_f.taille*2+1)*4; i++)
    {
        window.draw(cercle_f.pixels[i]);
    }
    sf::RectangleShape indicator_base=get_indicator_fire(feu,window,camera);
    indicator_base.setTexture(feuImage.getTexture());
    window.setView(camera);
    window.draw(bankImage);
    window.draw(feuImage);
    window.draw(joueurImage);  
    //window.draw(joueur.hitbox);
    window.setView(window.getDefaultView());
    window.draw(indicator_base);
    window.draw(text_vie);
    window.draw(text_faim); 
    window.draw(text_dollar);
    window.setView(camera);
    
}
    
    
void jeu(Perso joueur ,sf::RenderWindow &window)
{
    joueur.invincible=false;
    joueur.x=300;
    joueur.y=500;
    joueur.hp=20;
    joueur.faim=100;
    joueur.v=2;
    joueur.hitbox.setSize(sf::Vector2f(7,25));
    bool loose= false;
    objet feu, bank;
    std::vector<Bullet>bullets;
    Bullet balle;
    std::vector<Zombie>zombies;
    Zombie zombie;
    zombie.x=200;
    zombie.y=300;
    zombie.v=1;
    sf::View camera;
    camera.setCenter(joueur.x,joueur.y);
    float spawn_rate=5000;
    cercle_faim cercle_f;
    cercle_f.taille=100;
    int money=0;
    feu.x=300;
    feu.y=500;
    bank.x=100;
    bank.y=100;
    bool z=false,q=false,s=false,d=false,souris_pressee=false, sprint=false;
    charge(joueur.image,bank.image,feu.image,balle.image,zombie.image);
    cercle_f.pixels=get_cercle_faim(feu,cercle_f.taille,window);
    dessine(joueur,bank,feu,window,cercle_f,money,bullets,balle.image,zombies,zombie.image,camera);
    window.setView(camera);
    window.display();
    sf::Clock FoodGetClock,FoodLostClock,ZombieSpawnClock,InvicibilityClock;
    while (window.isOpen() and not loose)
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type==sf::Event::Resized)
            {
                camera.setSize(window.getSize().x,window.getSize().y);
                window.setView(camera);
            }
            if (event.type==sf::Event::KeyPressed)
            {
                if(event.key.code==sf::Keyboard::Z)
                    z=true;
                if(event.key.code==sf::Keyboard::Q)
                    q=true;
                if(event.key.code==sf::Keyboard::S)
                    s=true;
                if(event.key.code==sf::Keyboard::D)
                    d=true;
                if(event.key.code==sf::Keyboard::LShift)
                {
                    sprint=true;
                    joueur.v*=2;
                }

            }
            if (event.type==sf::Event::KeyReleased)
            {
                if(event.key.code==sf::Keyboard::Z)
                    z=false;
                if(event.key.code==sf::Keyboard::Q)
                    q=false;
                if(event.key.code==sf::Keyboard::S)
                    s=false;
                if(event.key.code==sf::Keyboard::D)
                    d=false;
                if(event.key.code==sf::Keyboard::LShift)
                {
                    sprint=false;
                    joueur.v/=2;
                }
                    
            }
            if(event.type==sf::Event::MouseButtonPressed)
                souris_pressee=true;
            if(event.type==sf::Event::MouseButtonReleased)
                souris_pressee=false;
        }
        //uptade de la position du joueur en fonction des touches pressées ou non
        
        if (z)
        {
            joueur.y-=joueur.v;
        }
        if (s)
        {
            joueur.y+=joueur.v;
        }
        if (q)
        {
            joueur.x-=joueur.v;
        }
        if (d)
        {
            joueur.x+=joueur.v;
        }
        joueur.hitbox.setPosition(joueur.x-7,joueur.y-8);
        camera.setCenter(joueur.x,joueur.y);
        //enlève l'incincibilité du joueur au bout de deux secondes
        if (joueur.invincible)
        {
            if (InvicibilityClock.getElapsedTime().asSeconds()>=2)
            {
                joueur.invincible=false;
            }
            
        }
        // récupère la trajectoire de la balle quand on clic
        if(souris_pressee)
        {
            get_balle(joueur.x,joueur.y,sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y,bullets,camera,window);
        }
        if (sqrt(abs(joueur.x-feu.x)*abs(joueur.x-feu.x)+abs(joueur.y-feu.y)*abs(joueur.y-feu.y))<cercle_f.taille)
        {
            if (joueur.faim<100 and FoodGetClock.getElapsedTime().asMilliseconds()>100)
            {
                FoodGetClock.restart();
                FoodLostClock.restart();
                joueur.faim++;
            }
        }
        else
            if (FoodLostClock.getElapsedTime().asMilliseconds()>1000)
            {
                FoodGetClock.restart();
                FoodLostClock.restart();
                joueur.faim--;
                if (sprint)
                {
                    joueur.faim--;
                }
                
            }
            
            
        // donne de la thune au joueur si il est près de la banque
        if (sqrt(abs(joueur.x-bank.x)*abs(joueur.x-bank.x)+abs(joueur.y-bank.y)*abs(joueur.y-bank.y))<cercle_f.taille)
        {
            money++;
        }
        
        // Clear screen
        window.clear(sf::Color::Black);
 
        // Draw the sprites
        dessine(joueur,bank,feu,window,cercle_f,money,bullets,balle.image,zombies,zombie.image,camera);
        //update les elements
        update_position_collisions(bullets,zombies,joueur,InvicibilityClock);
        if (ZombieSpawnClock.getElapsedTime().asMilliseconds()>spawn_rate)
            {
                ZombieSpawnClock.restart();
                zombie_spawn(zombies,joueur);
            }
        window.setView(camera);
        window.display();
        if (joueur.hp<=0 or joueur.faim<=0)
        {
            loose=true;
        }
        spawn_rate=spawn_rate-0.5;
    }
    while (window.isOpen() and loose)
    {
        window.setView(window.getDefaultView());
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type==sf::Event::KeyPressed)
            {
                if (event.key.code==sf::Keyboard::R)
                {
                    jeu(joueur,window);
                }
                
            }
            
        }
   
        sf::Text text_défaite;
        sf::Font font;
        if(!font.loadFromFile("../Jersey15-Regular.ttf"))
        std::cout<<"erreur du chargement de la police";
        text_défaite.setPosition(window.getSize().x/2,window.getSize().y/2);
        text_défaite.setFillColor(sf::Color::Red);
        text_défaite.setString("mort");
        text_défaite.setFont(font);
        window.clear(sf::Color::Black);
        
        window.draw(text_défaite);
        window.display();
    }
}







