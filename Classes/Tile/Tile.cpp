#include "Tile.hpp"

/* Create rectangle shape with basic setup */
Tile::Tile(sf::Vector2f position, int size, sf::Color color) {
    tileSize = size;
    tilePosition = position;

    rect = new sf::RectangleShape();
    rect->setFillColor(color);
    rect->setPosition(position);
    rect->setSize(sf::Vector2f(size, size));
}

/* Render sprite on screen */
void Tile::drawSprite(sf::RenderWindow& window) {
    window.draw(*rect);
}
