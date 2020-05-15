#include <iostream>
#include "color.h"
#include "vec3.h"
#include "ray.h"
using namespace std;

color ray_color(const ray& r) {
    // scales y based on height using the unit vector for direction.
    // blue to white from highest y val to lowest
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

int main() {
    // dims
    const auto aspect_ratio = 16.0 / 9.0;
    const int nx = 384;
    const int ny = static_cast<int>(nx/ aspect_ratio); 
    // specified header for ppm file
    std::cout << "P3\n" << nx << " " << ny << "\n255\n";
    point3 origin(0.0, 0.0, 0.0); 
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 vertical(0.0, 2.25, 0.0);
    /**
     * Calculate the lower left corner cordinate
     * (0,0,0) - (2,0,0) - (0, 1.25,) - (0, 0, 1)
     * (-2, -1.125, -1)
    **/

    point3 lower_left = origin - horizontal/2 - vertical/2 - vec3(0, 0, 1);
    // iterate through the 2D space
    for(int j = ny-1; j >= 0; j--) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for(int i = 0; i < nx; i++) {
            // calculate float val between 0 and 1 depending on how close to boarders
            auto u = float(i) / (nx - 1);
            auto v = float(j) / (ny - 1);

            // construct a ray r. direction based on nested for loops and scaled by u/v
            ray r(origin, lower_left + u*horizontal + v*vertical);
            
            // create vec3 color with (r, g, b) from the color returned from ray_color
            color pixel_color = ray_color(r);
            // convert floats to integer representing rgb
            write_color(std::cout, pixel_color);
        }
    }

    std::cerr << "\nDone.\n";
}