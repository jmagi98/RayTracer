#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <stdlib.h>
#include <iostream>

class vec3 {
    public:

        // Array to be used as vector

        float e[3];

        // setting up 3d vec
        vec3() : e{0,0,0} {}
        vec3(float e0, float e1, float e2) { 
            e[0] = e0; 
            e[1] = e1; 
            e[2] = e2;
        }

        // assiging numbers in vector to a cordinate and a color
        // this vec3 class will be used for both rgb colors and locations
        inline float x() const { return e[0]; }
        inline float y() const { return e[1]; }
        inline float z() const { return e[2]; }
        inline float r() const { return e[0]; }
        inline float g() const { return e[1]; }
        inline float b() const { return e[2]; }

        // overloading the + = and [] o[]
        inline const vec3& operator+() const { return *this; }
        inline vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
        inline float operator[](int i) const { return e[i]; }
        inline float& operator[](int i) { return e[i]; }

        // for operator assignment.
            vec3& operator+=(const vec3 &v) {
                e[0] += v.e[0];
                e[1] += v.e[1];
                e[2] += v.e[2];
                return *this;
            }

            vec3& operator*=(const float t) {
                e[0] *= t;
                e[1] *= t;
                e[2] *= t;
                return *this;
            }

            vec3& operator/=(const float t) {
                return *this *= 1/t;
            }


        // get magnitude of vector
        inline float length() const {
            return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
        }

        inline float squared_length() const {
            return (e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
        }

        inline void make_unit_vector();
        

};
using point3 = vec3;
using color = vec3;


// creating custom input and output
inline std::istream& operator>>(std::istream &is, vec3 &t) {
    is >> t.e[0] >> t.e[1] >> t.e[2];
    return is;
}

inline std::ostream& operator<<(std::ostream &os, vec3 &t) {
   os << t.e[0] << t.e[1] << t.e[2];
   return os;
}

// makes vector into unit vector (length of 1)
inline void vec3::make_unit_vector() {
    float k = 1.0 / sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
    e[0] *= k;
    e[1] *=k;
    e[2] *=k;

}

// Overload all math operators

inline vec3 operator+(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}


inline vec3 operator-(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}


inline vec3 operator*(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}


inline vec3 operator/(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}


inline vec3 operator/(const vec3 v, float t) {
    return vec3(v.e[0]/t, v.e[1]/t, v.e[2]/t);
}


inline vec3 operator*(float t, const vec3 &v) {
    return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}


inline float dot(const vec3 &v1, const vec3 &v2) {
    return v1.e[0] * v2.e[0]
         + v1.e[1] * v2.e[1]
         + v1.e[2] * v2.e[2];
}

inline vec3 cross(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1],
                v1.e[2] * v2.e[0] - v1.e[0] * v2.e[2],
                v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]); 
}

inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}

#endif
