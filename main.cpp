#include <raylib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "headers/game.h"

int main()
{
  // set seed to time to current unix timestamp
  srand(time(0));

  const Color fuchsia = { 157, 7, 89, 255 };
  const Color fuchsiaLight = { 224, 58, 149, 255 };

  const int screenWidth = 500;
  const int screenHeight = 620;

  //load font. LoadFontEx() is used to load .ttf fonts.
  //64 is the font size, 0 is codepoints. 0 codepoints means
  //all codepoints. another 0 is the codepointCount. 0
  //codepointCount means every character.
  int codepoints = 0;
  Font font = LoadFontEx("/fonts/Tuffy_Bold.ttf", 54, 0, 0);
  //Create window
  InitWindow(screenWidth, screenHeight, "Raylib Tetris");

  //Set FPS
  SetTargetFPS(60);               

  Game game = Game();

  // Main game loop
  //WindowShouldClose() determines if user close the game window. If true,
  //stop the game loop.
  while (!WindowShouldClose())
  {
    UpdateMusicStream(game.bgMusic);
    game.handleInput();
    if(game.elapsedTimeEventTriggered(0.4) && !game.gameOver)
    {
      game.moveBlockDown();
    }

    char scoreText[10];
    sprintf(scoreText, "%d", game.score);
    Vector2 scoreTextSize = MeasureTextEx(GetFontDefault(), scoreText, 28, 2);

    BeginDrawing();
      //Remove all drawn pixels on the game window and fill the window with
      //the specified color. 
      ClearBackground(fuchsia);
      DrawTextEx(font, "Score", {365, 15}, 28, 2, WHITE);
      DrawTextEx(font, "Next", {370, 175}, 28, 2, WHITE);
      if(game.gameOver) DrawTextEx(font, "GAME OVER", {320, 450}, 28, 2, WHITE);
      //1st param is the rectangle
      //2nd param is the roundness of the sides of rectangle
      //3rd param is the segments or the resolution of the roundness
      //of rectangle. In other words, how many lines are used to create
      //an arc.
      //last param is the color of rectangle
      DrawRectangleRounded({320, 55, 170, 60}, 0.2, 5, fuchsiaLight);

      DrawTextEx(
        font, 
        scoreText, 
        {
          //+7 is a magic number. It's an excess number when scoreTextSize.x
          //is divided by 2.
          320 + ((320 - 170)/2) - (scoreTextSize.x/2) + 7, 
          60 + 12
        }, 28, 2, WHITE);

      DrawRectangleRounded({320, 215, 170, 180}, 0.2, 5, fuchsiaLight);
      game.draw();
    EndDrawing();
  }

  //Destroy window in memory.
  CloseWindow();

  return 0;
}
