#pragma once

#include <raylib.h>
#include <iostream>
#include <vector>
#include <string>

#include "Button.h"

class recButton :public Button
{

    protected:

    static Texture2D recButton_up;
    static Texture2D recButton_down;

    static bool resourceguard2;
    static int resourcecounter2;









    public:

        recButton(int,int,float);
        ~recButton();
        void draw() override;   //going to override base draw() method
        bool update() override; //have to override update for rectangle collision

        

        




};


