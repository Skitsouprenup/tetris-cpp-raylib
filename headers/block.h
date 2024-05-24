#pragma once
#include <vector>
#include <map>
#include <string>

#include "position.h"
#include "colors.h"

class Block
{
  public:
    Block();
    int color;
    std::map<std::string, std::vector<Position>> cells;
    void drawBlock(int offsetX, int offsetY);
    void move(int rows, int columns);
    void rotate();
    void revertRotate();
    std::vector<Position> getCellsPosition();

  private:
    int cellSize;
    int currPosIndex;
    std::string blockPos;
    std::vector<std::string> posList;
    std::vector<Color> colors;
    /*
      The cell that these two offsets represent
      is the the top-left cell that is relative to
      the tetris block.
    */
    int rowOffset;
    int columnOffset;
};