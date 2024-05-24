#pragma once

#include <vector>
#include <raylib.h>

/*
  Grid Definition
*/

class Grid
{
  public:
    Grid();
    void createGrid();
    void drawGrid();
    bool isCellEmpty(int row, int column);
    bool cellOutOfBounds(int row, int column);
    int clearFilledRows();
    int grid[20][10];

  private:
    int rows;
    int columns;
    int cellSize;
    std::vector<Color> cellColors;
    bool gridRowFilled(int row);
    void clearRow(int row);
    void moveRowDown(int row, int clearedRows);
};