#include <iostream>

class Drawable
{
public:
    virtual void draw(std::ostream &) const = 0;
};

class Printable
{
public:
    virtual void print(std::ostream &) const = 0;
};

// std::ostream &
// operator<<(Printable *o);

class Vector2d : Printable
{
    double x_;
    double y_;
    double distanceTo(const Vector2d &);
    void print() const override;

public:
    Vector2d(double x, double y) : x_(x), y_(y){};
};

class Shape
{
    Vector2d center;
    char color;

public:
    virtual double area() = 0;
    virtual double circumference() = 0;
    virtual bool contains(const Vector2d point) const = 0;
};

class Circle : public Shape,
               public Drawable,
               public Printable
{
    double radius;

public:
    void print() const override;
};

class Rectangle : public Shape,
                  public Drawable,
                  public Printable
{
    double width;
    double height;

public:
    void print() const override;
};

class Square : public Shape,
               public Drawable,
               public Printable
{
    double width;

public:
    void print() const override;
};