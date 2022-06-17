#include <SFML/Graphics.hpp>

/* Tile class */
class Tile {
    private:
        int tileSize;
        sf::Vector2f tilePosition;
        sf::RectangleShape *rect;
    public:
        Tile(sf::Vector2f position, int size, sf::Color color);
        void drawSprite(sf::RenderWindow& window);
};
