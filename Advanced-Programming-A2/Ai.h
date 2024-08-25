#include "GameBoard.h"
#include "Player.h"
#include "TileBag.h"

class Ai {
    public:
        static void playTurn(Player *player, TileBag *tileBag, GameBoard *board);
    private:
        static void calculateMove(GameBoard* board, Player* player, TileBag* tileBag);
        static void placeTile(GameBoard* board, Player* player, int x, int y, Tile* tile, int score);
};