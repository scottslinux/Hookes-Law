#include <raylib.h>
#include <iostream>
#include <vector>
#include <string>

#include "recButton.h"

using namespace std;

Texture2D recButton::recButton_up{0};
Texture2D recButton::recButton_down{0};

int recButton::resourcecounter2{0};     //2 so you don't shadow the resource counter in base class
bool recButton::resourceguard2{false};





recButton::recButton(int locx,int locy, float scale) : Button({500,500},0.5,"label")
{
    location.x=locx;
    location.y=locy;
    buttonscale=scale;


    if(!resourceguard2) //only load once
    {
       // cout<<"loading the rec buttons....\n";
        recButton_up=LoadTexture("./resources/RectangleButton_up.png");
            
        recButton_down=LoadTexture("./resources/RectangleButton_down.png");

        resourceguard=true;
        


    }

    
    resourcecounter2++;

    return;
}
//-------------------------------------------------
recButton::~recButton()
{
    resourcecounter2--;

    if (resourcecounter2==0)
    {
        if (recButton_up.id!=0)
        {
            UnloadTexture(recButton_up);
            recButton_up=Texture2D{0};
        }
        if (recButton_down.id!=0)
        {
            UnloadTexture(recButton_down);
            recButton_down=Texture2D{0};
        }
        


    }






}
//-------------------------------------------------
bool recButton::update()

{
    //Define the buttons rectange

    Rectangle collisRec={location.x,location.y
        ,recButton_down.width*buttonscale,recButton_down.height*buttonscale};

    


    if (CheckCollisionPointRec(GetMousePosition(),collisRec)
            && IsMouseButtonDown(MOUSE_BUTTON_LEFT)&& !timerflag)
                {
                    
                    if(!IsSoundPlaying(click))
                        PlaySound(click);
                    timerflag=true;

                    value=true;

                }
                    else    
                    if (!timerflag)
                    {
                        value=false;
      
                  }

    if (CheckCollisionPointRec(GetMousePosition(),collisRec)
            && IsMouseButtonDown(MOUSE_BUTTON_LEFT)&& IsKeyDown(KEY_LEFT_SHIFT))
            {
                location.x=GetMousePosition().x-5;
                location.y=GetMousePosition().y-5;
                Rectangle collisRec={location.x,location.y
                    ,recButton_down.width*buttonscale,recButton_down.height*buttonscale};


            }

    if (timerflag)
            clicktimer();


    

    return value;


    
}

//-------------------------------------------------
void recButton::draw()
{


    Texture2D& activetexture=(!value ? recButton_up:recButton_down);
    
    DrawTextureEx(activetexture,{location.x,location.y},0,buttonscale,WHITE);
    
    if(value)
        DrawTextEx(pencil,"clicked",{location.x+recButton_down.width*buttonscale,location.y},25,0,BLACK);
        else
            DrawTextEx(pencil,"press me...",{location.x+recButton_down.width*buttonscale,location.y},25,0,BLACK);


    Vector2 center=MeasureTextEx(pencil,"A",50,0);
    int centx=((recButton_down.width*buttonscale)/2)-(center.x/2);
    int centy=((recButton_down.height*buttonscale)/2)-(center.y/2);



    DrawTextEx(pencil,"A",{location.x+centx,location.y+centy},
        50,0,Color{253,255,216,255});

 
    return;






}
