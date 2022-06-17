#include "Tile.hpp"

/* Default constructor */
Tile::Tile() { }

/* Create rectangle shape with basic setup */
Tile::Tile(sf::Vector2f position, int size, sf::Color color) {
    tileSize = size;
    tilePosition = position;
    tileColor = color;

    rect = new sf::RectangleShape();
    rect->setFillColor(tileColor);
    rect->setPosition(tilePosition);
    rect->setSize(sf::Vector2f(tileSize, tileSize));
}

/* Render sprite on screen */
void Tile::drawSprite(sf::RenderWindow &window) {
    window.draw(*rect);
}

/* Overload '=' operator */
Tile& Tile::operator=(const Tile *t) {
    if (t != this) {
        tileSize = t->tileSize;
        tilePosition = t->tilePosition;
        rect = t->rect;
    }

    return *this;
}

/* Return tile color */
sf::Color Tile::getTileColor() {
    return tileColor;
}

/* Set new color value for tile */
void Tile::setNewColor(sf::Color newColor) {
    tileColor = newColor;
    rect->setFillColor(newColor);
}
