#include <iostream>

using namespace std;

struct CDAccountV1
{
public:
    CDAccountV1(double n1, double n2, int n3)
    {
        this->x = n1;
        this->y = n2;
        this->z = n3;
    }
    CDAccountV1(CDAccountV1 &copy)
    {
        this->x = copy.x;
        this->y = copy.y;
        this->z = copy.z;
    };
    double x, y;
    int z;

    void print()
    {
        cout << x << " "
             << " " << y << " " << z << " \n";
    }
};

void swap(CDAccountV1 &v1, CDAccountV1 &v2)
{
    CDAccountV1 temp = v1;
    v1 = v2;
    v2 = temp;
    cout << "<swapping...>\n";
}

int main()
{
    struct CDAccountV1 v1(10.0, 0.01, 60);
    struct CDAccountV1 v2(50.0, 0.02, 30);

    v1.print();
    v2.print();
    swap(v1, v2);
    v1.print();
    v2.print();
}