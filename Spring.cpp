#include <iostream>
#include <vector>
#include <string>
#include <raylib.h>

#include "Spring.h"



Spring::Spring()
{


}
//======================================================

Spring::~Spring()
{



}
//======================================================
//do all calcs in meters, kg and seconds...convert at draw time
//example top of the cieling might be 50 meteres and the floor is 0
//scaleMeters is defined in Spring.h (also used in Simulatiuon)

void Spring::updatephysics()
{


}
//======================================================
void Spring::draw()
{
    DrawLineEx({pos.x,sandbox.height-(pos.y*pxlmeters)},{pos.x,sandbox.height-(pos.y*pxlmeters)+springLen},7,GREEN);


}
//======================================================
double Spring::timer()
{


}
//======================================================
//⁡⁣⁣⁡⁣⁣⁢passing in the area of the playing field, pos of top of spring⁡ 
void Spring::initialize(Rectangle sndbox,Vector2 pos, float scalepxm)
{
    springpos=pos;
    pxlmeters=scalepxm;
    sandbox=sndbox;
    K=80;   //Spring constant
    springLen=10;   //spring length 10 meters
    mass=15;    //15kg mass hanging
    pos.y=scaleMeters; //end of the pring on cieling (in meteres)
    pos.x=sandbox.width/2;


}