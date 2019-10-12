#include "..\..\..\libraries\ColorTool\include\ColorTool.hpp"
#include<algorithm>
#include <fstream>
#include <iostream>
#include <math.h>




int InverseColor(int color)
{
	int red=0;
	int green = 0;
	int blue = 0;
	int alpha = 0;

	//Unpack
	red =  ( color >> 24) & 0xFF;
	green =  (color >> 16) & 0xFF;
	blue =  (color  >> 8) & 0xFF;
	alpha = (color  ) & 0xFF;

	//Resets the config.txt

	color1.r = red;
	color1.g = green;
	color1.b = blue;
	color1.a = alpha;
	WriteToFile(color1);

	//Operations
	red = 255 - red;
	green = 255 - green;
	blue = 255 - blue;

	//New data generated save to file
	color2.r = red;
	color2.g = green;
	color2.b = blue;
	color2.a = alpha;
	AddData('I', color1, color2);

	//pack
	red = (red << 24) & 0xFF000000;
	green = (green << 16) & 0x00FF0000;
	blue = (blue << 8) & 0x0000FF00;
	alpha = (alpha) & 0xFF;

	//Returns result
	int inverseColor = red | green | blue | alpha;
	return inverseColor;
	
}

int AnalogousColor(int color,int percentage)
{
	std::vector <int> colorV;

	int red = 0;
	int green = 0;
	int blue = 0;
	int alpha = 0;

	//Unpack
	red = (color >> 24) & 0xFF;
	green = (color >> 16) & 0xFF;
	blue = (color >> 8) & 0xFF;
	alpha = (color) & 0xFF;

	//Save values on a vector for easier access
	colorV.push_back(red);
	colorV.push_back(green);
	colorV.push_back(blue);
	colorV.push_back(alpha);

	//Resets the initial config

	color1.r = red;
	color1.g = green;
	color1.b = blue;
	color1.a = alpha;
	WriteToFile(color1);


	//Get max and min values
	int minValue =*std::min_element(colorV.begin(), colorV.end());
	int maxValue =*std::max_element(colorV.begin(), colorV.end());

	//Calculate offset
	int offset = int( (maxValue * 200) / 255 );
	offset /= percentage;

	//Declaration Temporal variables
	int positonToModify = 0;
	int lowIndex=1;
	int hightIndex = 0;

	for (size_t i = 0; i < 3; i++)
	{
		//Position to modify
		if (colorV[i] < maxValue && colorV[i] >minValue)
		{
			positonToModify = i;

		}
		//Max and min index
		else if (colorV[i] == minValue ? lowIndex = i : hightIndex = i);

	}
	
	
	while (offset != 0)
	{

		for (size_t i = 0; i < 3; i++)
		{
			//Position to modify
			if (colorV[i] < maxValue && colorV[i] >minValue)
			{
				positonToModify = i;

			}
		}

		switch (positonToModify)
		{
			//Modify R
		case 0:

			//minus
			if (lowIndex == 1)
			{
				
				if (colorV[positonToModify] == minValue)
				{

					colorV[positonToModify] = offset;
					offset = 0;
					break;
				}
				if (colorV[positonToModify] - offset < minValue)
				{
					offset = std::abs(colorV[positonToModify] - offset);
					colorV[positonToModify] = minValue;
					lowIndex = 0;
				}
				else
				{
					colorV[positonToModify] -= offset;
					offset = 0;

				}

			}
			//plus
			else
			{
				if (colorV[positonToModify] == maxValue)
				{
					colorV[positonToModify] = offset;
					offset = 0;
					break;

				}
				if (colorV[positonToModify] + offset > maxValue)
				{
					offset = std::abs(colorV[positonToModify] - offset);
					colorV[positonToModify] = maxValue;
					hightIndex = 0;
				}
				else
				{
					colorV[positonToModify] += offset;
					offset = 0;

				}

			}
			break;

			//Modify green
		case 1:
			//Plus
			if (colorV[positonToModify] == maxValue)
			{
				colorV[positonToModify] = offset;
				offset = 0;
				break;
			}
			if (lowIndex == 0)
			{
				if (colorV[positonToModify] + offset > maxValue)
				{
					offset = std::abs(colorV[positonToModify] - offset);
					colorV[positonToModify] = maxValue;
					hightIndex = 1;
				}
				else
				{
					colorV[positonToModify] += offset;
					offset = 0;

				}

			}
			//minus
			else
			{			
				if (colorV[positonToModify] == minValue)
				{

					colorV[positonToModify] = offset;
					offset = 0;
					break;
				}
				if (colorV[positonToModify] - offset < minValue)
				{
					offset = std::abs(colorV[positonToModify] - offset);
					colorV[positonToModify] = minValue;
					lowIndex = 1;
				}
				else
				{
					colorV[positonToModify] -= offset;
					offset = 0;

				}

			}
			break;
			//Modify Blue
		case 2:
			//Plus
			if (lowIndex == 0)
			{
				if (colorV[positonToModify] == maxValue)
				{
					colorV[positonToModify] = offset;
					offset = 0;
					break;

				}
				if (colorV[positonToModify] + offset > maxValue)
				{
					offset = std::abs(colorV[positonToModify] - offset);
					colorV[positonToModify] = maxValue;
					hightIndex = 2;
				}
				else
				{
					colorV[positonToModify] += offset;
					offset = 0;
				}
			}
			//Minus
			else
			{				
				if (colorV[positonToModify] == minValue)
				{
					colorV[positonToModify] = offset;
					offset = 0;
					break;
				}
				if (colorV[positonToModify] - offset < minValue)
				{
					offset = std::abs(colorV[positonToModify] - offset);
					colorV[positonToModify] = minValue;
					lowIndex = 2;
				}
				else
				{
					colorV[positonToModify] -= offset;
					offset = 0;

				}
			}
			break;
		}
	}


	//New data generated save to file
	color2.r = colorV[0];
	color2.g = colorV[1];
	color2.b = colorV[2];
	color2.a = colorV[3];
	AddData('A', color1, color2);

	//pack
	red = (colorV[0] << 24) & 0xFF000000;
	green = (colorV[1] << 16) & 0x00FF0000;
	blue = (colorV[2] << 8) & 0x0000FF00;
	alpha = (colorV[3]) & 0xFF;


	int analogColor = red | green | blue | alpha;
	return analogColor;
}



void WriteToFile(ColorRGBA color)
{
	std::ofstream configuration;
	configuration.open("..\\MidlewareProyect\\Assets\\Plugins\\config.txt");

	if (configuration.is_open())
	{	
		configuration <<  color.r << " " << color.g << " " << color.b << " " << color.a << "\0";
		configuration.close();
	}


};

int InitializeTool()
{
	vector <int> colors;

	//Opens files
	std::ifstream configFile("..\\MidlewareProyect\\Assets\\Plugins\\config.txt");
	if (configFile.is_open()) 
	{
		float a;
		while (configFile >> a)
		{
				colors.push_back(a);	
		}
		

		int red = (colors[0] << 24) & 0xFF000000;
		int green = (colors[1] << 16) & 0x00FF0000;
		int blue = (colors[2] << 8) & 0x0000FF00;
		int alpha = (colors[3]) & 0xFF;


		int dataColor = red | green | blue | alpha;

		return dataColor;

	}
	else return 0xFFFFFFFF;

}

void AddData(char operation, ColorRGBA originalColor, ColorRGBA colorModified)
{
	std::ofstream configFile("..\\MidlewareProyect\\Assets\\Plugins\\data.txt",ios::app);
	if (configFile.is_open())
	{
		configFile << operation << " " << originalColor.r << " " << originalColor.g << " " << originalColor.b << " " << originalColor.a << "|" << " " << colorModified.r << " " << colorModified.g << " " << colorModified.b << " " << colorModified.a << " \n";
	}
	
}


