#include "raylib.h"
#include "snake.h"
#include "scoreboard.h"
#include "fruit.h"

using namespace std;

char sprite_name[30] = "resources/sprite.png";

int main()
{
    Sound sound;
    Music music;

    // SetWindowState(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_BORDERLESS_WINDOWED_MODE| FLAG_WINDOW_UNDECORATED);
    InitWindow(SCREEN_WIDTH, SCREEN_HIEGHT, "Game Start!");
    InitAudioDevice();
    
    sound   = LoadSound("resources/CreepyNoise.ogg");
    music   = LoadMusicStream("resources/arcade.mp3");
    
    Snake snake(sprite_name);
    ScoreBoard score_board(10,{0,0,10,20});
    Fruit fruit;

    bool mute   = true;
    bool play   = false;
    // PlayMusicStream(music); //->false

    SetTargetFPS(60);

    //Menu Loop
    Rectangle play_button={200,200,400,100};
    Rectangle close_button={200,400,400,100};
    while (!WindowShouldClose())
    {
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if(CheckCollisionPointRec(GetMousePosition(),play_button)){
                play=true;
                break;
            }
            if(CheckCollisionPointRec(GetMousePosition(),close_button)){
                break;
            }
        }
        BeginDrawing();
        ClearBackground(BLACK);
        DrawRectangleRec(play_button,BLUE);
        DrawRectangleRec(close_button,RED);
        DrawText("Play",play_button.x+140,play_button.y+25,64,GREEN);
        DrawText("Close",close_button.x+130,close_button.y+25,64,GREEN);
        EndDrawing();
    }

    //Game Loop
    while (!WindowShouldClose()&&play)
    {
        UpdateMusicStream(music);
        snake.update_snake();   
        if(fruit.check_fruit_collision(&snake)){
            snake.increase_speed();
            if(score_board.increment_score())break;
            else continue;
        }
        if (IsKeyPressed(KEY_M))
        {
            mute = !mute;
            if(mute)
                StopMusicStream(music);
            else
                PlayMusicStream(music);
        }
        if (IsKeyPressed(KEY_LEFT))
            snake.go_left();
        else if (IsKeyPressed(KEY_RIGHT))
            snake.go_right();
        else if (IsKeyPressed(KEY_DOWN))
            snake.go_down();
        else if (IsKeyPressed(KEY_UP))
            snake.go_up();

        BeginDrawing();
        ClearBackground(BLACK);
        score_board.draw_grid();
        fruit.draw_fruit();
        snake.draw();
        score_board.draw_score_board();
        EndDrawing();
    }
    StopMusicStream(music);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}