//Luke Powell (16634291) Objet-oriented Programming (CMP2090M) Assignnment
//This is the header file which contains the Base_Image class which is a parent class and the derived classes Large_Image and Ref_Image
#ifndef Header
#define Header

#include <stdio.h>
#include <array>

//This is the parent class called Base_Image which contains elements such as member functions for the Base_Image source file
class Base_Image{
//Publically accessible
public:
    
		//Constructor
		Base_Image();
		
		//Overloaded constructor
		Base_Image(int Arr_X, int Arr_Y);
		
		//Destructor
		~Base_Image();
		
		//Sets pixels
		void setCol(int x, int y, int C);
		
		//Returns matrix
		double* getArea(int x, int y, int Arr_X, int Arr_Y);
		
		//Finda sum of squared difference
		double Find_SSD(double* Wally_Matrix, double* Cluttered_Matrix, int Wally_X, int Wally_Y);

//Private to class
protected:
	
	//x and y variables of the matrix structure
	int X;
	int Y;
	
	int count;
	
	//SSD value
	double SSD;
	double Differencei;
	double Differencej;
	double DifferenceSum;
	double sum;
	
	//This defines the array
	double** Base_Arr;
};

//This is a child class of the Base_Image class called Large_Image which contains elements such as member functions for the Large_Image source file
class Large_Image : public Base_Image {

	//Publically accessible
public:

	//Overload constructor
	Large_Image(int X, int Y) :Base_Image(X, Y) {}

	//Member function allowing Wally to be highlighted on the cluttered image
	double* Highlight_Image(int Last_X, int Last_Y, double* Cluttered_Image_Data, int Wally_X, int Wally_Y, int Cluttered_Y);
};

//This is a child class of the Base_Image class called Ref_Image which contains elements such as member functions for the Ref_Image source file
class Ref_Image : public Base_Image
{

	//Publically accessible
public:

	//Constructor
	Ref_Image();

	//Overload constructor
	Ref_Image(int X, int Y) : Base_Image(X, Y) {}

	//gets the X start position
	int getX_Start();

	//gets the Y start position
	int getY_Start();

	//sets the X start position to r
	void setX_Start(int r);

	//sets the Y start position to c
	void setY_Start(int c);

	//Overides the matrix variables
	void fill(int Rows_N, int Cols_N, double** Large_Cluttered_Scene, int C);

	//Sets the SSD value
	void setSSD(int score);

	//gets the SSD value
	float getSSD();


	//Private to class
protected:

	//Initialises the x start position
	int X_Start;

	//Initialises the y start position
	int Y_Start;

	//Initialises the float SSD
	float SSD;

};
#endif /* Header*/