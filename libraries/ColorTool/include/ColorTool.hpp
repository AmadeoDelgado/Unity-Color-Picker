#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

///Data model 
static struct ColorRGBA
{
	
	int r = 0;
	int g = 0;
	int b = 0;
	int a = 0;

}color1,color2;

///Returns the inverse color
int InverseColor(int color);

///Returns an analogous color with the maximun distance / percentaje
int AnalogousColor(int color,int percentage);

///Writes the actual color to the config file
void WriteToFile(ColorRGBA color);

///Returns the data of the last sesion, if there is none returns white
int InitializeTool();

///Serialize all the data operations
void AddData(char operation,ColorRGBA originalColor,ColorRGBA colorModified);

