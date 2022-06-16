#include <SFML/Graphics.hpp>

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

    /* Window loop */
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    return 0;
}
