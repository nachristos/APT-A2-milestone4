#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

#include <iostream>
#include <string>


typedef char Colour;
typedef int Shape;

class Tile {
public:

    Tile(Colour colour, Shape shape);

    Colour getColour() const;
    Shape getShape() const;
    std::string print();

    // Function to overload the << operator
    friend std::ostream& operator<<(std::ostream& os, const Tile& tile);

    // Equality operator for Tile comparison
    bool operator==(const Tile& other) const;

    // Inequality operator for Tile comparison
    bool operator!=(const Tile& other) const;
    
    // Function to check if the tile has a match by color or shape
    std::string matchType(const Tile& other);
    
    // Function to print the tile in enhanced mode
    std::string enhancedPrint();

private:
    Colour colour;
    Shape shape;
};

#endif // ASSIGN2_TILE_H
