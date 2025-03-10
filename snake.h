#ifndef SNAKE_H
#define SNAKE_H
#include "raylib.h"
#include "math.h"
#include <iostream>
#include <vector>

struct position{
    float posX;
    float posY;
};

struct speed{
    int* speedX;
    int* speedY;
};

struct object_speed{
    struct speed* speed;
};

enum direction  {LEFT,UP,RIGHT,DOWN};
struct decision_point{
    // float x;
    // float y;
    struct Vector2 pos;
    direction dir;
};

class Snake{
    private:
        int MASTER_SPEED            = 300;
        int NULL_SPEED              = 0;
        const int SPEED_DELTA       = 10;
        struct speed horiz_speed    = {&MASTER_SPEED,&NULL_SPEED};
        struct speed verti_speed    = {&NULL_SPEED,&MASTER_SPEED};
        int N                       = 0;
        static const int MAX_N      = 10;
        std::vector<struct decision_point> decision_points;

    public:


        // struct object_speed snake_speed[MAX_N];
        // struct position sprite_pos[MAX_N];

        std::vector<struct object_speed>  snake_speed;
        std::vector<struct position>  sprite_pos;


        Texture2D sprite;
        Snake(char* file_name);
        ~Snake();
        void draw(void);
        void go_left(int speed);
        void go_left();
        void go_right(int speed);
        void go_right();
        void go_up(int speed);
        void go_up();
        void go_down(int speed);
        void go_down();
        void update_snake();
        void increase_speed();
        
};

class MyClass {
public:
    MyClass();
    ~MyClass();
    void myFunction();
    int myVariable;

private:
    int privateVariable;

};

const int TILE_SIZE     = 50;
const int SCREEN_WIDTH  = 810;
const int SCREEN_HIEGHT = 810;
const int SCREEN_X_OFF  = 100;
const int SCREEN_Y_OFF  = 100;
const int BORDER_SIZE   = 10;

#endif
