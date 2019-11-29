//Luke Powell (16634291) Objet-oriented Programming (CMP2090M) Assignnment
//This part of the code includes all of the relevant pieces required to carry out the programme
//The Header file containing the classes is also included here
#include "pch.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <istream>
#include <Windows.h>
#include "Header.h"


using namespace std;

//read_text reads in the text files converting them to a 1D array of doubles
double* read_text(const char *fileName, int sizeR, int sizeC);

//write_pgm converts the 1D array of doubles to a .pgm image allowing the image of Wally being found to be viewed.
void write_pgm(const char *filename, double *data, int sizeR, int sizeC, int Q);

//This is the function which runs the sum of squared difference function finding Wally
int StartSSD();

//This is a function which takes the colour pixels from the image of Wally and converts them into objects
void Wally_Image_Colour(int X, int Y, double* data, Ref_Image*& Image);

//The is a function which takes the colourr pixels from the cluttered image and converts them into objects
void Large_Image_Colour(int X, int Y, double* data, Large_Image*& Image);

//Begins the sum of squared difference function
int StartSSD() {
	int Sum_Squared_Difference=1;
	cout << "\n\t\t\t\t*****Files have been read in!*****\n" << endl;
	cout << endl;
	cout << "\t\t\t\t*****Step 2: Lets find Wally!*****\n" << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\t*******Press 'Enter' to Find Wally though SSD!*******\n" << endl;
	cin.ignore();
	return Sum_Squared_Difference;
}

int main() 
{
	//This part of code ensures that the programme has a nice user interface and looks friendly for the user
	cout << "Luke Powell (16634291)- Object-Oriented Programming (CMP2090M)- Assignment 1 \n" << endl;
	cout << "\t*****Step 1: The large image and the reference image are being read in...*****\n" << endl;
	//This signifies a loading bar showing the user that something is actually happened whilst the programme is running
	string loading = "";
	for (int i = 0; i < 8; i++)
	{
		cout << loading;
		Sleep(150);
		loading += "....";
	}
	cout << endl;
	//The x and y values of the cluttered and wally images are initialised here
	const int Cluttered_X = 768;
	const int Cluttered_Y = 1024;
	const int Wally_X = 49;
	const int Wally_Y = 36;
    double SSD;
    
	//The matrices from the Ref_Image class and the Large_Image class are initialised here
    Ref_Image* Wally_Grey = new Ref_Image();
    Large_Image* Cluttered_Scene = new Large_Image(Cluttered_X, Cluttered_Y);
	
	//The files names for the cluttered and Wally images being read in are intialised here
	const char* Large_Image = "Cluttered_scene.txt";
	const char* Small_Image = "Wally_Grey.txt";
    
	//These are the initialised pointers for the 1D arrays from the read in files
	double* Large_Image_Data = 0;
    double* Wally_Image_Data = 0;
    double* Area_Vec;
    
	//The text files colour data of the images are stored in the arrays
	Large_Image_Data = read_text(Large_Image, Cluttered_X, Cluttered_Y);
    Wally_Image_Data = read_text(Small_Image, Wally_X, Wally_Y);
    Wally_Image_Colour(Wally_X, Wally_Y, Wally_Image_Data, Wally_Grey);
    Large_Image_Colour(Cluttered_X, Cluttered_Y, Large_Image_Data, Cluttered_Scene);
    
	//The data of the Wally image is deleted
	delete [] Wally_Image_Data;
    
	//The Wally image values are put into a 1D array
	double* Area_Wally = (*Wally_Grey).getArea(0, 0, Wally_X, Wally_Y);
    
	//The Wally object is deleted as the values have been put into a 1D array
	delete Wally_Grey;
    
	//An object is made in order to match the image
	Ref_Image* Vec_Object = new Ref_Image();
	
	//This int gets the loop ready in order to find the sum of squared difference
	int Sum_Squared_Difference = StartSSD(), area = 1, Area_Y = 1, Area_X = 1;

    //The programme then informs the user that the finding Wally process is underway
	cout << "\t\t\t\t*******Finding Wally!*******" << endl << endl;
    
	//The loop goes through the cluttered scene image and attempts the find the similarity between the two images
	for (int i = 0; i < Cluttered_X - Wally_X; i = i + Area_X){
		for (int j = 0; j < Cluttered_Y - Wally_Y; j = j + Area_Y){
			Area_Vec = (*Cluttered_Scene).getArea(i, j, Wally_X, Wally_Y);

			//The sum of squared difference is found
					SSD = (*Cluttered_Scene).Find_SSD(Area_Wally, Area_Vec, Wally_X, Wally_Y);
				
			//The area is then deleted
			delete[] Area_Vec;
                
			//When the loop is at the first x and y value then object variables are set to them
			if(i == 0 && j == 0){
						(*Vec_Object).setX_Start(i);
						(*Vec_Object).setY_Start(j);
						(*Vec_Object).setSSD(SSD);
                }
            
				//If the sum of sqaured difference values is smaller than what is stored then it replaces the previous stored object else the loop continues
					if (SSD < (*Vec_Object).getSSD())
					{
						(*Vec_Object).setSSD(SSD);
						(*Vec_Object).setX_Start(i);
						(*Vec_Object).setY_Start(j);
					}
            }
        }
        
		//The matrix of the area of the Wally image is deleted after the programme has finished
		delete [] Area_Wally;
        
		//The cluttered scene data is updated to where Wally has been calculated to be
            Large_Image_Data = (*Cluttered_Scene).Highlight_Image((*Vec_Object).getX_Start(), (*Vec_Object).getY_Start(), Large_Image_Data, Wally_X, Wally_Y, Cluttered_Y);
		
		//The objects are deleted
		delete Cluttered_Scene;
		delete Vec_Object;
       
		//Initialises the output file where Wally will have been found
		const char* outputFileName = "Wally_Found.pgm";
        
		//Writes the data to the new .pgm file "Wally_Found.pgm"
			write_pgm(outputFileName, Large_Image_Data, Cluttered_X, Cluttered_Y, 255);
        
		//Deletes the large image data
		delete [] Large_Image_Data;
        
		//The user is informed that Wally has been found andd outputted
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "\t\t\t\t*****Wally has been found!*****" << endl;
		cout << "\t\t\t\t****Wally has been highlighted!****" << endl;
		cout << "\t\t\t*******Wally Outputted to: Wally_Found.pgm*******" << endl;
		cout << endl;
		cout << "\t\t\t\t******Search Successful******" << endl;
    
        return 0;
}

//Takes the Wally image data and puts it into a matrix
void Wally_Image_Colour(int X, int Y, double* data, Ref_Image*& Image){
    int count = 0;
	for (int X_Count = 0; X_Count < X; X_Count++)
	{
		for (int Y_Count = 0; Y_Count < Y; Y_Count++)
		{
			(*Image).setCol(X_Count, Y_Count, data[count]);
			count++;
		}
	}
}

//Takes the image data of the cluttered image and puts it into a matrix
void Large_Image_Colour(int X, int Y, double* data, Large_Image*& Image)
{
	int count = 0;
	for (int X_Count = 0; X_Count < X; X_Count++)
	{
		for (int Y_Count = 0; Y_Count < Y; Y_Count++)
		{
			(*Image).setCol(X_Count, Y_Count, data[count]);
			count++;
		}
	}
}

//Read .txt file with image of size RxC, and convert to an array of doubles
double* read_text(const char *fileName, int sizeR, int sizeC)
{
	double* data = new double[sizeR*sizeC];
	int i = 0;
	ifstream myfile;
	myfile.open(fileName, ios::in);
	if (myfile.is_open())
	{
		while (myfile.good())
		{
			if (i > sizeR*sizeC - 1) break;
			myfile >> *(data + i);
			//cout << *(data+i) << ' '; // This line display the converted data on the screen, you may comment it out. 
			i++;
		}
		myfile.close();
	}
	else cout << "\t\t\t\t*****Unable to open file*****";
	//cout << i;
	return data;
}

// convert data from double to .pgm stored in filename
void write_pgm(const char *filename, double *data, int sizeR, int sizeC, int Q)
{
	int i;
	unsigned char *image;
	ofstream myfile;
	image = (unsigned char *) new unsigned char[sizeR*sizeC];
	// convert the integer values to unsigned char
	for (i = 0; i < sizeR*sizeC; i++)
		image[i] = (unsigned char)data[i];
	myfile.open(filename, ios::out | ios::binary | ios::trunc);
	if (!myfile) {
		cout << "\t\t\t\tCan't open file: " << filename << endl;
		exit(1);
	}
	myfile << "P5" << endl;
	myfile << sizeC << " " << sizeR << endl;
	myfile << Q << endl;
	myfile.write(reinterpret_cast<char *>(image), (sizeR*sizeC) * sizeof(unsigned char));
	if (myfile.fail()) {
		cout << "\t\t\t\tCan't write image " << filename << endl;
		exit(0);
	}
	myfile.close();
	delete[] image;
}

