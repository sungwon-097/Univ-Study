#include <iostream>
#include <vector>
using namespace std;

class Figure
{
public:
    virtual void draw(){};
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
{
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

private:
    int x1, y1;
    int x2, y2;
};

class Circle : public Figure
{
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

private:
    int radius;
    int x, y;
};

vector<Figure *> setRectangle(int x1, int y1, int x2, int y2, vector<Figure *> v) // 사각형 성분을 벡터에 가져옴
{
    cout << "Enter x, y coordinates of P1:";
    cin >> x1 >> y1;
    cout << "Enter x, y coordinates of P2:";
    cin >> x2 >> y2;

    Rectangle *r = new Rectangle(Point(x1, y1), Point(x2, y2));

    v.push_back(r);

    return v;
}

vector<Figure *> setCircle(int x1, int y1, int r, vector<Figure *> v) // 원의 성분을 벡터에 가져옴
{
    cout << "Enter x, y coordinates of P1:";
    cin >> x1 >> y1;
    cout << "Enter the radius:";
    cin >> r;

    Circle *c = new Circle(Point(x1, y1), r);

    v.push_back(c);

    return v;
}

void drawFigues()
{
    int x1, y1, x2, y2, r;  // 각 도형의 성분들
    vector<Figure *> space; // 객체를 담아둘 벡터공간

    while (true)
    {
        string figure = "";
        cout << "Enter figure type or draw : "; // 문자를 받아옴
        cin >> figure;

        if (figure == "draw")
        {
            vector<Figure *>::iterator iter;
            for (iter = space.begin(); iter != space.end(); iter++) // iterator를 순회하며 virtual function 실행
            {
                Figure *f = *iter;
                f->draw(); // Figure를 상속하는 Rectangle과 Circle의 draw()
            }
            break;
        }
        else if (figure == "Rectangle")
            space = setRectangle(x1, y1, x2, y2, space); // 사각형 추가
        else if (figure == "Circle")
            space = setCircle(x1, y1, r, space); // 원 추가
        else
            cout << "Input error!\n"; // 형식 오류
    }
}

int main()
{
    drawFigues();
    return 0;
}