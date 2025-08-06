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
    // ⁡⁢⁣⁣​‌‌‍𝘆=𝟭/𝟮 𝗮𝘁𝟮 +𝘃𝟬𝘁 +𝘆𝟬​⁡;

    float y0=Masspos.y; //hold the last Y position
    double dt=GetFrameTime();   //elapsed frame time

    //      ⁡⁣⁢⁣​‌‍‌𝗛𝗼𝗼𝗸𝗲'𝘀 𝗟𝗮𝘄 𝗧𝗶𝗺𝗲​⁡

    float SF=K* abs(Masspos.y-springLen); //  ⁡⁣⁢⁣SF =Spring Force⁡

    float newpos= (0.5*G*dt*dt)+vel+y0;
    vel=(G+SF) *dt + vel;     //calc vel  vy=at+v0  adding SF to Gravity

    Masspos.y=newpos;

    cout<<"Position: X: "<<Masspos.x<<"  Y: "<<Masspos.y<<endl;

}
//======================================================
void Spring::draw()
{
    //DrawLineEx({pos.x,sandbox.height-(pos.y*pxlmeters)},{pos.x,sandbox.height-(pos.y*pxlmeters)+springLen},7,GREEN);

    //draw the spring line
    DrawLineEx({Masspos.x,sandbox.y},{Masspos.x,sandbox.height-(Masspos.y*pxlmeters)},
                        8,RED);
    //draw the anvil
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
    K=.015;   //Spring constant
    springLen=50;   //spring length 10 meters
    mass=25;    //15kg mass hanging
    Masspos.y=150; //⁡⁣⁢⁣​‌‍‌𝗲𝗻𝗱 𝗼𝗳 𝘁𝗵𝗲 𝘀𝗽𝗿𝗶𝗻𝗴 𝗼𝗻 𝗰𝗶𝗲𝗹𝗶𝗻𝗴 (𝗶𝗻 𝗺𝗲𝘁𝗲𝗿𝗲𝘀)​⁡
    Masspos.x=sandbox.width/2;

    G=G/pxlmeters;  // 9.8 / 32 (for 50 meters)= 0.31 m/sec2 ????

    cout<<"Mass Position: X: "<<Masspos.x<<"  Y: "<<Masspos.y<<endl;
    cout<<"sandbox x: "<<sandbox.x<<" Y: "<<sandbox.y<<" Width: "<<sandbox.width<<
        " Height: "<<sandbox.height<<" PixelMeters: "<<pxlmeters<<endl;


}