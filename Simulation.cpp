#include <iostream>
#include <raylib.h>
#include <vector>
#include <string>

#include "Button.h"
#include "recButton.h"
#include "Slider.h"
#include "TextBox.h"
#include "textButton.h"
#include "Spring.h"

#include "Simulation.h"



Simulation::Simulation():
    resetButton({(float)0.73*GetScreenWidth(),(float)0.28*GetScreenHeight()},0.15,"BEGIN SIM"),
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

    //          ​‌‍‌⁡⁣⁢⁣ℙ𝕀𝕏𝔼𝕃 : 𝕄𝔼𝕋𝔼ℝ𝕊 𝕊𝕔𝕒𝕝𝕚𝕟𝕘​⁡
    pxMeter=simheight/scaleMeters;  
    // calc scale factor for converting meters to pixels
    // divide the height of the simarea by the number of meters it represents
    // example 1600px/ 50 meters = 32 [pxMeter]. So, positioning at 25m would be
    // 1600 - (25m * 32px/m)= 1600 - 800= positoin at 800 (which is half of the 50m)
   



    

    
    
    chalk=LoadFontEx("./resources/Crayon.ttf",50,0,0);
   // std::cout << "Font texture ID: " << chalk.texture.id << std::endl;

    
    spring.initialize(simarea,{40,50},pxMeter); //the 40,50 are meters

    
    
}
//================================================
Simulation::~Simulation()
{
    UnloadFont(chalk);
    cout<<"chalk is unloaded.....\n";
}
//================================================
void Simulation::update()
{
    resetButton.update();
    float mass=massSlider.update();
    float acc=gravitySlider.update();
    forceText.update();

    forceText.print(mass*acc);

    spring.updatephysics();

    





}
//================================================
void Simulation::draw()
{
    //⁡⁣⁢⁣​‌‍‌𝗗𝗿𝗮𝘄 𝘁𝗵𝗲 𝗲𝗹𝗲𝗺𝗲𝗻𝘁𝘀 𝗼𝗳 𝘁𝗵𝗲 𝘀𝗰𝗿𝗲𝗲𝗻 𝗮𝗿𝗲𝗮 𝗮𝗻𝗱 𝗰𝗼𝗻𝘁𝗿𝗼𝗹𝘀​⁡

    DrawRectangleLinesEx(simarea,5,WHITE);
    //side panel rectangle
    DrawRectangle(winx*0.73,simarea.y,winx*0.3,simarea.height,Color{24,52,20,255});
    DrawTextEx(chalk,"Sping Physics Simulation",{winx*.735,winy*.05},90,0,Color{230,230,115,255});
    DrawTextEx(chalk,"Danger Simulation Area\n   Remain Clear...",{winx*.23,winy*.83},80,0,WHITE);

    resetButton.draw();
    massSlider.draw();
    gravitySlider.draw();
    forceText.draw();

    spring.draw();


}
//================================================
void Simulation::doPhysics()
{



    return;
}