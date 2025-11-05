#include "game.h"
//charge les textures
void charge(sf::Texture &mec,sf::Texture &bank,sf::Texture &feu,sf::Texture &bullet,sf::Texture &zombie,sf::Texture &etabli)
{
    mec.loadFromFile("../../sprites/mec.png");
    feu.loadFromFile("../../sprites/feu_de_camp.png");
    bank.loadFromFile("../../sprites/bank.png");
    bullet.loadFromFile("../../sprites/bullet.png");
    zombie.loadFromFile("../../sprites/zombie.png");
    etabli.loadFromFile("../../sprites/etabli.png");

}
void init_text_pause(sf::RenderWindow &window,sf::Text &resu)
{
    resu.setFillColor(sf::Color::White);
    resu.setPosition(window.getSize().x/2.f,window.getSize().y/2.f);
    sf::Font font;
    if(!font.loadFromFile("../../Jersey15-Regular.ttf"))
        std::cout<<"erreur du chargement de la police";
    resu.setFont(font);
    resu.setString("PAUSE");
}
void dessine(Perso joueur,objet bank,objet feu,objet etabli,sf::RenderWindow &window,cercle_faim cercle_f,int money,std::vector<Bullet> bullets,sf::Texture image_balle,std::vector<Zombie>zombies,sf::Texture image_zombie,sf::View &camera)
{
    sf::Sprite joueurImage(joueur.image),bankImage(bank.image),feuImage(feu.image),balleImage(image_balle),zombieImage(image_zombie),etabliImage(etabli.image);
    sf::Text text_faim, text_dollar,text_vie;
    sf::Font font;
    if(!font.loadFromFile("../../Jersey15-Regular.ttf"))
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
    etabliImage.setPosition(etabli.x-17,etabli.y-16);
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
    window.draw(bankImage);
    window.draw(etabliImage);
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
void init(Perso &joueur, objet &feu,objet &bank,objet &etabli,Zombie &zombie,sf::View &camera,sf::RenderWindow &window,float &spawn_rate,cercle_faim &cercle_f,Bullet &balle,sf::Text &text_pause,weapon &arme)
{
    joueur.invincible=false;
    joueur.x=300;
    joueur.y=500;
    joueur.hp=20;
    joueur.faim=100;
    joueur.v=2;
    joueur.hitbox.setSize(sf::Vector2f(7,25));
    zombie.x=200;
    zombie.y=300;
    zombie.v=1;
    camera.setCenter(joueur.x,joueur.y);
    camera.setSize(sf::Vector2f(window.getSize()));
    window.setView(camera);
    spawn_rate=5000;
    cercle_f.taille=100;
    feu.x=300;
    feu.y=500;
    bank.x=500;
    bank.y=300;
    etabli.x=100;
    etabli.y=100;
    feu.x=300;
    feu.y=500;
    bank.x=500;
    bank.y=300;
    etabli.x=100;
    etabli.y=100;
    arme.dégats=2;
    arme.tear_rate=5000;
    arme.id=0;
    charge(joueur.image,bank.image,feu.image,balle.image,zombie.image,etabli.image);
    cercle_f.pixels=get_cercle_faim(feu,cercle_f.taille,window);
    init_text_pause(window,text_pause);
}
    
void jeu(Perso joueur ,sf::RenderWindow &window)
{   
    //definition des classes
    objet feu, bank,etabli;
    std::vector<Bullet>bullets;
    Bullet balle;
    Zombie zombie;
    std::vector<Zombie>zombies; 
    sf::View camera;
    cercle_faim cercle_f;
    sf::Text text_pause ;
    //mise en place des constantes
    float spawn_rate=5000; 
    int money=0;
    weapon arme;
    bool z=false, q=false, s=false, d=false, souris_pressee=false, sprint=false, loose= false, in_crafting=false, pause=false;
    init(joueur,feu,bank,etabli,zombie,camera,window,spawn_rate,cercle_f,balle,text_pause,arme);
    int vitesse_de_base=joueur.v;
    dessine(joueur,bank,feu,etabli,window,cercle_f,money,bullets,balle.image,zombies,zombie.image,camera);
    window.display();
    sf::Clock FoodGetClock,FoodLostClock,ZombieSpawnClock,InvicibilityClock,TearRateClock;
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
                camera.setSize(sf::Vector2f(window.getSize()));
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
                }
                if(event.key.code==sf::Keyboard::Enter)
                    if (sqrt(abs(joueur.x-etabli.x)*abs(joueur.x-etabli.x)+abs(joueur.y-etabli.y)*abs(joueur.y-etabli.y))<20)
                    {
                        if (in_crafting)
                        {
                            in_crafting=false;
                        }
                        else
                            in_crafting=true;
                    }
                if(event.key.code==sf::Keyboard::P)
                    pause=!pause;
                    

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
                }
                    
            }
            if(event.type==sf::Event::MouseButtonPressed)
                souris_pressee=true;
            if(event.type==sf::Event::MouseButtonReleased)
                souris_pressee=false;
        }
        if (in_crafting)
        {
            z=false;q=false;s=false;d=false;
            
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                window.close();

                if (event.type==sf::Event::Resized)
                {
                    camera.setSize(sf::Vector2f(window.getSize()));
                    window.setView(camera);
                }

                //truc de craft
                if (event.type==sf::Event::KeyPressed)
                {
                    if(event.key.code==sf::Keyboard::Q)
                    {
                        if (money>=100)
                        {
                            std::cout<<"j'ai acheté du tear rate"<<std::endl;
                            arme.tear_rate-=300;
                            money-=100;
                        }
                        else
                            std::cout<<"pas assez d'argent"<<std::endl;
                        
                        
                    }
                    if(event.key.code==sf::Keyboard::D)
                    {
                    if (money>=100)
                        {
                            std::cout<<"j'ai acheté des dégats rate"<<std::endl;
                            arme.dégats+=1;
                            money-=100;
                        }
                        else
                            std::cout<<"pas assez d'argent"<<std::endl;
                    }
                }
            }
        }
        else
        if (pause)
        {   window.getDefaultView();
            window.draw(text_pause);
            window.display();
            window.setView(camera);
        }
        else
        {

        //uptade de la position du joueur en fonction des touches pressées ou non
        update_pos_joueur(joueur,z,q,s,d,sprint,vitesse_de_base);
        //update de la hitbox et de la cam
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
        if(souris_pressee and TearRateClock.getElapsedTime().asMilliseconds()>arme.tear_rate)
        {
            TearRateClock.restart();
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
        dessine(joueur,bank,feu,etabli,window,cercle_f,money,bullets,balle.image,zombies,zombie.image,camera);
        //update les elements
        update_position_collisions(bullets,zombies,joueur,InvicibilityClock,arme);
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
}
    //quand le joueur perd
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
        if(!font.loadFromFile("../../Jersey15-Regular.ttf"))
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







