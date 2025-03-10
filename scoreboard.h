#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include "raylib.h"
#include "math.h"
#include <iostream>
#include "snake.h"

class ScoreBoard{
    private:
        int score;
        int max_score;
        Rectangle score_box;
    public:
        int get_score();
        ScoreBoard(int initial_score,int max_score,Rectangle score_box);
        ScoreBoard(int max_score,Rectangle score_box);
        bool increment_score();
        bool increment_score(int increment);
        void draw_score_board();
        void draw_grid();
        
};

#endif