#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
    public:
        // both based in vec3 class
        point3 orig;
        vec3 dir;

        // constructors
        ray() {}
        ray(const point3& origin, const vec3& directon) : orig(origin), dir(directon) {}
        point3 origin() const { return orig; }
        vec3 direction() const { return dir; }
        
        // get the point on a ray at any scalar
        point3 at(float t) const {
            return orig + t*dir;
        }

};
#endif