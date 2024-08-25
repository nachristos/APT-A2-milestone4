#ifndef ASSIGN2_GAMEBOARD_H
#define ASSIGN2_GAMEBOARD_H

#include <vector>
#include <string>
#include "Tile.h"
#include <map>

class GameBoard {
public:
    GameBoard();
    GameBoard(int rows, int cols);
    ~GameBoard();
    // Copy constructor
    GameBoard(const GameBoard& other);

    // Copy assignment operator
    GameBoard& operator=(const GameBoard& other);

    // Move constructor
    GameBoard(GameBoard&& other);

    // Move assignment operator
    GameBoard& operator=(GameBoard&& other);

    // Place a tile at a specific position
    void placeTile(int row, int col, Tile* tile);

    // Get the tile at a specific position
    Tile* getTile(int row, int col) const;

    // Display the board
    std::string displayBoard() const;

    // Getters for rows and cols
    int getRows() const;
    int getCols() const;

    // Check if the board is empty
    bool isEmpty() const;

    // Resize the board
    void resize(int rows, int cols);
    
    // Set the enhanced mode
    void setEnhancedMode(bool enhancedMode);
    // Get the enhanced mode
    bool getEnhancedMode() const;
private:    
    int rows;
    int cols;
    std::vector<std::vector<Tile*>> board;
    bool enhancedMode;
};

#endif // ASSIGN2_GAMEBOARD_H
