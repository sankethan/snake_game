#include "snake.h"

Snake::Snake(char *file_name)
{
    TraceLog(LOG_INFO, "The Snake is Born!");
    sprite = LoadTexture(file_name);
    // snake_speed.emplace_back(&horiz_speed);
    // sprite_pos.emplace_back(-1.0f*sprite.width,0+5);
    N++;
}
Snake::~Snake()
{
    TraceLog(LOG_INFO, "The Snake is Dead!");
}
void Snake::draw()
{
    // for(int i=0;i<N;i++)
    DrawTexture(sprite, sprite_pos.posX, sprite_pos.posY, WHITE);
}
void Snake::go_left(int speed)
{
    if (*(snake_speed.speed->speedX) == 0)
    {
        sprite_pos.posY = *snake_speed.speed->speedY > 0 ? ((floor((sprite_pos.posY + (sprite.height / 2)) / TILE_SIZE) * TILE_SIZE) + 5) : (floor((sprite_pos.posY) / TILE_SIZE) * TILE_SIZE) + 5;
        MASTER_SPEED = -abs(speed);
        snake_speed.speed = &horiz_speed;
    }
}
void Snake::go_left()
{
    if (*(snake_speed.speed->speedX) == 0)
    {
        sprite_pos.posY = *snake_speed.speed->speedY > 0 ? ((floor((sprite_pos.posY + (sprite.height / 2)) / TILE_SIZE) * TILE_SIZE) + 5) : (floor((sprite_pos.posY) / TILE_SIZE) * TILE_SIZE) + 5;
        MASTER_SPEED = -abs(MASTER_SPEED);
        snake_speed.speed = &horiz_speed;
    }
}
void Snake::go_right(int speed)
{
    if (*(snake_speed.speed->speedX) == 0)
    {
        sprite_pos.posY = *snake_speed.speed->speedY > 0 ? ((floor((sprite_pos.posY + (sprite.height / 2)) / TILE_SIZE) * TILE_SIZE) + 5) : (floor((sprite_pos.posY) / TILE_SIZE) * TILE_SIZE) + 5;
        MASTER_SPEED = abs(speed);
        snake_speed.speed = &horiz_speed;
    }
}
void Snake::go_right()
{
    if (*(snake_speed.speed->speedX) == 0)
    {
        sprite_pos.posY = *snake_speed.speed->speedY > 0 ? ((floor((sprite_pos.posY + (sprite.height / 2)) / TILE_SIZE) * TILE_SIZE) + 5) : (floor((sprite_pos.posY) / TILE_SIZE) * TILE_SIZE) + 5;
        MASTER_SPEED = abs(MASTER_SPEED);
        snake_speed.speed = &horiz_speed;
    }
}
void Snake::go_up(int speed)
{
    if (*(snake_speed.speed->speedY) == 0)
    {
        sprite_pos.posX = *snake_speed.speed->speedX > 0 ? ((floor((sprite_pos.posX + (sprite.width / 2)) / TILE_SIZE) * TILE_SIZE) + 5) : (floor((sprite_pos.posX) / TILE_SIZE) * TILE_SIZE) + 5;
        MASTER_SPEED = -abs(speed);
        snake_speed.speed = &verti_speed;
    }
}
void Snake::go_up()
{
    if (*(snake_speed.speed->speedY) == 0)
    {
        sprite_pos.posX = *snake_speed.speed->speedX > 0 ? ((floor((sprite_pos.posX + (sprite.width / 2)) / TILE_SIZE) * TILE_SIZE) + 5) : (floor((sprite_pos.posX) / TILE_SIZE) * TILE_SIZE) + 5;
        MASTER_SPEED = -abs(MASTER_SPEED);
        snake_speed.speed = &verti_speed;
    }
}
void Snake::go_down(int speed)
{
    if (*(snake_speed.speed->speedY) == 0)
    {
        sprite_pos.posX = *snake_speed.speed->speedX > 0 ? ((floor((sprite_pos.posX + (sprite.width / 2)) / TILE_SIZE) * TILE_SIZE) + 5) : (floor((sprite_pos.posX) / TILE_SIZE) * TILE_SIZE) + 5;
        MASTER_SPEED = abs(speed);
        snake_speed.speed = &verti_speed;
    }
}
void Snake::go_down()
{
    if (*(snake_speed.speed->speedY) == 0)
    {
        sprite_pos.posX = *snake_speed.speed->speedX > 0 ? ((floor((sprite_pos.posX + (sprite.width / 2)) / TILE_SIZE) * TILE_SIZE) + 5) : (floor((sprite_pos.posX) / TILE_SIZE) * TILE_SIZE) + 5;
        MASTER_SPEED = abs(MASTER_SPEED);
        snake_speed.speed = &verti_speed;
    }
}
void Snake::update_snake()
{
    sprite_pos.posX = (sprite_pos.posX > SCREEN_WIDTH) ? (-sprite.width) : (sprite_pos.posX < -sprite.width) ? (SCREEN_WIDTH)
                                                                                                             : sprite_pos.posX + (GetFrameTime() * *(snake_speed.speed->speedX));
    sprite_pos.posY = (sprite_pos.posY > SCREEN_HIEGHT) ? (-sprite.height) : (sprite_pos.posY < -sprite.height) ? (SCREEN_HIEGHT)
                                                                                                                : sprite_pos.posY + (GetFrameTime() * *(snake_speed.speed->speedY));
}
void Snake::increase_speed()
{
    MASTER_SPEED = MASTER_SPEED + ((MASTER_SPEED > 0) ? SPEED_DELTA : (-1 * SPEED_DELTA));
}
