#pragma once

#include "vec3.h"

class ray {
public:
    //default constructor
    ray() {}

    //point and direction of the ray, constructor
    ray(const point3 &origin, const vec3 &direction) : orig(origin), dir(direction) {}

    //getters
    const point3 &origin() const { return orig; }
    const vec3 &direction() const { return dir; }

    //return point 3, scales direction and adds it to origin
    point3 at(double t) const
    {
        return orig + t * dir;
    }

private:
    point3 orig;
    vec3 dir;
};