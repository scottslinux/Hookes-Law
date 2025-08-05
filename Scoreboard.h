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

class Scoreboard{

    private:
        Font chalk;

        int winx=0;
        int winy=0;
        Rectangle simarea{0,0,0,0};

        
        Button resetButton;
        Slider massSlider;
        Slider gravitySlider;
        TextBox forceText;



    public:



    Scoreboard();
    ~Scoreboard();

    void update();
    void draw();










};
