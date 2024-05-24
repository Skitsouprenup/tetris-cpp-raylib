#include "headers/colors.h"

/*
  Declare global color variables
*/
const Color silver = { 192, 192, 192, 255 }; //Empty cell color
const Color tomato = { 255, 99, 71, 255 };
const Color teal = { 0, 128, 128, 255 };
const Color indigo = { 75, 0, 130, 255 };
const Color gold = { 255, 215, 0, 255 };
const Color orange = { 255, 165, 0, 255 };
const Color lapis = { 40, 50, 194, 255 };

std::vector<Color> getCellColors() 
{
  return { silver, tomato, teal, indigo, gold, orange, lapis };
}