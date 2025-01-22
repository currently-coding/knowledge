#include <iostream>
#include <memory>

#include "geometry.h"

int main()
{
    Circle c1(Vector2d(20, 20), 18, ’~’);
    Circle c2(Vector2d(10, 10), 3, ’*’);
    Circle c3(Vector2d(30, 10), 3, ’*’);
    Square s1(Vector2d(20, 20), 5, ’+’);
    Rectangle r1(Vector2d(20, 30), 14, 2, ’#’);
    Rectangle r2(Vector2d(27, 28), 3, 3, ’#’);
    Rectangle r3(Vector2d(13, 28), 3, 3, ’#’);
    DrawingBoard db(40, 40);
    db.add_shape(&c1);
    db.add_shape(&c2);
    db.add_shape(&c3);
    db.add_shape(&s1);
    db.add_shape(&r1);
    db.add_shape(&r2);
    db.add_shape(&r3);
    cout << db << endl;
    db.draw(cout);
    cout << "circles: " << db.n_circles() << endl;
    cout << "rectangles: " << db.n_rectangles() << endl;
    cout << "squares: " << db.n_squares() << endl;
}