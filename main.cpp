#include <iostream>
#include <raylib.h>
#include <vector>
#include <string>

#include "Button.h"
#include "recButton.h"
#include "Slider.h"
#include "TextBox.h"
#include "textButton.h"
#include "Scoreboard.h"

using namespace std;


int main()
{
    const int winwidth=2500;
    const int winheight=1800;
    
    
    


    InitWindow(winwidth,winheight,"Spring Demo");
        SetTargetFPS(60);
        InitAudioDevice();
    Scoreboard gameWindow;

    while(!WindowShouldClose())
    {

        BeginDrawing();

            ClearBackground(BLACK);

            gameWindow.update();
            gameWindow.draw();






        EndDrawing();



    }







    CloseAudioDevice();

}