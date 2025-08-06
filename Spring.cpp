#include <iostream>
#include <vector>
#include <string>
#include <raylib.h>

#include "Spring.h"

using namespace std;

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
    //DrawLineEx({pos.x,sandbox.height-(pos.y*pxlmeters)},{pos.x,sandbox.height-(pos.y*pxlmeters)+springLen},7,GREEN);

    DrawCircle(Masspos.x,sandbox.height-(Masspos.y*pxlmeters),30,GREEN);

}
//======================================================
double Spring::timer()
{


}
//======================================================
//⁡⁣⁣⁡⁣⁣⁢passing in the area of the playing field, pos of top of spring⁡ 
void Spring::initialize(Rectangle sndbox,Vector2 pos2, float scalepxm)
{
    springpos=pos2;
    pxlmeters=scalepxm;
    sandbox=sndbox;
    K=80;   //Spring constant
    springLen=10;   //spring length 10 meters
    mass=15;    //15kg mass hanging
    Masspos.y=25; //⁡⁣⁢⁣​‌‍‌𝗲𝗻𝗱 𝗼𝗳 𝘁𝗵𝗲 𝘀𝗽𝗿𝗶𝗻𝗴 𝗼𝗻 𝗰𝗶𝗲𝗹𝗶𝗻𝗴 (𝗶𝗻 𝗺𝗲𝘁𝗲𝗿𝗲𝘀)​⁡
    Masspos.x=sandbox.width/2;


    cout<<"Mass Position: X: "<<Masspos.x<<"  Y: "<<Masspos.y<<endl;
    cout<<"sandbox x: "<<sandbox.x<<" Y: "<<sandbox.y<<" Width: "<<sandbox.width<<
        " Height: "<<sandbox.height<<" PixelMeters: "<<pxlmeters<<endl;


}