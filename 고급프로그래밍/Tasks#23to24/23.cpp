#include <iostream>
using namespace std;

class Figure
{

public:
    virtual void draw()=0;
    virtual void b(){};
};

class Point
{
public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    Point(Point &p)
    {
        this->x = p.x;
        this->y = p.y;
    }

    int x;
    int y;
};

class Rectangle : public Figure
{ //사각형
public:
    Rectangle(const Point &obj1, const Point &obj2)
    {
        this->x1 = obj1.x;
        this->y1 = obj1.y;
        this->x2 = obj2.x;
        this->y2 = obj2.y;
    }

    void draw()
    {
        cout << "A rectangle from (" << x1 << ", " << y1;
        cout << ") to (" << x2 << ", " << y2 << ")\n";
    }
//    void b(){}
private:
    int x1, y1;
    int x2, y2;
};

class Circle : public Figure
{ // 원
public:
    Circle(const Point &center, int r)
    {
        this->radius = r;
        this->x = center.x;
        this->y = center.y;
    }

    void draw()
    {
        cout << "A circle with the center of (" << x << ", ";
        cout << y << ") and the radius of " << radius << "\n";
    }
    void b(){}
private:
    int radius;
    int x, y;
};

void draw2figures(Figure &f1, Figure &f2)
{
    cout << "First figure is: ";
    f1.draw(); // 가상함수 출력
    cout << "Second figure is: ";
    f2.draw(); // 가상함수 출력
}

int main()
{
    Point p1(0, 0), p2(2, 2);
    Rectangle r1(p1, p2);
    Circle c1(p1, 2);
    draw2figures(r1, c1);
}