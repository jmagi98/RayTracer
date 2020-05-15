#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

// color is defined using vec3 in h file
void write_color(std::ostream& out, color pixel_color) {
    // creating int values for rgb color
    out << static_cast<int> (255.999 * pixel_color.r()) << ' '
        << static_cast<int> (255.999 * pixel_color.g()) << ' '
        << static_cast<int> (255.999 * pixel_color.b()) << '\n'; 
}

#endif