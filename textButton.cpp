#include "textButton.h"

#include <iostream>
#include <vector>
#include <string>
#include <raylib.h>



Font textButton::typeface{0};
Sound textButton::click{0};
bool textButton::resourceguard{false};
int textButton::resourcecounter{0};

using namespace std;

//**************************************************** */

textButton::textButton(std::string buttonlabel,Vector2 loc, int fntsize)
{
    if (!resourceguard) //only once
    {
        cout<<"Loading the resources.....\n";

        
        typeface=LoadFontEx("./resources/Inter.ttf",100,0,0);
        click=LoadSound("./resources/click.wav");

        resourceguard=true;
    }
    resourcecounter++;

    location=loc;
    //buttonscale=scale;
    value=false;    //start button as non-pressed
    fontsize=fntsize;   //establish fontsize from the parameter fntsize

//calculate button dimensions based on the size of the text

    label=buttonlabel;  //this is what the button will read
    Vector2 sizetext=MeasureTextEx(typeface,label.c_str(),fontsize,0); //need variable font size

    buttonwidth=(sizetext.x*1.5);    //add padding around text
    buttonheight=(sizetext.y*1.25);    //add padding around text
    buttonRect={location.x,location.y,(float)buttonwidth,(float)buttonheight};

    

    



  //  std::cout<<"in the constructor...\n";
   // std::cout<<"location: "<<location.x<<","<<location.y<<std::endl;

    return;
}
//----------------------------------------------
textButton::~textButton()
{
    resourcecounter--;  //decrement before checkin against 0. so 1 item would run destructor

    if(resourcecounter==0)
    {
        cout<<"unloading the resources....\n";
        unloadResources();
        resourceguard=false;
    }
    

}
//-----------------------------------------------
bool textButton::update()
{
   bool value=false;

    if (CheckCollisionPointRec(GetMousePosition(),buttonRect)&&(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
        {
            timerflag=true;
            if(!IsSoundPlaying(click))
            PlaySound(click);
            value=true;
        }



    if (timerflag)
            textButton::clicktimer();

    return value;
}
//-----------------------------------------------
void textButton::draw()
{
    if (!timerflag)
    {
        DrawRectangle(location.x-8,location.y-8,buttonwidth+16,buttonheight+16,BLACK);
        DrawRectangle(location.x-5,location.y-5,buttonwidth+10,buttonheight+10,DARKGRAY);
        DrawRectangle(location.x,location.y,buttonwidth,buttonheight,GRAY);
    }
    else    //when clicked make the frame black
        {
            DrawRectangle(location.x-8,location.y-8,buttonwidth+16,buttonheight+16,BLACK);
            DrawRectangle(location.x-5,location.y-5,buttonwidth+10,buttonheight+10,
                Color{255,15,0,255});
            DrawRectangle(location.x,location.y,buttonwidth,buttonheight,GRAY);

        }
    int centerx=location.x+(buttonwidth/2)-(MeasureTextEx(typeface,label.c_str(),fontsize,0)).x/2;
    int centery=location.y+(buttonheight/2)-(MeasureTextEx(typeface,label.c_str(),fontsize,0)).y/2;
    
    Vector2 pos={centerx,centery};

    DrawTextEx(typeface,label.c_str(),{pos.x+2,pos.y+2},fontsize,0,BLACK);
    DrawTextEx(typeface,label.c_str(),pos,fontsize,0,textcolor);



    return;
}
//-----------------------------------------------
bool textButton::getbuttonval()
{


return true;
}
//-----------------------------------------------
void textButton::unloadResources()
{

    

    if (typeface.texture.id != 0) {
        UnloadFont(typeface);
        typeface = Font{};
    }

    if (click.frameCount > 0) {
        UnloadSound(click);
        click = Sound{};
    }




}
//-----------------------------------------------
bool textButton::clicktimer()
{

    if(timer<0.4)
    {
            timer+=GetFrameTime();

    }
        else
            {
                timer=0;
                timerflag=false;
            }

return false;


}