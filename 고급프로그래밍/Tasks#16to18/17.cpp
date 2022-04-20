#include <iostream>
using namespace std;

class Vector2D{

public:
    Vector2D(int x, int y);
    Vector2D();
    void output() const;
    int getCoordinates_x() const;
    int getCoordinates_y() const;
    friend const int operator *(const Vector2D& v1, const Vector2D& v2); // use friend, vector * vector
    friend const Vector2D operator *(int k, const Vector2D& v2); // scalar * vector
private:
    int coordinates_x;
    int coordinates_y;
};


void Vector2D::output()const{
    cout << "( " << coordinates_x << ", " << coordinates_y << " )\n";
}

int main(){
    Vector2D v0, v1(2,2), v2(3,3), v3;

    int k = 2;
    v3 = k * v1;
    v3.output();
    cout << v1 * v2 << "\n";
}

Vector2D::Vector2D(){
    coordinates_x=coordinates_y=0;
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

const int operator *(const Vector2D& v1, const Vector2D& v2){

    int mulOfx = v1.getCoordinates_x() * v2.getCoordinates_x();
    int mulOfy = v1.getCoordinates_y() * v2.getCoordinates_y();

    return mulOfx + mulOfy;
}

const Vector2D operator *(int k, const Vector2D& v2){

    int mulOfx = k * v2.getCoordinates_x();
    int mulOfy = k * v2.getCoordinates_y();

    return Vector2D(mulOfx, mulOfy);
}