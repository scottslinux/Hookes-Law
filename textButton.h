#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <raylib.h>


class textButton

{
    protected:

    float buttonscale=1.0;
    float timer=0.0;

    int buttonheight=0;
    int buttonwidth=0;
    std::string label;
    int fontsize=0;
    Rectangle buttonRect;
    Color textcolor{253,255,216,255};


    
    bool timerflag=false;
    bool animationflag=false;

    Vector2 location;

    

                            //instance specific



    static Font typeface;
    static Sound click;

    static bool resourceguard;
    static int resourcecounter;
    



   


    public:
    bool value=false;   //true and false for on/off
    

    textButton(std::string buttonlabel,Vector2 location,int fntsize);
    ~textButton();

    virtual bool update();
    virtual void draw();
    bool getbuttonval();
    void unloadResources();
    bool clicktimer();



};
