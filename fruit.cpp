#include "fruit.h"
using namespace std;
Fruit::Fruit(){
    srand(time(NULL));
    fruit_coordi = {rand()%(int)(SCREEN_WIDTH/TILE_SIZE),rand()%(int)(SCREEN_WIDTH/TILE_SIZE)};
    fruitRect = {(1.0f*BORDER_SIZE)+(fruit_coordi.X*TILE_SIZE),(1.0f*BORDER_SIZE)+(fruit_coordi.Y*TILE_SIZE),TILE_SIZE-BORDER_SIZE,TILE_SIZE-BORDER_SIZE};
}

bool Fruit::check_fruit_collision(Snake *snake){
    if(CheckCollisionRecs({ snake->sprite_pos.posX, snake->sprite_pos.posY, 1.0f*snake->sprite.width, 1.0f*snake->sprite.height}, fruitRect)){
        fruitRect.x=BORDER_SIZE+((rand()%(int)(SCREEN_WIDTH/TILE_SIZE))*TILE_SIZE);
        fruitRect.y=BORDER_SIZE+((rand()%(int)(SCREEN_HIEGHT/TILE_SIZE))*TILE_SIZE);
        return true;
    }
    return false;
}
void Fruit::draw_fruit(){
    DrawRectangleRec(fruitRect,RED);
}