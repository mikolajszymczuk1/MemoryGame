#include "Tile.hpp"

/* Default constructor */
Tile::Tile() { }

/* Create rectangle shape with basic setup */
Tile::Tile(sf::Vector2f position, int size, sf::Color color) {
    tileSize = size;
    tilePosition = position;
    tileColor = color;
    coveringColor = sf::Color::White;

    rect = new sf::RectangleShape();
    rect->setFillColor(coveringColor);
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

/* Return tile postion */
sf::Vector2f Tile::getTilePosition() {
    return tilePosition;
}

/* Return tile size */
int Tile::getTileSize() {
    return tileSize;
}

/* Set new color value for tile */
void Tile::setNewColor(sf::Color newColor) {
    tileColor = newColor;
}

/* Based on isDiscoverd property set color on tail */
void Tile::updateColor() {
    rect->setFillColor(isDiscovered ? tileColor : coveringColor);
}

/* Show or hide tile on board */
void Tile::setTileStatus(bool newStatus) {
    isDiscovered = newStatus;
    updateColor();
}