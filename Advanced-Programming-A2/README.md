# Advanced-Programming-A2
Advanced-Programming-A2

To Compile: 

 `make`<br>
 
OR<br>
 g++ -Wall -Wextra -std=c++14 -O -o qwirkle qwirkle.cpp Tile.cpp Node.cpp LinkedList.cpp TileBag.cpp Player.cpp FileHandler.cpp Rules.cpp InputValidator.cpp Student.cpp GameBoard.cpp Tests.cpp Ai.cpp
 
To Run: `./qwirkle.exe`<br>
Run with AI and enhanced tiles: `./qwirkle.exe --ai --e`
 
To clean up: `make clean`
 
Run unit tests: `./qwirkle.exe test`

Make tests executabe and run: `chmod +x ./tests/run && ./tests/run`

Or run individually:<br>
 `./tests/credits/test` Test credits menu<br>
 `./tests/qwirkle/test` Test scoring a QWIRKLE<br>
 `./tests/load-game/test` Test loading game<br>
 `./tests/new-game/test` Test create new game<br>
 `./tests/save-game/test` Test saving game<br>
 `./tests/game-end/test` Test game ends when tiles run out<br>
 `./tests/line-validation/test` Test tile placement is valid based on neighboring tiles<br>
 `./tests/ai-load-game/test` Test continuing AI game from save<br>
 `./tests/ai-new-game/test` Test beginning new AI game with --ai flag<br>
 `./tests/enhanced-new-game/test` Test enhanced tiles<br>
 
 **Individual Enhancements**
 
 AI second player mode - This feature can be enabled by inlcluding the --ai flag when running tha app eg: `./qwirkle.exe --ai`<br>
 Tests have been included to validate this new functionality:<br> `./tests/ai-load-game/test` test validates loading a saved AI game without declaring --ai arguments at runtime.
This test also validates the AI player will replace a tile when there is no valid moves.
`./tests/ai-new-game/test` Tests new game started with AI player 2 by runtime flag --ai
This test also validates the AI player choses the move that will earn it the highest score.

Tile colours and unicode tile symbols - THis feature adds styling to the displayed tiles. When this feature is activated with the --e flag (`./qwirkle.exe --e`), tiles on the GameBoard and in the players hand will be rendered with colours and symbols. A unit test has been added that validates the enhanced tile printing via the linked list enhancedPrint function. Also,the `./tests/enhanced-new-game/test` test has been included to validate this new functionality.

Note, both flags can be used together and order of declaration is not important: `./qwirkle.exe --ai --e`
 
 
 
 
 
