#include <iostream>
#include <vector>
#include <string>
#include <raylib.h>

#include "Spring.h"
#include "Simulation.h"

using namespace std;

Spring::Spring()
{
        marker=LoadFont("./resources/Chalk.ttf");  //load gloabally
        cout<<"ID: :"<<marker.texture.id<<endl;

        ball=LoadTexture("./resources/ball.png");




}
//======================================================

Spring::~Spring()
{

    UnloadFont(marker);
    UnloadTexture(ball);

}
//======================================================
//do all calcs in meters, kg and seconds...convert at draw time
//example top of the cieling might be 50 meteres and the floor is 0
//scaleMeters is defined in Spring.h (also used in Simulatiuon)

void Spring::updatephysics()
{
    timer();

    if(ticflag)     //only update physics once every 0.016 sec  (60fps)
    {
    
        // ⁡⁢⁣⁣​‌‌‍𝘆=𝟭/𝟮 𝗮𝘁𝟮 +𝘃𝟬𝘁 +𝘆𝟬​⁡;

        float y0=Masspos.y; //hold the last Y position
        double dt=GetFrameTime();   //elapsed frame time

        //      ⁡⁣⁢⁣​‌‍‌𝗛𝗼𝗼𝗸𝗲'𝘀 𝗟𝗮𝘄 𝗧𝗶𝗺𝗲​⁡ ​‌‍‌⁡⁢⁣⁢𝗳= -𝗞*𝗫⁡​
        float neutral=80;    //correct the springlength from length to height in the air (meters)
                            //this puts the end of a 50m spring hanging from a 200m room at 150m high

        float dx=neutral-Masspos.y;
        float SF= -1* K * dx;  //  ⁡⁣⁢⁣SF =Spring Force⁡

        //f*=-1.0;  //reverse the force so the accelleration is up

        float springAcc=SF/mass;
        springAcc*= -1.0;  //reverse the accelleration for the vertical system


        float newpos= (0.5*G*dt*dt)+(vel*dt)+y0;
        vel=(springAcc+G) *dt + vel;     //calc vel  vy=at+v0  adding SF to Gravity

        Masspos.y=newpos;

        ticflag=false;

        cout<<"Position: X: "<<Masspos.x<<"  Y: "<<Masspos.y<<" Time: "<<elapsedTime<<" SFdx: "<<dx<<endl;
        cout<<"newpos "<<newpos<<" springlen "<<springLen<<endl;
    }
}
//======================================================
void Spring::draw()
{
    //DrawLineEx({pos.x,sandbox.height-(pos.y*pxlmeters)},{pos.x,sandbox.height-(pos.y*pxlmeters)+springLen},7,GREEN);

    //draw the spring line
    DrawLineEx({Masspos.x,sandbox.y},{Masspos.x,sandbox.height-(Masspos.y*pxlmeters)},
                        4,BROWN);
    //draw the anvil
    //DrawCircle(Masspos.x,sandbox.height-(Masspos.y*pxlmeters),50,LIGHTGRAY);

    char buffer[50];
    snprintf(buffer,sizeof(buffer),"%.0f",mass);
    DrawTextEx(marker,buffer,{Masspos.x-30,sandbox.height-(Masspos.y*pxlmeters)-20},50,0,BLACK);

    DrawTexture(ball,Masspos.x-ball.width/2,sandbox.height-(Masspos.y*pxlmeters),WHITE);
    

}
//======================================================
double Spring::timer()
{
    animtimer+=GetFrameTime();
    elapsedTime+=animtimer;
    if(animtimer> .016)
    {
        ticflag=true;
        animtimer=0;
    }
    return 1.0;
}
//======================================================
//⁡⁣⁣⁡⁣⁣⁢passing in the area of the playing field, pos of top of spring⁡ 
void Spring::initialize(Rectangle sndbox,Vector2 pos2, float scalepxm)
{
    springpos=pos2;
    pxlmeters=scalepxm;
    sandbox=sndbox;
    K=200;   //Spring constant 500 Nm
    springLen=20;   //spring length meters
    mass=500;    //15kg mass hanging
    Masspos.y=80; //⁡⁣⁢⁣​‌‍‌𝗲𝗻𝗱 𝗼𝗳 𝘁𝗵𝗲 𝘀𝗽𝗿𝗶𝗻𝗴 𝗼𝗻 𝗰ei𝗹𝗶𝗻𝗴 (𝗶𝗻 𝗺𝗲𝘁𝗲𝗿𝗲𝘀)​⁡
    Masspos.x=sandbox.width/2;

    

    cout<<"Mass Position: X: "<<Masspos.x<<"  Y: "<<Masspos.y<<endl;
    cout<<"sandbox x: "<<sandbox.x<<" Y: "<<sandbox.y<<" Width: "<<sandbox.width<<
        " Height: "<<sandbox.height<<" PixelMeters: "<<pxlmeters<<endl;


}