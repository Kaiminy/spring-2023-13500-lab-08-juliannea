#include <iostream>
#include "imageio.h"
#include "invert.h"
#include "box.h"

int main()
{   
    std::string image1 = "inImage.pgm";
    int img[MAX_H][MAX_W];
    invert_colors(image1);

    invert_half(image1);

    white_box(image1);

    frame(image1);

    pixel(image1);
  
    scale(image1, img);

    return 0;

    
}
