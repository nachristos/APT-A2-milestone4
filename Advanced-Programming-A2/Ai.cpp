#include "Ai.h"
#include "GameBoard.h"
#include "Player.h"
#include "TileBag.h"
#include "Rules.h"

        void Ai::placeTile(GameBoard* board, Player* player, int x, int y, Tile* tile, int score){
            // Place the best tile
            board->placeTile(x, y, tile);
            // Remove the tile from the player's hand
            player->removeTileFromHand(tile);
            player->setScore(player->getScore() + score);
            std::cout << "\nMR ROBOTO played: " << tile->print() << " at " << char(x + 'A') << y << " for a score of " << score << std::endl;
        }

        
        void Ai::calculateMove(GameBoard* board, Player* player, TileBag* tileBag){
            // Get the player's hand
            LinkedList* hand = player->getHand();
            Node *tile = hand->getHead();
            
            if (board->isEmpty()) {
                // Place the first tile in the middle of the board
                placeTile(board, player, board->getRows() / 2, board->getCols() / 2, tile->getTile(), 1);
                return;
            }

            int bestX;
            int bestY;
            int bestScore = 0;
            Node *bestTile;
                
            // Loop through the player's hand
            while (tile != nullptr) {
                // Loop through the board
                for (int i = 0; i >= 0 && i < board->getRows(); ++i) {
                    for (int j = 0; j >= 0 && j < board->getCols(); ++j) {
                        // Check if the move is valid
                        if (Rules::validateMove(board, tile->getTile(), i, j)) {
                            // Place the tile                            
                            board->placeTile(i, j, tile->getTile());

                            int currentScore = (Rules::calculateScore(board, i, j));
                            if (currentScore > bestScore) {
                                bestX = i;
                                bestY = j;
                                bestScore = currentScore;
                                bestTile = tile;
                            }
                            board->placeTile(i, j, nullptr);
                        }
                    }
                }
                if (tile->getNext() == nullptr){         
                    if (bestScore > 0) {          
                    placeTile(board, player, bestX, bestY, bestTile->getTile(), bestScore);
                    } else {
                        // No valid moves, draw a tile
                        std::cout << "\nMR ROBOTO drew a tile from the tilebag.\n" << std::endl;
                        Tile* newTile = tileBag->drawTile();
                        if (newTile != nullptr)
                        {
                            player->addTileToHand(newTile);
                            player->removeTileFromHand(tile->getTile());
                            tileBag->addTile(tile->getTile());
                        }
                    }
                }
                tile = tile->getNext();
            }            
        };
        
        void Ai::playTurn(Player* player, TileBag* tileBag, GameBoard* board){

            calculateMove(board, player, tileBag);
            
            Tile* newTile = tileBag->drawTile();
            if (newTile != nullptr)
            {
                player->addTileToHand(newTile);
            }
        };