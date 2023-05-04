#include <iostream>
#include "imageio.h"
#include "invert.h"
#include "box.h"

using namespace std;

int main()
{   
    std::string image1 = "inImage.pgm";

    std::string image2 = "image2.pgm";
  
    int img[MAX_H][MAX_W];
  
    invert_colors(image2);

    invert_half(image2);

    //testing on different images 

    white_box(image1);

    frame(image1);

    pixel(image2, img);
  
    scale(image1, img);

    return 0;

    
}
