#include <iostream>
using namespace std;

class Vector2D{

public:
    Vector2D(int x, int y);
    Vector2D();
    void output() const;
    int getCoordinates_x() const;
    int getCoordinates_y() const;
private:
    int coordinates_x;
    int coordinates_y;
};

const Vector2D operator +(const Vector2D& v1, const Vector2D& v2); // operator plus
const Vector2D operator -(const Vector2D& v1, const Vector2D& v2); // operator minus
bool operator ==(const Vector2D& v1, const Vector2D& v2); // isEqual()
void Vector2D::output()const{
    cout << "( " << coordinates_x << ", " << coordinates_y << " )\n";
}
int main(){
    Vector2D v0, v1(2,2), v2(3,3), v3;

    v3 = v1 + v2;
    v3.output();

    v3 = v2 - v2;
    v3.output();

    if(v3 == v0)
        cout << "Operator - works!\n";
}

Vector2D::Vector2D(){
    coordinates_x = 0;
    coordinates_y = 0;
}

Vector2D::Vector2D(int x, int y){
    coordinates_x = x;
    coordinates_y = y;
}

int Vector2D::getCoordinates_x()const{ 
    return coordinates_x;
}

int Vector2D::getCoordinates_y()const{ 
    return coordinates_y;
}

const Vector2D operator +(const Vector2D& v1, const Vector2D& v2){
    int sumOfx = v1.getCoordinates_x() + v2.getCoordinates_x();
    int sumOfy = v1.getCoordinates_y() + v2.getCoordinates_y();

    return Vector2D(sumOfx, sumOfy);
}

const Vector2D operator -(const Vector2D& v1, const Vector2D& v2){
    int sumOfx = v1.getCoordinates_x() - v2.getCoordinates_x();
    int sumOfy = v1.getCoordinates_y() - v2.getCoordinates_y();

    return Vector2D(sumOfx, sumOfy);
}

bool operator ==(const Vector2D& v1, const Vector2D& v2){
    if(v1.getCoordinates_x() == v2.getCoordinates_x())
        if(v1.getCoordinates_y() == v2.getCoordinates_y())
            return true;
    
    return false;
}