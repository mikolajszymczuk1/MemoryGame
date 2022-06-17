#include <SFML/Graphics.hpp>

/* Tile class */
class Tile {
    private:
        int tileSize;
        sf::Color tileColor;
        sf::Vector2f tilePosition;
        sf::RectangleShape *rect;
    public:
        Tile();
        Tile(sf::Vector2f position, int size, sf::Color color);
        void drawSprite(sf::RenderWindow &window);
        Tile& operator=(const Tile *t);
        sf::Color getTileColor();
        void setNewColor(sf::Color newColor);
};
