#include <SFML/Graphics.hpp>
#include "Classes/Tile/Tile.hpp"

/* Window configuration */
struct WindowConfig {
    int width = 600;
    int height = 600;
};

/* Main program */
int main() {
    /* Window setup */
    WindowConfig config;
    sf::RenderWindow window(sf::VideoMode(config.width, config.height), "Memory Game", sf::Style::Close);
    window.setFramerateLimit(60);  // 60 FPS

    /* Example shapes */
    Tile *tile1 = new Tile(sf::Vector2f(0, 0), 120, sf::Color::Magenta);
    Tile *tile2 = new Tile(sf::Vector2f(120, 0), 120, sf::Color::Green);

    /* Window loop */
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        /* Clear window before drawing */
        window.clear(sf::Color::White);

        /* -------------------------------------------------- */
        tile1->drawSprite(window);
        tile2->drawSprite(window);

        // Draw decoration grid
        for (int i = 0; i < 5; i++) {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(0.f, i * 120.f), sf::Color::Black),
                sf::Vertex(sf::Vector2f(600.f, i * 120.f), sf::Color::Black)
            };

            window.draw(line, 2, sf::Lines);
        }

        for (int i = 0; i < 5; i++) {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(i * 120.f, 0.f), sf::Color::Black),
                sf::Vertex(sf::Vector2f(i * 120.f, 600.f), sf::Color::Black)
            };

            window.draw(line, 2, sf::Lines);
        }

        /* -------------------------------------------------- */

        /* Display all rendered elements */
        window.display();
    }

    return 0;
}
