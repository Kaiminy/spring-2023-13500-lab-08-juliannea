#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;

#include "imageio.h"


// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(std::string filename, int image[MAX_H][MAX_W], int &height, int &width) {
	char c;
	int x;

	//reading and opening file
	ifstream instr;
	instr.open(filename);

		///Think this is getting rid of non image info 
	// read the header P2
	instr >> c;
	assert(c == 'P');
	instr >> c;
	assert(c == '2');

	// skip the comments (if any)
	while ((instr>>ws).peek() == '#') {
		instr.ignore(4096, '\n');
	}

	//getting image info
	instr >> width;
	instr >> height;

	//check that the width and height follow the max width and height limit -program terminates if false 
	assert(width <= MAX_W);
	assert(height <= MAX_H);
	int max;
	instr >> max;
	assert(max == 255);

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			instr >> image[row][col]; //making the array be made up of the width and height of the pmg file
	instr.close();
	return; //changes the array in the main function since it passes by reference 
}

//Makes the new image file basicallt 
// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(std::string filename, int image[MAX_H][MAX_W], int height, int width) {
	ofstream ostr;
	ostr.open(filename);
	if (ostr.fail()) {
		cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << endl;
	// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << image[row][col] << ' ';
			ostr << endl;
		}
	}
	ostr.close();
	return;
}

