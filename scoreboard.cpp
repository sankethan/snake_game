#include "scoreboard.h"


ScoreBoard::ScoreBoard(int initial_score, int max_score,Rectangle score_box)
    :score(initial_score),
    max_score(max_score),
    score_box(score_box)
    {}
ScoreBoard::ScoreBoard(int max_score,Rectangle score_box)
    :score(0),
    score_box(score_box),
    max_score(max_score)
    {}
int ScoreBoard::get_score(){
    return score;
}

bool ScoreBoard::increment_score(){
    return (score+=1)==max_score;
};
bool ScoreBoard::increment_score(int increment){
    return (score+=increment)==max_score;
};
void ScoreBoard::draw_score_board(){
    char print[10];
    sprintf(print,"%d/%d",score,max_score);
    DrawText(print,score_box.x,score_box.y,4,BLUE);
}

void  ScoreBoard::draw_grid(){
    for(int j= 0 ;j<(SCREEN_HIEGHT)/TILE_SIZE;j++)
        for(int i=0;i<SCREEN_WIDTH/TILE_SIZE;i++)
            DrawRectangle(BORDER_SIZE+(i*TILE_SIZE),BORDER_SIZE+(j*TILE_SIZE),TILE_SIZE-BORDER_SIZE,TILE_SIZE-BORDER_SIZE,GRAY);
}