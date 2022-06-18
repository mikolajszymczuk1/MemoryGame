#include "../Tile/Tile.hpp"
#include "../../Structures/TileCords/TileCords.hpp"
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
        bool discoverTile(sf::Vector2i position);
        bool isCursorOnTile(sf::Vector2i mousePosition, sf::Vector2i tilePostion, int tileSite);
        void getTileCords(sf::Vector2i position, TileCords &tileCords);
        void compareTwoTiles(TileCords tileACords, TileCords tileBCords);
        bool checkIfUserWon();
};
