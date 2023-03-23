#include <iostream>
#include "imageio.h"

/*
Notes: The difference is between the number and 255. 
If the number is 0, then the difference is 255 so it gets replaced by 255
If the number is 1, the difference is 254 from 255, so it gets replaced by 254
If the number is 255, the difference is 0, so it get's replaced by 0

Reading the file
-When you read the file it puts each number into an array on rows and columns 
-The array name is determed by what you initalized the array is before putting it in a paremeter. 
-The array in the main function will change since it's passed by reference 
*/

//creating a function that takes in an array and replaces the values depending on it'ss difference from 255
void invert_colors(std::string filename)
{
    //reading the image 
    int img[MAX_H][MAX_W];

    int h, w; // height and width respectively

    readImage(filename, img,h,w); // marhsalling to img_data, h,w

    //copying its contents in new array
    int invert[MAX_H][MAX_W];

    for(int row = 0; row < h; row++) 
    {
        for(int col = 0; col < w; col++) 
        {
            invert[row][col] = img[row][col];
        }
    }

    int difference;
    //process the array rows 
    for(int r = 0; r < MAX_H; r++)
    {
        //process the array columns 
        for(int c = 0; c < MAX_W; c++)
        {
            //math to replace with difference of 255

            //find the difference 
            difference = invert[r][c] - 255;
            difference = abs(difference); //in the case the difference is a negative number 

            //replace column value with difference 
            invert[r][c] = difference;
        }
    }
    // and save this new image to file "outImage.pgm"
    writeImage("TaskA.pgm",invert, h, w);

    return;
}

//Task B
/*
invert half 
255/2 = 138
225-138 = 117 -start of right half 
177++ change from the columns 177 to up 
*/

void invert_half(std::string filename)
{
    //reading the image 
    int img[MAX_H][MAX_W];

    int h, w; // height and width respectively

    readImage(filename, img,h,w); // marhsalling to img_data, h,w

    //copying its contents in new array
    int invert[MAX_H][MAX_W];

    for(int row = 0; row < h; row++) 
    {
        for(int col = 0; col < w; col++) 
        {
            invert[row][col] = img[row][col];
        }
    }

    //initialize what is half of the columns 
    int half = (MAX_W/100) * 50;

    //invert half of the picture 
    int difference;
    //process the array rows 
    for(int r = 0; r < MAX_H; r++)
    {
        //process the array columns 
        for(int c = 0; c < MAX_W; c++)
        {   
            if(c >= half)
            {
                //math to replace with difference of 255

                //find the difference 
                difference = invert[r][c] - 255;
                difference = abs(difference); //in the case the difference is a negative number 

                //replace column value with difference 
                invert[r][c] = difference;
            }
            
        }
    }
    // and save this new image to file "outImage.pgm"
    writeImage("TaskB.pgm",invert, h, w);

    return;
}





