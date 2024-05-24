/*
  Grid Implementation
*/

#include "headers/grid.h"
#include "headers/colors.h"

Grid::Grid()
{
  rows = 20;
  columns = 10;
  //30 * 10 = 300
  //30 * 20 = 600
  //Thus, the width of our screen is 300
  //and its height is 600
  cellSize = 30;

  cellColors = getCellColors();

  createGrid();
}

void Grid::createGrid()
{
  for(int row = 0; row < rows; row++) {
    for(int column = 0; column < columns; column++) {
      grid[row][column] = 0;
    }
  }
}

bool Grid::cellOutOfBounds(int row, int column)
{
  //Check if a selected cell in not in the bounds of
  //our container
  if(row >= 0 && row < rows && column >= 0 && column < columns)
  {
    return false;
  }
  return true;
}

/*
  Draw cells and the assigned color to them.
*/
void Grid::drawGrid()
{
  for(int row = 0; row < rows; row++) {
    for(int column = 0; column < columns; column++) {
      int cellValue = grid[row][column];

      //The +10 is the top and left offset of
      //the whole grid. The -1 is for the gap
      //between cells.
      //When drawing a block is not locked in the grid,
      //+10 must be also applied to the block.
      DrawRectangle(
        column * cellSize + 10, 
        row * cellSize + 10, 
        cellSize - 1, 
        cellSize - 1, 
        cellColors[cellValue]
      );
    }
  }
}

bool Grid::isCellEmpty(int row, int column)
{
  if(grid[row][column] == 0)
  {
    return true;
  }
  return false;
}

bool Grid::gridRowFilled(int row)
{
  for(int column = 0; column < columns; column++)
  {
    if(grid[row][column] == 0) return false;
  }
  return true;
}

void Grid::clearRow(int row)
{
  for(int column = 0; column < columns; column++)
  {
    grid[row][column] = 0;
  }
}

int Grid::clearFilledRows()
{
  int clearedRows = 0;

  //Start at the row at the bottom of the
  //grid to the top.
  for(int row = rows-1; row > 0; row--)
  {
    //First, clear filled row and subsequent filled rows.
    if(gridRowFilled(row))
    {
      clearRow(row);
      clearedRows++;
    }
    //Next, move down the cells on top of cleared rows.
    else if(clearedRows > 0)
    {
      moveRowDown(row, clearedRows);
    }
  }

  return clearedRows;
}

void Grid::moveRowDown(int row, int clearedRows)
{
  for(int column = 0; column < columns; column++)
  {
    //grid[row + clearedRows][column] is a cleared row
    //below grid[row][column]
    //Example, you have 5 rows and then 2 rows below have been
    //deleted. clearedRows will be 2 and row will be in
    //index 2. row + clearedRows = 4 which is the last row
    //in the grid. All cells of row will be transferred to the
    //last row of the grid and the current row will be emptied. 
    //Next, row grid will move up and the content of the current
    //row will be transferred to 'row + clearedRows' row which
    //in this case is '1 + 2' which is index 3.
    grid[row + clearedRows][column] = grid[row][column];
    //Clear grid[row][column] cell once its content
    //is moved down.
    grid[row][column] = 0;
  }
}
