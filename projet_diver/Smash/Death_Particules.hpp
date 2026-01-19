#include <SFML/Graphics.hpp>


class Death_particules
{
    public :
    sf::RectangleShape tri;
    int durée=90;
    sf::Vector2f speed;

    void apply_forces();
    void rebondit(sf::RenderWindow &window);
    void move();
    void affiche(sf::RenderWindow &window);
};