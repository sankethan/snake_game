#ifndef FRUIT_H
#define FRUIT_H
#include "raylib.h"
#include <iostream>
#include "snake.h"

struct coordinate{
    int Y;
    int X;
};

class Fruit{
    private:
        struct coordinate   fruit_coordi;
        Rectangle fruitRect;
    public:
        Fruit();
        bool check_fruit_collision(Snake *snake);
        void draw_fruit();
};

#endif