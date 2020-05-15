#include <iostream>
#include "color.h"
#include "vec3.h"
using namespace std;

int main() {
    // dims
    int nx = 200;
    int ny = 100; 
    // specified header for ppm file
    std::cout << "P3\n" << nx << " " << ny << "\n255\n";
    
    // iterate through the 2D space
    for(int j = ny-1; j >= 0; j--) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for(int i = 0; i < nx; i++) {
            // create vec3 color with (r, g, b)
            color pixel_color(float(i)/(nx - 1), float(j)/(ny - 1), 0.25);
            // convert floats to integer representing rgb
            write_color(std::cout, pixel_color);
        }
    }

    std::cerr << "\nDone.\n";
}