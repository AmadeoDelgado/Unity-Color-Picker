using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System;
using UnityEngine;
/// <summary>
/// Conection between the DLL functions and unity
/// </summary>
public class Interface : MonoBehaviour
{

    //public static Interface instance;
    
    //Dll functions
    [DllImport("ColorToolDll")]
    static extern int CalculateInverseColor(int color);
    [DllImport("ColorToolDll")]
    static extern int CalculateAnalogousColor(int color,int percentage);
    [DllImport("ColorToolDll")]
    static extern int Initialize();

    ///converts color32 to int
    static private int Color32toInteger(Color32 color32)
    {
        int color = 0;
        int temColor = 0;
        temColor = color32.r;
        temColor = temColor << 24;
        color = color | temColor;


        temColor = color32.g;
        temColor = temColor << 16;
        color = color | temColor;

        temColor = color32.b;
        temColor = temColor << 8;
        color = color | temColor;

        temColor = color32.a;
        temColor = temColor << 0;
        color = color | temColor;

        return color;
    }
    ///converts int to color32
    static private Color32 IntegerToColor32(int colorInt)
    {
        Color32 color32 = Color.clear;

        color32.r = (byte)(colorInt >> 24 & 0x000000FF);
        color32.g = (byte)(colorInt >> 16 & 0x000000FF);
        color32.b = (byte)(colorInt >> 8 & 0x000000FF);
        color32.a = (byte)(colorInt  & 0x000000FF);

        return color32;
    }

    ///wrapper Inverse color function
     static public Color32 InverseColorsWrap(Color32 input)
    {

        return IntegerToColor32 ( 
            CalculateInverseColor( Color32toInteger(input) )
                                 ) ;
    }

    ///wrapper Inverse color function
    static public Color32 AnlagousColorWrap(Color32 input,int percentage)
    {

        return IntegerToColor32(
            CalculateAnalogousColor(Color32toInteger(input), percentage)
                                 );
    }
    ///Wrapper Intitializer of the tool
    static public Color32 InitializeWrap()
    {

        return IntegerToColor32(Initialize());
    }

}