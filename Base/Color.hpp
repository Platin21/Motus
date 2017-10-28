// @v 1.10.0
// @n Motus Lib
// @a Armin Hamar
// @l https://www.binpress.com/license/view/l/dc100faf74fa8ba3d613f8255ae1ef73
#pragma once
#include "Types.hpp"
#include "Convert.hpp"

// Header
#define MT_VERSION_1_10_0
// Header

#define RGB(r,g,b) Color(r,g,b)
#define GBR(g,b,r) Color(r,g,b)
#define BRG(b,g,r) Color(r,g,b)

#define RGBA(r,g,b,a) Color(r,g,b,a)
#define GBRA(g,b,r,a) Color(r,g,b,a)
#define BRGA(b,r,g,a) Color(r,g,b,a)

class Color
{
    short Red,Green,Blue,Alpha;
public:
    Color(short r = 255,short g = 255,short b = 255,short alpha = 255): Red(r),Green(g),Blue(b),Alpha(alpha)
    {
        if(Red >= MAX_RGB) Red = 255;
        if(Green >= MAX_RGB) Green = 255;
        if(Blue >= MAX_RGB) Blue = 255;
        if(Alpha >= MAX_RGB) Alpha = 255;
        
        if(Red < 0) Red = 0;
        if(Green < 0) Green = 0;
        if(Blue < 0) Blue = 0;
        if(Alpha < 0) Alpha = 1;
    };
    Color(utf8Char* RGBhexColor)
    {
        if(RGBhexColor[0] == '#' && CStringLenghtOf(&RGBhexColor[1]) == 8)
        {
            u32 hexColor = hexToDecimal(&RGBhexColor[1],8);
            Red    = ((hexColor >> 32) & 0xFF);  // get red
            Green  = ((hexColor >> 16) & 0xFF);  // get green
            Blue   = ((hexColor >> 8) & 0xFF);   // get blue
            Alpha  = ((hexColor) & 0xFF);        // get alpha
        }
        else
        {
            u32 hexColor = hexToDecimal(&RGBhexColor[1],8);
            Red    = ((hexColor >> 16) & 0xFF);  // get red
            Green  = ((hexColor >> 8) & 0xFF);  // get green
            Blue   = ((hexColor) & 0xFF);   // get green
            Alpha  = 255; // set alpha
        }
    }
    
    Color(i32&& hexColor)
    {
        Red    = ((hexColor >> 32) & 0xFF);  // get red
        Green  = ((hexColor >> 16) & 0xFF);  // get green
        Blue   = ((hexColor >> 8) & 0xFF);   // get blue
        Alpha  = ((hexColor) & 0xFF);        // get alpha
    }
    
    Color(i32& hexColor)
    {
        Red    = ((hexColor >> 32) & 0xFF);  // get red
        Green  = ((hexColor >> 16) & 0xFF);  // get green
        Blue   = ((hexColor >> 8) & 0xFF);   // get blue
        Alpha  = ((hexColor) & 0xFF);        // get alpha
    }
    
    void negate()
    {
        Red = MAX_RGB - Red;
        Green = MAX_RGB - Green;
        Blue  = MAX_RGB - Blue;
    }
    
    // @g & @s
    short getRed()
    {
        return Red;
    }
    
    short getGreen()
    {
        return Green;
    }
    
    short getBlue()
    {
        return Blue;
    }
    
    short getAlpha()
    {
        return Alpha;
    }
    
    void setRed(short red)
    {
        Red = red;
    }
    
    void setGreen(short green)
    {
        Green = green;
    }
    
    void setBlue(short blue)
    {
        Blue = blue;
    }
    
    void setAlpha(short alpha)
    {
        Alpha = alpha;
    }
    // @g & @s
    
};
