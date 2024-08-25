#include "Tile.h"
#include <map>
#include "TileCodes.h"

Tile::Tile(Colour colour, Shape shape) : colour(colour), shape(shape) {}

Colour Tile::getColour() const {
    return colour;
}

Shape Tile::getShape() const {
    return shape;
}

// Overload the << operator for the Tile class
std::ostream& operator<<(std::ostream& os, const Tile& tile) {
    os << tile.getColour() << tile.getShape();
    return os;
}

std::string Tile::print() {
    return colour + std::to_string(shape);
}

// This function checks if two Tile objects are equal.
bool Tile::operator==(const Tile& other) const {

    return colour == other.getColour() && shape == other.getShape();
}

// This function checks if two Tile objects are not equal.
bool Tile::operator!=(const Tile& other) const {

    return !(*this == other);
}

// This function checks if the tile has a match by color or shape, is the same or doesn't match at all
std::string Tile::matchType(const Tile& other)
{
    if (colour == other.getColour() && shape == other.getShape()) {
        return "same";
    }
    if (colour == other.getColour()) {
        return "color";
    }
    if (shape == other.getShape()) {
        return "shape";
    }
    return "no-match";
}

// This function prints the tile in enhanced mode
std::string Tile::enhancedPrint() {
    std::map<int, std::string> shapes = shapeMap;
    std::map<char, std::string> colours = colourMap;
    return " \033[" + colours[colour] + shapes[shape] + "\033[0m";
}