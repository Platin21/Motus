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


class Color
{
    short Red,Green,Blue,Alpha;
public:
    Color(short r,short g,short b): Red(r),Green(g),Blue(b) {};
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
    
    void Negativ()
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
    
    void addColor(Color& c)
    {
        if((c.getRed() + Red) >= MAX_RGB)
            setRed((c.getRed() + Red) - MAX_RGB);
        else
            setRed(c.getRed() + Red);
        
        if((c.getGreen() + Green) >= MAX_RGB)
            setGreen((c.getGreen() + Green) - MAX_RGB);
        else
            setGreen(c.getGreen() + Green);
        
        if((c.getBlue() + Blue) >= MAX_RGB)
            setBlue((c.getBlue() + Blue) - MAX_RGB);
        else
            setBlue(c.getBlue() + Blue);
        
        if((c.getAlpha() + Alpha) >= MAX_RGB)
            setAlpha((c.getAlpha() + Alpha) - MAX_RGB);
        else
            setAlpha(c.getAlpha() + Alpha);
    }
    
    void subColor(Color& c)
    {
        setRed(c.getRed() - Red);
        setGreen(c.getGreen() - Green);
        setBlue(c.getBlue() + Blue);
        setAlpha(c.getAlpha() + Alpha);
    }
    
    void operator+=(Color& c)
    {
        addColor(c);
    }
    
    void operator-=(Color& c)
    {
        subColor(c);
    }
    
};
