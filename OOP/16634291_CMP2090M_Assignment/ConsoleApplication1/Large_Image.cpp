//Luke Powell (16634291) Objet-oriented Programming (CMP2090M) Assignnment
//Includes the relevant files such as the Header file containing the Large_Image class
#include "pch.h"
#include "Header.h"

using namespace std; 

//This function draws a box around Wally on the cluttered scene image showing his location
double* Large_Image::Highlight_Image(int Last_X, int Last_Y, double* Cluttered_Image_Data, int Wally_X, int Wally_Y, int Cluttered_Y)
{
	int X_Output = Last_X + Wally_X;
	int Y_Output = Last_Y + Wally_Y;
	for (int X_Count = Last_X; X_Count <= X_Output; X_Count++)
	{
		for (int Y_Count = Last_Y; Y_Count <= Y_Output; Y_Count++)
		{
			if (X_Count == Last_X || X_Count == Last_X + 49 || Y_Count == Last_Y || Y_Count == Last_Y + 36)
			{
				for (int x = 0; x < 2.5; x++)
				{
					Cluttered_Image_Data[Cluttered_Y * (X_Count - x) + (Y_Count - x)] = 0;
				}
			}
			
		}
	}

	
	return Cluttered_Image_Data;
}
