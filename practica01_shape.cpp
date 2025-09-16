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
 double w_, h_;
public:
 Rectangle(double w, double h) : w_(w), h_(h) {}
 double area() const override { return w_ * h_; }
 double perimeter() const override { return 2 * (w_ + h_); }
};
class Circle : public Shape {
 double r_;
public:
 explicit Circle(double r) : r_(r) {}
 double area() const override { return M_PI * r_ * r_; }
 double perimeter() const override { return 2 * M_PI * r_; }
};
int main() {
 vector<unique_ptr<Shape>> shapes;
 shapes.emplace_back(make_unique<Rectangle>(4.0, 3.0));
 shapes.emplace_back(make_unique<Circle>(2.5));
 for (const auto& s : shapes) {
 cout << "A=" << s->area() << " | P=" << s->perimeter() <<
'\n';
 }
 return 0;
}
