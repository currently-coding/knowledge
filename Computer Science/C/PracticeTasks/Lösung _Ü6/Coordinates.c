#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {
    _2D, 
    _3D
} CoordinateType;

typedef struct {
    CoordinateType type;
    union {
        struct {
            float x;
            float y;
        } _2D;
        struct {
            float x;
            float y;
            float z;
        } _3D;
    };
} Coordinate;

float calculate_distance(Coordinate *c1, Coordinate *c2) {
    if (c1->type != c2->type) {
        return NAN;
    }
    switch (c1->type) { 
    case _2D:
        return sqrtf(powf(c2->_2D.x - c1->_2D.x, 2) + powf(c2->_2D.y - c1->_2D.y, 2));
    case _3D:
        return sqrtf(powf(c2->_3D.x - c1->_3D.x, 2) + powf(c2->_3D.y - c1->_3D.y, 2) + powf(c2->_3D.z - c1->_3D.z, 2));
    default:
        return NAN;
    }
}

void print_coordinate(Coordinate *c) {
    switch (c->type) { 
    case _2D:
        printf("2D Coordinate (x:%f, y:%f)\n", c->_2D.x, c->_2D.y);
        break;
    case _3D:
        printf("3D Coordinate (x:%f, y:%f, z:%f)\n", c->_3D.x, c->_3D.y, c->_3D.z);
        break;
    }
}

int main() {
    Coordinate xy1 = {.type  = _2D, ._2D.x = 10, ._2D.y = 10};
    Coordinate xy2 = {.type  = _2D, ._2D.x = 20, ._2D.y = 20};

    Coordinate xyz1 = {.type  = _3D, ._3D.x = 10, ._3D.y = 10, ._3D.z = 10};
    Coordinate xyz2 = {.type  = _3D, ._3D.x = 20, ._3D.y = 20, ._3D.z = 20};

    const double distance_1 = calculate_distance(&xy1, &xy2);
    const double distance_2 = calculate_distance(&xyz1, &xyz2);

    print_coordinate(&xy1);
    print_coordinate(&xy2);
    printf("Distance: %f\n\n", distance_1);

    print_coordinate(&xyz1);
    print_coordinate(&xyz2);
    printf("Distance: %f\n", distance_2);

    return 0;
}