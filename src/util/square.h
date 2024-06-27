#ifndef square_H
#define square_H

#include "hittable.h"
#include "vec3.h"

class square : public hittable {
public:
    square(const point3 &center, double side_length) : center(center), side_length(side_length) {}

    bool hit(const ray &r, interval ray_t, hit_record &rec) const override
    {
        // Calculate the half side length
        double half_side_length = side_length / 2.0;

        // Calculate the minimum and maximum bounds of the square
        point3 min_bound = center - vec3(half_side_length, half_side_length, half_side_length);
        point3 max_bound = center + vec3(half_side_length, half_side_length, half_side_length);

        // Check if the ray intersects the square's bounding box
        if (!checkBoundingBoxIntersection(r, min_bound, max_bound, ray_t.min, ray_t.max))
            return false;

        // Calculate the intersection point with the square's plane
        double t = (center.z() - r.origin().z()) / r.direction().z();

        // Check if the intersection point is within the acceptable range
        if (t < ray_t.min || t > ray_t.max)
            return false;

        // Calculate the intersection point
        point3 intersection_point = r.at(t);

        // Check if the intersection point is within the square's bounds
        if (intersection_point.x() < min_bound.x() || intersection_point.x() > max_bound.x() ||
            intersection_point.y() < min_bound.y() || intersection_point.y() > max_bound.y())
            return false;

        // Set the hit record
        rec.t = t;
        rec.p = intersection_point;
        rec.normal = vec3(0, 0, 1);// Assuming the square is aligned with the xy-plane
        rec.set_face_normal(r, rec.normal);

        return true;
    }

private:
    point3 center;
    double side_length;

    bool checkBoundingBoxIntersection(const ray &r, const point3 &min_bound, const point3 &max_bound, double tmin, double tmax) const
    {
        for (int i = 0; i < 3; i++)
        {
            double invD = 1.0 / r.direction()[i];
            double t0 = (min_bound[i] - r.origin()[i]) * invD;
            double t1 = (max_bound[i] - r.origin()[i]) * invD;
            if (invD < 0.0)
                std::swap(t0, t1);
            tmin = t0 > tmin ? t0 : tmin;
            tmax = t1 < tmax ? t1 : tmax;
            if (tmax <= tmin)
                return false;
        }
        return true;
    }
};

#endif