#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <raylib.h>

using namespace std;


class TextBox{

protected:

static Font boxfont;
static int resourcecounter3;
static bool resourceguard3;


Vector2 locationxy{0,0};
Vector2 size{0,0};
string boxstring{};
Color background{0,0,0,255};
Color fntcolor{0,0,0,255};    //Color fntcolor{0,255,0,255};
int fontsize=50;
int maxdigits=0;
std::string label;






public:


TextBox(int fontsz, int digits, Vector2 loc, std::string textLabel);
~TextBox();

void update();
void draw();
void print(string val);
void print(int val);
void print(float val);
void print(double content);
void insertcomma(string& num);





};
