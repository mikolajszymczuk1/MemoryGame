#include <SFML/Graphics.hpp>
#include "Classes/Board/Board.hpp"
#include "Structures/WindowConfig/WindowConfig.hpp"
#include <time.h>

/* Declarations */

void drawGrid(sf::RenderWindow &window, float windowSize, int size, float tileSize, sf::Color color);
void gameUpdate();

/* ------------ */

/* Main program */
int main() {
    srand(time(NULL));  // Seed for random functions

    /* Variables */
    const int MAX_DISCOVERED_TILES = 2;
    const int DELAY_BETWEEN_EACH_GUESS = 1;  // In seconds
    bool isMouseButtonClicked = false;
    bool isWon = false;
    int discoveredTiles = 0;
    TileCords tileA;
    TileCords tileB;
    sf::Clock clock;

    /* Window setup */
    WindowConfig config;
    sf::RenderWindow window(sf::VideoMode(config.width, config.height), "Memory Game", sf::Style::Close);
    window.setFramerateLimit(60);  // 60 FPS

    /* Font setup */
    sf::Font font;
    font.loadFromFile("Fonts/Fascinate-Regular.ttf");

    /* Text setup */
    sf::Text winText;
    winText.setFont(font);
    winText.setString("You won !");
    winText.setCharacterSize(70);
    winText.setFillColor(sf::Color::Black);
    winText.setPosition(
        sf::Vector2f(
            (config.width / 2) - (winText.getLocalBounds().width / 2),
            (config.height / 2) - (winText.getLocalBounds().height))
    );

    /* Create game board */
    sf::Color colorsPalette[18] = {  // Colors palette
        sf::Color(184, 36,  94),
        sf::Color(214, 67,  49),
        sf::Color(255, 153, 52),
        sf::Color(249, 209, 0),
        sf::Color(175, 184, 59),
        sf::Color(127, 204, 74),
        sf::Color(43,  148, 56),
        sf::Color(104, 205, 186),
        sf::Color(20,  143, 174),
        sf::Color(150, 195, 236),
        sf::Color(64,  115, 255),
        sf::Color(136, 77,  255),
        sf::Color(172, 59,  228),
        sf::Color(237, 149, 236),
        sf::Color(224, 81,  147),
        sf::Color(255, 140, 133),
        sf::Color(128, 128, 128),
        sf::Color(22,  170, 244)
    };

    Board *gameBoard = new Board(6, 100, colorsPalette, 18);

    /* Window loop */
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        /* Do all game logic */

        /* -------------------------------------------------- */

        if (discoveredTiles < MAX_DISCOVERED_TILES) {
            clock.restart();  // Restart clock

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !isMouseButtonClicked) {
                isMouseButtonClicked = true;
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    
                if (gameBoard->discoverTile(mousePosition)) {
                    if (discoveredTiles == 0) {
                        gameBoard->getTileCords(mousePosition, tileA);     
                    } else {
                        gameBoard->getTileCords(mousePosition, tileB);
                    }

                    discoveredTiles++;
                }
            } else {
                isMouseButtonClicked = false;
            }
        } else {
            // Create small delay between each guess
            sf::Time delay = clock.getElapsedTime();
            if (delay.asSeconds() > DELAY_BETWEEN_EACH_GUESS) {
                gameBoard->compareTwoTiles(tileA, tileB);
                if (gameBoard->checkIfUserWon()) isWon = true;
                discoveredTiles = 0;
            }
        }

        /* -------------------------------------------------- */

        /* Clear window before drawing */
        window.clear(sf::Color::White);

        /* -------------------------------------------------- */

        // Render all tiles on screen
        gameBoard->drawTiles(window);

        // Draw decoration grid
        drawGrid(window, config.width, 6, 100, sf::Color::Black);

        // If player won, draw a text
        if (isWon) window.draw(winText);

        /* -------------------------------------------------- */

        /* Display all rendered elements */
        window.display();
    }

    return 0;
}

/* Helper Functions */

/* Draw grid (n x n) with specific tile size */
void drawGrid(sf::RenderWindow &window, float windowSize, int size, float tileSize, sf::Color color) {
    for (int i = 0; i < size; i++) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(0.f, i * tileSize), color),
            sf::Vertex(sf::Vector2f(windowSize, i * tileSize), color)
        };

        window.draw(line, 2, sf::Lines);
    }

    for (int i = 0; i < size; i++) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(i * tileSize, 0.f), color),
            sf::Vertex(sf::Vector2f(i * tileSize, windowSize), color)
        };

        window.draw(line, 2, sf::Lines);
    }
}
