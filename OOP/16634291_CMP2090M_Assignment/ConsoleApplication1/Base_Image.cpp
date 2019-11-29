//Luke Powell (16634291) Objet-oriented Programming (CMP2090M) Assignnment
//The relevant files are included such as the Header file containing the Base_Image class
#include "pch.h"
#include "Header.h"

using namespace std;

//Default constuctor creating a matrix with a height and width of 1
Base_Image::Base_Image()
{
	X = 1;
	Y = 1;
	Base_Arr = new double*[X];
	for (int i = 0; i < X; i++)
	{
		Base_Arr[i] = new double[X];
		for (int j = 0; j < Y; j++)
		{
			Base_Arr[i][j] = 0;
		}
	}
}

//A costructor defining the dimensions of the matrix
Base_Image::Base_Image(int Arr_X, int Arr_Y)
{
	X = Arr_X;
	Y = Arr_Y;
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

//Matrix destructor 
Base_Image::~Base_Image() {
	
	//Deletes the array elements
	for (int i = 0; i < X; i++) {
		delete Base_Arr[i];
	}

	//Deletes the array 
	delete[] Base_Arr;

}

//This part returns a pointer to the 1D array of the area and adds the vales into the array
double* Base_Image::getArea(int x, int y, int Arr_X, int Arr_Y)
{
	double* a = new double[Arr_X * Arr_Y];
	count = 0;
	for (int i = x; i < Arr_X + x; i++)
	{
		for (int j = y; j < Arr_Y + y; j++)
		{
			a[count] = Base_Arr[i][j];
			count++;
		}
	}
	return a;
}

//The colour values are set in the array
void Base_Image::setCol(int x, int y, int C)
{
	Base_Arr[x][y] = C;
}

//The sum of squared difference is calculated between the large and small image
//The difference between the matrices are found and the difference is then squared and added to find the overall sum
double Base_Image::Find_SSD(double* Wally_Matrix, double* Cluttered_Matrix, int Wally_X, int Wally_Y)
{
	SSD = 0;
	for (int i = 0; i < Wally_X; i++)
	{
		for (int j = 0; j < Wally_Y; j++)
		{
			if (Wally_Matrix[i] != 255 && Wally_Matrix[j] !=255)
			{
				Differencei = Wally_Matrix[i] - Cluttered_Matrix[i];
				Differencej = Wally_Matrix[j] - Cluttered_Matrix[j];
				DifferenceSum = Differencei + Differencej;
				sum = DifferenceSum * DifferenceSum;
				SSD = sum + SSD;
			}
	}
	}
	return SSD;
}









