#include <iostream>
#include "imageio.h"

//Task C
/*
    white box fill it by 50% by 50% of the og width and height
    find 50% of the width 
    find 50% of the height 
    width of box is 138 
    height of box is 138 
    make box in middle 
*/
void white_box(std::string filename)
{
    //reading the image 
    int img[MAX_H][MAX_W];

    int h;
    int w;

    readImage(filename, img,h,w); 

    //copying its contents in new array
    int invert[MAX_H][MAX_W];

    for(int row = 0; row < h; row++) 
    {
        for(int col = 0; col < w; col++) 
        {
            invert[row][col] = img[row][col];
        }
    }

    //width halfsies 
    int halfW = w/2;
    int halfW2 = halfW/2;

    int minusw = halfW-halfW2;
    int plusw = halfW+halfW2;

    //rows halfsies 
    int halfr = h/2;
    int halfr2 = halfr/2;

    int minusr = halfr - halfr2;
    int plusr = halfr + halfr2;

    for(int r=0;r< MAX_H;r++) 
    {
        // going through each row
        for (int c = 0; c <MAX_W; c++) 
        {
           
            if((minusw < c) && (plusw > c) && (minusr < r) && (plusr > r)) 
            {
                invert[r][c] = 255; // writing white onto the pixel 
            }
            
        }
    }
    // and save this new image to file "outImage.pgm"
    writeImage("TaskC.pgm",invert, h, w);

    return;

}

//Task D

void frame(std::string filename)
{
    //reading the image 
    int img[MAX_H][MAX_W];

    int h;
    int w;

    readImage(filename, img,h,w); 

    //copying its contents in new array
    int invert[MAX_H][MAX_W];

    for(int row = 0; row < h; row++) 
    {
        for(int col = 0; col < w; col++) 
        {
            invert[row][col] = img[row][col];
        }
    }
     
    //width halfsies 
    int halfW = w/2;
    int halfW2 = halfW/2;

    int minusw = halfW-halfW2;
    int plusw = halfW+halfW2;

    //rows halfsies 
    int halfr = h/2;
    int halfr2 = halfr/2;

    int minusr = halfr - halfr2;
    int plusr = halfr + halfr2;

    

    for(int r=0;r< MAX_H;r++) 
    {
        // interating through each row
        for (int c = 0; c <MAX_W; c++) 
        {
            //condition for width frame 
            if((r == minusr+1 && (c > minusw && c < plusw)) || (r == plusr-1 && (c > minusw && c < plusw)))
            {
                invert[r][c] = 255; // writing white onto the pixel 
            }
            //condition for height frame 
            if((c == minusw+1 && (r > minusr && r < plusr)) || (c == plusw-1 && (r > minusr && r < plusr)))
            {
                invert[r][c] = 255; // writing white onto the pixel 
            }   
        }
    }
    // and save this new image to file "outImage.pgm"
    writeImage("TaskD.pgm",invert, h, w);

    return;

}

//Task E 
void scale(std::string filename)
{

    int img[MAX_H][MAX_W];
    int zoom[MAX_H][MAX_W];
    

    int h, w; 

    readImage(filename, img,h,w); 

    for(int i=0;i<h;i++) {
    
        for (int j = 0; j<w; j++) {
           
            
            zoom[2*i][2*j] = img[i][j];
            zoom[2*i][2*j + 1] = img[i][j];
            
            zoom[2*i+1][2*j] = img[i][j];
            zoom[2*i+1][2*j + 1] = img[i][j];
            
        }
    }

    writeImage("taskE.pgm", zoom, h*2,w*2);  

    return;
}

void pixel(std::string filename) 
{

    int img[MAX_H][MAX_W];
    int zoom[MAX_H][MAX_W];
    // space may be an issue in the future

    int h, w; // height and width respectively

    readImage(filename, img,h,w); // marhsalling to img_data, h,w


    int avg; // average of each 2x2 pixel cluster

    for(int i=0;i<h - (h%2);i+=2) { // h%2 is to ensure evenness
        // interating through each row
        for (int j = 0; j<w - (w%2); j+=2) {
            // iterating through each col

            //average of the four pixels
            avg = (zoom[i][j] + zoom[i+1][j] + zoom[i][j+1] + zoom[i+1][j+1]) / 4;

            zoom[i][j] = avg;
            zoom[i+1][j] = avg;
            zoom[i][j+1] = avg;
            zoom[i+1][j+1] = avg;

            // updating the cluster ^^
        }
    }

    writeImage("taskF.pgm", zoom, h,w); // wriitng to the image    

    return;
}




