#include <string>
#include <map>

#ifndef ASSIGN2_TILECODES_H
#define ASSIGN2_TILECODES_H

// Colours
#define RED    'R'
#define ORANGE 'O'
#define YELLOW 'Y'
#define GREEN  'G'
#define BLUE   'B'
#define PURPLE 'P'

// Shapes
#define CIRCLE    1
#define STAR_4    2
#define DIAMOND   3
#define SQUARE    4
#define STAR_6    5
#define CLOVER    6

const std::map<int, std::string> shapeMap = {
    {1, "\u25CF"},
    {2, "\u2726"},
    {3, "\u25C6"},
    {4, "\u25A0"},
    {5, "\u2736"},
    {6, "\u2724"}
};
const std::map<char, std::string> colourMap ={
    {'R', "91m"},
    {'O', "31m"},
    {'Y', "93m"},
    {'G', "92m"},
    {'B', "94m"},
    {'P', "95m"}
};

#endif // ASSIGN1_TILECODES_H
