#include <iostream>
#include "imageio.h"
#include "invert.h"
#include "box.h"

int main()
{   
    std::string image1 = "image2.pgm";
    invert_colors(image1);

    invert_half(image1);

    white_box(image1);

    frame(image1);

    scale(image1);

    pixel(image1);
    
}