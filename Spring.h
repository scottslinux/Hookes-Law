#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <raylib.h>




class Spring{

private:

    float K=0;
    float springLen=0;
    Vector2 springpos{};

    int nodes=0;    //eventually the number of nodes

    //variables for anvil
    float mass=0;
    Vector2 Masspos{};
    const float G=-9.8;
    float vel=0;
    float dtime=0;
    float scaleMeters=50;
    float pxlmeters=0;
    Rectangle sandbox{};



public:



    Spring();
    ~Spring();

    void initialize(Rectangle simarea, Vector2 sprngpos,float scalepxm);
    void draw();
    void updatephysics();
    double timer();


};
