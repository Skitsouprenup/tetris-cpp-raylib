#include "headers/block.h"
#include "headers/position.h"

/*
  Add public before 'Block'
  in order the parent class
  method to be accessible to
  LBlock instance.

  '+' is the pivot point of blocks.
*/

//L-block
class LBlock:public Block {
  public:
    LBlock() {
      color = 1;
      move(0,3);

      /*
          x
        xxx
         +
      */
      cells["up"] = {Position(0,2), Position(1,0), Position(1,1), Position(1,2)};

      /*
         x  
        +x
         xx
      */
      cells["right"] = {Position(0,1), Position(1,1), Position(2,1), Position(2,2)};

      /*
         +
        xxx
        x
      */
      cells["down"] = {Position(1,0), Position(1,1), Position(1,2), Position(2,0)};

      /*
        xx
         x+
         x
      */
      cells["left"] = {Position(0,0), Position(0,1), Position(1,1), Position(2,1)};
    }
};

//J-block
class JBlock:public Block {
  public:
    JBlock() {
      color = 2;
      move(0,3);

      /*
        x
        xxx
         +
      */
      cells["up"] = {Position(0,0), Position(1,0), Position(1,1), Position(1,2)};

      /*
         xx  
        +x
         x
      */
      cells["right"] = {Position(0,1), Position(0,2), Position(1,1), Position(2,1)};

      /*
         +
        xxx
          x
      */
      cells["down"] = {Position(1,0), Position(1,1), Position(1,2), Position(2,2)};

      /*
         x
         x+
        xx
      */
      cells["left"] = {Position(0,1), Position(1,1), Position(2,0), Position(2,1)};
    }
};

//I-block
class IBlock:public Block {
  public:
    IBlock() {
      color = 3;
      move(-1,3);

      /* 
        xxxx
         +
      */
      cells["up"] = {Position(1,0), Position(1,1), Position(1,2), Position(1,3)};

      /*
         x
        +x 
         x
         x
      */
      cells["right"] = {Position(0,2), Position(1,2), Position(2,2), Position(3,2)};

      /* +
        xxxx
      */
      cells["down"] = {Position(2,0), Position(2,1), Position(2,2), Position(2,3)};

      /*
        x
        x+
        x
        x
      */
      cells["left"] = {Position(0,1), Position(1,1), Position(2,1), Position(3,1)};
    }
};

//O-block
class OBlock:public Block {
  public:
    OBlock() {
      color = 4;
      move(0,4);

      /*
        xx
        xx
      */
      std::vector<Position> cell = 
        {Position(0,0), Position(0,1), Position(1,0), Position(1,1)};

      cells["up"] = cell;
      cells["right"] = cell;
      cells["down"] = cell;
      cells["left"] = cell;
    }
};

//S-block
class SBlock:public Block {
  public:
    SBlock() {
      color = 5;
      move(0,3);

      /*
         xx
        xx
         +
      */
      cells["up"] = {Position(0,1), Position(0,2), Position(1,0), Position(1,1)};
      /*
         x
        +xx
          x
      */
      cells["right"] = {Position(0,1), Position(1,1), Position(1,2), Position(2,2)};
      /*
         xx
        xx
         +
      */
      cells["down"] = {Position(1,1), Position(1,2), Position(2,0), Position(2,1)};
      /*
        x
        xx+
         x
      */
      cells["left"] = {Position(0,0), Position(1,0), Position(1,1), Position(2,1)};
    }
};

//T-block
class TBlock:public Block {
  public:
    TBlock() {
      color = 1;
      move(0,3);
      /*
         x
        xxx
         +
      */
      cells["up"] = {Position(0,1), Position(1,0), Position(1,1), Position(1,2)};
      /*
         x
        +xx
         x
      */
      cells["right"] = {Position(0,1), Position(1,1), Position(1,2), Position(2,1)};
      /*
         +
        xxx
         x
      */
      cells["down"] = {Position(1,0), Position(1,1), Position(1,2), Position(2,1)};
      /*
         x
        xx+
         x
      */
      cells["left"] = {Position(0,1), Position(1,0), Position(1,1), Position(2,1)};
    }
};

//Z-block
class ZBlock:public Block {
  public:
    ZBlock() {
      color = 2;
      move(0,3);

      /*
       xx
        xx
        +
      */
      cells["up"] = {Position(0,0), Position(0,1), Position(1,1), Position(1,2)};
      /*
          x
        +xx
         x
      */
      cells["right"] = {Position(0,2), Position(1,1), Position(1,2), Position(2,1)};
      /*
         +
        xx
         xx
      */
      cells["down"] = {Position(1,0), Position(1,1), Position(2,1), Position(2,2)};
      /*
         x
        xx+
        x
      */
      cells["left"] = {Position(0,1), Position(1,0), Position(1,1), Position(2,0)};
    }
};