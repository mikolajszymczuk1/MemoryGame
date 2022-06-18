#include "Tile.hpp"

/* Default constructor */
Tile::Tile() { }

/* Create rectangle shape with basic setup */
Tile::Tile(sf::Vector2f position, int size, sf::Color color) {
    tileSize = size;
    tilePosition = position;
    tileColor = color;
    isDiscovered = false;

    rect = new sf::RectangleShape();
    rect->setFillColor(tileColor);
    rect->setPosition(tilePosition);
    rect->setSize(sf::Vector2f(tileSize, tileSize));
}

/* Render sprite on screen */
void Tile::drawSprite(sf::RenderWindow &window) {
    if (isDiscovered) window.draw(*rect);
}

/* Overload '=' operator */
Tile& Tile::operator=(const Tile *t) {
    if (t != this) {
        tileSize = t->tileSize;
        tilePosition = t->tilePosition;
        rect = t->rect;
        isDiscovered = t->isDiscovered;
    }

    return *this;
}

/* Return tile color */
sf::Color Tile::getTileColor() {
    return tileColor;
}

/* Return tile postion */
sf::Vector2f Tile::getTilePosition() {
    return tilePosition;
}

/* Return tile size */
int Tile::getTileSize() {
    return tileSize;
}

/* Return tile discover status */
bool Tile::getTileStatus() {
    return isDiscovered;
}

/* Set new color value for tile */
void Tile::setNewColor(sf::Color newColor) {
    tileColor = newColor;
    rect->setFillColor(tileColor);
}

/* Show or hide tile on board */
void Tile::setTileStatus(bool newStatus) {
    isDiscovered = newStatus;
}
