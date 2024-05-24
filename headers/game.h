#pragma once
#include "grid.h"
#include "../blocktypes.cpp"

class Game 
{
  public:
    Game();
    ~Game();
    Grid grid;
    double lastUpdate;
    bool gameOver;
    int score;
    Music bgMusic;
    void handleInput();
    void moveBlockDown();
    void draw();
    bool elapsedTimeEventTriggered(double interval);

  private:
    Block getRandomBlock();
    std::vector<Block> getAllBlocks();
    bool blockOutOfBounds();
    void rotateBlock();
    void lockBlockToGrid();
    void resetGame();
    void updateScore(int linesCleared);
    bool lockBlockToFilledCell();
    void moveBlockLeft();
    void moveBlockRight();
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    Sound clearSound;
};