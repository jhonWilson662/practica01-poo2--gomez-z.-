// practica01_shape.cpp
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
using namespace std;

struct Shape {
    virtual ~Shape() = default;
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

class Rectangle : public Shape {
    double width_, height_;
public:
    Rectangle(double w, double h) : width_(w), height_(h) {}
    double area() const override { return width_ * height_; }
    double perimeter() const override { return 2 * (width_ + height_); }
};

class Circle : public Shape {
    double radius_;
public:
    explicit Circle(double r) : radius_(r) {}
    double area() const override { return M_PI * radius_ * radius_; }
    double perimeter() const override { return 2 * M_PI * radius_; }
};

int main() {
    vector<unique_ptr<Shape>> shapes;
    shapes.emplace_back(make_unique<Rectangle>(4.0, 3.0));
    shapes.emplace_back(make_unique<Circle>(2.5));

    for (const auto& s : shapes) {
        cout << "Área = " << s->area()
             << " | Perímetro = " << s->perimeter() << '\n';
    }
    return 0;
}
