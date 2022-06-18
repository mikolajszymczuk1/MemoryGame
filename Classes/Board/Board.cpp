#include "Board.hpp"

/* Generate board with tiles */
Board::Board(int size, int tileSize, sf::Color *colorsPalette, int colorsPaletteLength) {
    boardSize = size;
    
    // Generate board
    boardArr = new Tile *[boardSize];
    for (int i = 0; i < boardSize; i++) {
        boardArr[i] = new Tile[boardSize];
        for (int j = 0; j < boardSize; j++) {
            boardArr[i][j] = new Tile(sf::Vector2f(j * tileSize, i * tileSize), tileSize, sf::Color::Black);
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
bool Board::discoverTile(sf::Vector2i position) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            sf::Vector2i tilePosition = (sf::Vector2i)boardArr[i][j].getTilePosition();

            if (isCursorOnTile(position, tilePosition, boardArr[i][j].getTileSize()) && !boardArr[i][j].getTileStatus()) {
                boardArr[i][j].setTileStatus(true);
                return true;
            }
        }
    }

    return false;
}

/* Return true if mouse cursor correctly click the tile */
bool Board::isCursorOnTile(sf::Vector2i mousePosition, sf::Vector2i tilePosition, int tileSize) {
    if (mousePosition.x > tilePosition.x && mousePosition.x < (tilePosition.x + tileSize) &&
    mousePosition.y > tilePosition.y && mousePosition.y < (tilePosition.y + tileSize)) {
        return true;
    }

    return false;
}

/* Get information about tile cords x[j], y[i] */
void Board::getTileCords(sf::Vector2i position, TileCords &tileCords) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            sf::Vector2i tilePosition = (sf::Vector2i)boardArr[i][j].getTilePosition();

            if (isCursorOnTile(position, tilePosition, boardArr[i][j].getTileSize())) {
                tileCords.x = j;
                tileCords.y = i;
            }
        }
    }
}

/* Return color from tile that cursor is on it */
void Board::compareTwoTiles(TileCords tileACords, TileCords tileBCords) {
    sf::Color tileAColor = boardArr[tileACords.y][tileACords.x].getTileColor();
    sf::Color tileBColor = boardArr[tileBCords.y][tileBCords.x].getTileColor();

    if (tileAColor != tileBColor) {
        boardArr[tileACords.y][tileACords.x].setTileStatus(false);
        boardArr[tileBCords.y][tileBCords.x].setTileStatus(false);
    }
}

/* Return true if all tiles are discovered */
bool Board::checkIfUserWon() {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (!boardArr[i][j].getTileStatus()) return false;
        }
    }

    return true;
}
