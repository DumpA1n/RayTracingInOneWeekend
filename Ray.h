#pragma once

#include "MMath.h"

class Ray {
public:
    explicit Ray(const vec3f& origin, const vec3f& direction)
         : origin(origin), direction(direction) {}

    const vec3f& get_origin() const { return origin; }
    const vec3f& get_direction() const { return direction; }

    vec3f at(float t) const { return origin + t * direction; }

private:
    vec3f origin;
    vec3f direction;
};