#include <iostream>
#include <vector>
#include <string>
#include <raylib.h>

#include "TextBox.h"


Font TextBox::boxfont{0};
int TextBox::resourcecounter3=0;
bool TextBox::resourceguard3=false;

//---------------------------------------------------------
TextBox::TextBox(int fontsz, int digits, Vector2 loc,std::string labeltxt): fontsize{fontsz},locationxy{loc},maxdigits{digits}
{
    resourcecounter3++; //count for each  attempt to load
    if (!resourceguard3)
    {
        
        boxfont=LoadFontEx("./resources/Inter.ttf",50,0,0);
        resourceguard3=true;
        
      //  if (boxfont.texture.id !=0)
          //  cout<<" Font loaded successfully for textbox...\n";

        
    }

    boxstring="X"; //get the size for one large character and then mult for full size
    Vector2 messagesize=MeasureTextEx(boxfont,boxstring.c_str(),fontsize,0);
    messagesize.x*=digits;  //size * numberofchars 
    label=labeltxt;



    size={messagesize.x,messagesize.y*1.25};


    boxstring="";  //start with null

}
//---------------------------------------------------------

TextBox::~TextBox()
{
    resourcecounter3--;

    if (resourcecounter3==0)
    {
        UnloadFont(boxfont);
        boxfont={0};
    
    }




}
//---------------------------------------------------------
void TextBox::update()
{
    


    return;
}
//---------------------------------------------------------
void TextBox::draw()
{
    
    Vector2 labelsize=MeasureTextEx(boxfont,label.c_str(),fontsize,0);

    DrawTextEx(boxfont,label.c_str(),{locationxy.x,locationxy.y+5},fontsize,0,WHITE);
    DrawRectangle(locationxy.x+labelsize.x,locationxy.y,size.x,size.y,GRAY);

    if (boxstring.length()>maxdigits)
    {
        char buffer[20];
        for (int i=0;i<=maxdigits;i++)
            buffer[i]={'*'};

        DrawTextEx(boxfont,buffer,{locationxy.x+5+labelsize.x,locationxy.y+5},fontsize,0,fntcolor);
        return;
    }

    DrawTextEx(boxfont,boxstring.c_str(),{locationxy.x+5+labelsize.x,locationxy.y+5},fontsize,0,fntcolor);

    return;
}
//---------------------------------------------------------
void TextBox::print(string content)
{
    boxstring=content;

    return;
}
//-----------------------------------------------------------
void TextBox::print(int content)
{
    boxstring=to_string(content);
    insertcomma(boxstring);


    return;
}
//-----------------------------------------------------------
void TextBox::print(float content)
{
    
   // cout<<"content="<<content<<endl;

    char buffer[20];    //display string of float with 2 decimal points
    snprintf(buffer,sizeof(buffer),"%.2f",content);

    boxstring=buffer;

    insertcomma(boxstring);
  //  cout<<"going to insert comma...\n";
   // cout<<boxstring<<endl;

    return;
}
//-----------------------------------------------------------
void TextBox::print(double content)
{
    
   // cout<<"content="<<content<<endl;

    char buffer[20];    //display string of float with 2 decimal points
    snprintf(buffer,sizeof(buffer),"%.2f",content);

    boxstring=buffer;

    insertcomma(boxstring);
  //  cout<<"going to insert comma...\n";
  //  cout<<boxstring<<endl;

    return;
}
//-----------------------------------------------------------
void TextBox::insertcomma(string& numstrng)
{
    int len=numstrng.length();
    int leftdigits=0;
    int commas=0;
    bool negflag=false;

    

  //  cout<<"numstrng= "<<numstrng<<endl;
    if(numstrng[0]=='-')             // trim off the negative and set the flag for putting it back
    {
        numstrng=numstrng.substr(1);
        negflag=true;
      //  cout<<"new numstrng= "<<numstrng<<endl;
    }

    for(char i:numstrng)
    {
        if (i!='-' && i!='.')   //count all the members of the string to the left of decimal
                leftdigits++;
        if (i=='.') break;      //stop couting on the left
    }
    
    string leftside=numstrng.substr(0,leftdigits);
    string rightside=numstrng.substr(leftside.length(),numstrng.length());


  // cout<<"leftside: "<<leftside<<" rightside: "<<rightside<<endl;

    string tempstr="";
    string temp2="";
    int index=0;
    


    for (int i=leftside.length()-1;i>=0;i--)
    {
        index++;

        if((index>3))
        {
            tempstr+=',';
            tempstr+=leftside[i];
            index=1;
            continue;

        }

        tempstr+=leftside[i];
        

    }


  //  cout<<"left string: "<<leftside<<" right string: "<<rightside<<" temp: "<<tempstr<<endl;

    for (int i=tempstr.length()-1;i>=0;i--)
    {
        temp2+=tempstr[i];


    }

    numstrng=temp2+rightside;
    if(negflag)                 // put the negative sign back if it was there
        boxstring='-'+numstrng;
        else
            boxstring=numstrng;

 //   cout<<"Boxstring..."<<boxstring<<endl;

    return;

}