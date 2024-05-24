#include "headers/game.h"
#include <random>

Game::Game() {
  grid = Grid();
  lastUpdate = 0;
  blocks = getAllBlocks();
  currentBlock = getRandomBlock();
  nextBlock = getRandomBlock();
  gameOver = false;
  score = 0;

  InitAudioDevice();
  bgMusic = LoadMusicStream("sounds/Tetris.mp3");
  PlayMusicStream(bgMusic);

  clearSound = LoadSound("sounds/clear.wav");
}

Game::~Game()
{
  UnloadSound(clearSound);
  UnloadMusicStream(bgMusic);
  CloseAudioDevice();
}

Block Game::getRandomBlock()
{
  if(blocks.empty()) blocks = getAllBlocks();

  int randIndex = rand() % blocks.size();
  Block block = blocks[randIndex];
  //Remove the selected block from the vector.
  //We will lock the selected block once
  //it hits the bottom of its container or
  //in-place block.
  blocks.erase(blocks.begin() + randIndex);
  return block;
}

std::vector<Block> Game::getAllBlocks()
{
  return {
    LBlock(), 
    JBlock(), 
    IBlock(), 
    OBlock(), 
    SBlock(), 
    TBlock(), 
    ZBlock()
  };
}

void Game::draw()
{
  grid.drawGrid();
  //draw current block
  currentBlock.drawBlock(10, 10);
  switch (nextBlock.color)
  {
  case 3:
    nextBlock.drawBlock(255, 290);
    break;
  case 4:
    nextBlock.drawBlock(255, 280);
    break;
  
  default:
    nextBlock.drawBlock(270, 270);
  }
}

void Game::handleInput()
{
  if(gameOver) return;

  int keyPressed = GetKeyPressed();

  //reset
  if(gameOver && keyPressed != 0)
  {
    gameOver = false;
  }

  switch (keyPressed)
  {

    case KEY_LEFT:
      moveBlockLeft();
      break;

    case KEY_RIGHT:
      moveBlockRight();
      break;

    case KEY_DOWN:
      moveBlockDown();
      updateScore(0);
      break;
    
    case KEY_SPACE:
      rotateBlock();
      break;

    default:
      break;

  }
}

void Game::moveBlockLeft()
{
  currentBlock.move(0, -1);
  if(blockOutOfBounds() || lockBlockToFilledCell()) currentBlock.move(0, 1);
}

void Game::moveBlockRight()
{
  currentBlock.move(0, 1);
  if(blockOutOfBounds() || lockBlockToFilledCell()) currentBlock.move(0, -1);
}

void Game::moveBlockDown()
{
  currentBlock.move(1, 0);

  if(blockOutOfBounds() || lockBlockToFilledCell())
  {
    currentBlock.move(-1, 0);
    lockBlockToGrid();
  }
}

void Game::lockBlockToGrid()
{
  std::vector<Position> tiles = currentBlock.getCellsPosition();

  //assign the color id of a block in the grid container.
  for(Position tile : tiles)
  {
    grid.grid[tile.row][tile.column] = currentBlock.color;
  }
  currentBlock = nextBlock;
  //End game if the new block overlaps
  //a filled cell. This means that blocks
  //have piled up and reach the top grid.
  if(lockBlockToFilledCell())
  {
    gameOver = true;
  }

  nextBlock = getRandomBlock();
  int linesCleared = grid.clearFilledRows();
  if(linesCleared > 0)
  {
    PlaySound(clearSound);
    updateScore(linesCleared);
  }
}

void Game::resetGame()
{
  grid.createGrid();
  blocks = getAllBlocks();
  currentBlock = getRandomBlock();
  nextBlock = getRandomBlock();
  score = 0;
}

void Game::updateScore(int linesCleared)
{

  switch (linesCleared)
  {
    case 1:
      score += 100;
      break;
    case 2:
      score += 300;
      break;
    case 3:
      score += 500;
      break;
    case 4:
      score += 1000;
      break;
  
    default:
      break;
  }

  //Score for locking down a block
  score += 1;
    
}

/*
  When block overlaps with a filled cell, lock it next to an occupied cell.
*/
bool Game::lockBlockToFilledCell()
{
  std::vector<Position> tiles = currentBlock.getCellsPosition();

  for(Position tile : tiles)
  {
    if(grid.isCellEmpty(tile.row, tile.column) == false)
    {
      return true;
    }
  }

  return false;
}

bool Game::elapsedTimeEventTriggered(double interval)
{
  //GetTime() returns the elapsed time in seconds since InitWindow()
  double currentTime = GetTime();

  if(currentTime - lastUpdate >= interval)
  {
    lastUpdate = currentTime;
    return true;
  }

  return false;
}

bool Game::blockOutOfBounds()
{
  std::vector<Position> tiles = currentBlock.getCellsPosition();
  //Check if all cells of a block is in the boundary of
  //our container
  for(Position tile : tiles)
  {
    if(grid.cellOutOfBounds(tile.row, tile.column)) return true;
  }
  return false;
}

void Game::rotateBlock()
{
  currentBlock.rotate();
  if(blockOutOfBounds() || lockBlockToFilledCell())
  {
    currentBlock.revertRotate();
  }
}