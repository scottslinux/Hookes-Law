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



Scoreboard::Scoreboard():
    resetButton({(float)0.75*GetScreenWidth(),(float)0.1*GetScreenHeight()},0.15,"BEGIN SIM"),
    massSlider({(float)0.73*GetScreenWidth(),(float)0.35*GetScreenHeight()},0.4,0,0,100,"GRAVITY"),
    gravitySlider({(float)0.73*GetScreenWidth(),(float)0.45*GetScreenHeight()},0.4,0,0,100,"MASS"),
    forceText(60,10,{(float)0.73*GetScreenWidth(),(float)0.60*GetScreenHeight()},"Acceleration: ")

{
    winx=GetScreenWidth();
    winy=GetScreenHeight();

    float simx=0.02*winx;
    float simy=0.02*winy;
    float simwidth=winx*0.7;
    float simheight=winy*0.95;
   



    simarea={simx,simy,simwidth,simheight};

    
    


    
    chalk=LoadFontEx("./resources/Crayon.ttf",50,0,0);
    std::cout << "Font texture ID: " << chalk.texture.id << std::endl;
    
}
//================================================
Scoreboard::~Scoreboard()
{
    UnloadFont(chalk);
    cout<<"chalk is unloaded.....\n";
}
//================================================
void Scoreboard::update()
{
    resetButton.update();
    float mass=massSlider.update();
    float acc=gravitySlider.update();
    forceText.update();

    forceText.print(mass*acc);



}
//================================================
void Scoreboard::draw()
{
    DrawRectangleLinesEx(simarea,5,WHITE);
    DrawTextEx(chalk,"A NON-STATIC FONT!!!  2,679.34",{500,500},80,0,WHITE);

    resetButton.draw();
    massSlider.draw();
    gravitySlider.draw();
    forceText.draw();


}