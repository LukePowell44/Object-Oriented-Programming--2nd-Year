//Luke Powell (16634291) Objet-oriented Programming (CMP2090M) Assignnment
//The relevant parts are included including the Header file containing the Ref_Image class
#include "pch.h"
#include "Header.h"

using namespace std;

//Default constuctor creating a matrix with a height of 36 and a width of 49
Ref_Image::Ref_Image()
{
	X = 49;
	Y = 36;
	Base_Arr = new double*[X];
	for (int i = 0; i < X; i++)
	{
		Base_Arr[i] = new double[Y];
		for (int j = 0; j < Y; j++)
		{
			Base_Arr[i][j] = 0;
		}
	}
}

//Returns the starting x value
int Ref_Image::getX_Start()
{
	return X_Start;
}

//Returns the starting y value
int Ref_Image::getY_Start()
{
	return Y_Start;
}

//Sets the starting x value to r
void Ref_Image::setX_Start(int r)
{
	X_Start = r;
}

//Sets the starting y value to c
void Ref_Image::setY_Start(int c)
{
	Y_Start = c;
}

void Ref_Image::fill(int Rows_N, int Cols_N, double** Large_Cluttered_Scene, int C)
{
	for (int i = X_Start; i < X_Start + Rows_N; i++)
	{
		for (int j = Y_Start; j < Y_Start + Cols_N; j++)
		{
			Base_Arr[i][j] = C;
		}
	}
}

//Returns the SSD
float Ref_Image::getSSD()
{
	return SSD;
}

//Sets the SSD to score
void Ref_Image::setSSD(int score)
{
	SSD = score;
}



