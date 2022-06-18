#include <SFML/Graphics.hpp>

/* Tile class */
class Tile {
    private:
        int tileSize;
        bool isDiscovered = false;
        sf::Color tileColor;
        sf::Color coveringColor;
        sf::Vector2f tilePosition;
        sf::RectangleShape *rect;
        void updateColor();
    public:
        Tile();
        Tile(sf::Vector2f position, int size, sf::Color color);
        void drawSprite(sf::RenderWindow &window);
        Tile& operator=(const Tile *t);
        sf::Color getTileColor();
        sf::Vector2f getTilePosition();
        int getTileSize();
        void setNewColor(sf::Color newColor);
        void setTileStatus(bool newStatus);
};
