#include <iostream>
#include <raylib.h>
#include <vector>
#include <string>

#include "Button.h"
#include "recButton.h"
#include "Slider.h"
#include "TextBox.h"
#include "textButton.h"
#include "Simulation.h"

using namespace std;


int main()
{
    const int winwidth=2500;
    const int winheight=1800;

    InitWindow(GetMonitorWidth(0),GetMonitorHeight(0),"test");
    float bestwidth=GetMonitorWidth(0)*0.95;
    float bestheight=GetMonitorHeight(0)*0.8;
    CloseWindow();
    


    InitWindow(bestwidth,bestheight,"Spring Demo");
        SetTargetFPS(60);
        InitAudioDevice();
    Simulation gameWindow;

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