#include "hittable.h"
#include "hittable_list.h"
#include "rtweekend.h"
#include "sphere.h"
#include "square.h"
#include "camera.h"

int main()
{
    // World - sample list of hittable objects
    hittable_list world;

    world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));
    //world.add(make_shared<square>(point3(0, -25, -5), 50));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 400;
    cam.samples_per_pixel = 100;

    cam.render(world);
}