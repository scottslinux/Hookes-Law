#pragma once

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

class Simulation{

    private:
        Font chalk;

        int winx=0;
        int winy=0;
        Rectangle simarea{0,0,0,0};

        
        Button resetButton;
        Slider massSlider;
        Slider gravitySlider;
        TextBox forceText;

        float pxMeter=0;  //scale factor to convert meters to pixels
        float scaleMeters=200.0; //​‌‌‍⁡⁣⁢⁣𝗵𝗲𝗶𝗴𝗵𝘁 𝗼𝗳 𝘀𝗶𝗺𝗮𝗿𝗲𝗮 𝗶𝗻 𝗺𝗲𝘁𝗲𝗿𝘀⁡​

        Spring spring;


    public:



    Simulation();
    ~Simulation();

    void update();
    void draw();
    void doPhysics();
    










};
