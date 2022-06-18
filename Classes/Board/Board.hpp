#include "../Tile/Tile.hpp"
#include <SFML/Graphics.hpp>

/* Board class */
class Board {
    private:
        int boardSize;
        Tile **boardArr;
    public:
        Board(int size, int tileSize, sf::Color *colorsPalette, int colorsPaletteLength);
        ~Board();
        void drawTiles(sf::RenderWindow &window);
        static int randomNumber(int min, int max);
        void discoverTile(sf::Vector2i position);
};
