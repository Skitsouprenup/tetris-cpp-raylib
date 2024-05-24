#include "headers/block.h"

Block::Block()
{
  cellSize = 30;
  blockPos = "up";
  colors = getCellColors();
  rowOffset = 0;
  columnOffset = 0;
  posList = { "up", "right", "down", "left" };
  currPosIndex = 0;
}

void Block::drawBlock(int offsetX, int offsetY) 
{
  std::vector<Position> tiles = getCellsPosition();
  for(Position pos: tiles) {
    DrawRectangle(
      pos.column * cellSize + offsetX, 
      pos.row * cellSize + offsetY, 
      cellSize - 1, 
      cellSize - 1, 
      colors[color]
    );
  }
}

void Block::move(int row, int column) 
{
  rowOffset += row;
  columnOffset += column;
}

void Block::rotate()
{
  currPosIndex++;
  if(currPosIndex == cells.size()) {
    currPosIndex = 0;
  }
  blockPos = posList[currPosIndex];
}

void Block::revertRotate()
{
  currPosIndex--;
  if(currPosIndex == -1)
  {
    currPosIndex = cells.size()-1;
  }
  blockPos = posList[currPosIndex];
}

//Get the current position of each cell that is occupied
//by a block.
std::vector<Position> Block::getCellsPosition() 
{
  std::vector<Position> currentTiles = cells[blockPos];
  std::vector<Position> copy;

  for(Position tile : currentTiles) {
    copy.push_back(Position(tile.row + rowOffset, tile.column + columnOffset));
  }
  return copy;
}