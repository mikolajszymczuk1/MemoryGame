#include "Board.hpp"

/* Generate board with tiles */
Board::Board(int size, int tileSize, sf::Color *colorsPalette, int colorsPaletteLength) {
    boardSize = size;
    
    // Generate board
    boardArr = new Tile *[boardSize];
    for (int i = 0; i < boardSize; i++) {
        boardArr[i] = new Tile[boardSize];
        for (int j = 0; j < boardSize; j++) {
            boardArr[i][j] = new Tile(sf::Vector2f(i * tileSize, j * tileSize), tileSize, sf::Color::Black);
        }
    }

    /* Set new colors for all tiles */
    for (int i = 0; i < colorsPaletteLength; i++) {
        int colorsToPlace = 2;
        while (colorsToPlace > 0) {
            int y = Board::randomNumber(0, boardSize - 1);
            int x = Board::randomNumber(0, boardSize - 1);
            if (boardArr[y][x].getTileColor() == sf::Color::Black && boardArr[y][x].getTileColor() != colorsPalette[i]) {
                boardArr[y][x].setNewColor(colorsPalette[i]);
                colorsToPlace--;
            }
        }
    }
}

/* Make free space (Delete 2d Tile array) */
Board::~Board() {
    delete []boardArr;
}

/* Render all tiles on screen */
void Board::drawTiles(sf::RenderWindow &window) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            boardArr[i][j].drawSprite(window);
        }
    }
}

/* Static method that return random number between [min, max] */
int Board::randomNumber(int min, int max) {
    return min + rand() % (( max + 1 ) - min);
}

/* Show real tile color on tile with postion 'postion' */
void Board::discoverTile(sf::Vector2i position) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            Tile currentTile = boardArr[i][j];
            sf::Vector2i tilePosition = (sf::Vector2i)currentTile.getTilePosition();

            if (position.x > tilePosition.x && position.x < (tilePosition.x + currentTile.getTileSize()) &&
            position.y > tilePosition.y && position.y < (tilePosition.y + currentTile.getTileSize())) {
                currentTile.setTileStatus(true);
            }
        }
    }
}
