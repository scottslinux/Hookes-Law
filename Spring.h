#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <raylib.h>




class Spring{

private:

    float K=0;
    float springLen=2.0;  //meter long spring
    Vector2 springpos{};
    Font marker{};
    Texture2D ball{};

    int nodes=0;    //eventually the number of nodes

    //variables for anvil
    float mass=0;
    Vector2 Masspos{};
    float G=-9.8;
    float vel=0;
    float dtime=0;
    float scaleMeters=200;  // ​‌‌‍⁡⁣⁢⁣***** 𝗦𝗽𝗲𝗰𝗶𝗳𝘆𝗶𝗻𝗴 𝗵𝗲𝗶𝗴𝗵𝘁⁡​ will update in updatephysics
    float pxlmeters=0;
    Rectangle sandbox{};
    double animtimer=0;
    double elapsedTime=0;
    bool ticflag=false;



public:



    Spring();
    ~Spring();

    void initialize(Rectangle simarea, Vector2 sprngpos,float scalepxm);
    void draw();
    void updatephysics(float newK, float newMass);
    double timer();


};
