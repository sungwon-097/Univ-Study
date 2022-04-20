#include <iostream>
using namespace std;

class Vector2D{

public:
    Vector2D(int x, int y);
    Vector2D();
    int getCoordinates_x() const;
    int getCoordinates_y() const;

    friend const Vector2D operator +(const Vector2D& v1, const Vector2D& v2);
    friend std::ostream& operator << (ostream& outputStream, const Vector2D& v2); // Operator << overloading
private:
    int coordinates_x;
    int coordinates_y;
};

int main(){
    Vector2D v0, v1(2,2), v2(3,3), v3;

    cout << v1;
    cout << v1 + v2;
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

std::ostream& operator << (ostream& outputStream, const Vector2D& v2){ // << overloading
    outputStream << "( "<< v2.getCoordinates_x() << ", " << v2.getCoordinates_y() << " )\n";
    return outputStream;
}

const Vector2D operator +(const Vector2D& v1, const Vector2D& v2){
    int sumOfx = v1.getCoordinates_x() + v2.getCoordinates_x();
    int sumOfy = v1.getCoordinates_y() + v2.getCoordinates_y();

    return Vector2D(sumOfx, sumOfy);
}