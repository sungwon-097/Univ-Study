#include <iostream>

using namespace std;

template <typename T>
class Quad
{ // class define
public:
    Quad(T t1, T t2, T t3, T t4)
    {
        set_t1(t1);
        set_t2(t2);
        set_t3(t3);
        set_t4(t4);
    } // constructor

    void set_t1(T t1) { this->t1 = t1; } // setter
    void set_t2(T t2) { this->t2 = t2; }
    void set_t3(T t3) { this->t3 = t3; }
    void set_t4(T t4) { this->t4 = t4; }

    T get_t1() { return this->t1; } // getter
    T get_t2() { return this->t2; }
    T get_t3() { return this->t3; }
    T get_t4() { return this->t4; }

private:
    T t1, t2, t3, t4; // member variables
};

template <typename T>
ostream &operator<<(ostream &outs, Quad<T> &q) // Overloading operator "<<""
{
    outs << "Elements are : < " << q.get_t1() << ", " << q.get_t2();
    outs << ", " << q.get_t3() << ", " << q.get_t4() << " >";
    return outs;
}

int main()
{
    Quad<int> qi(5, 6, 7, 8);
    Quad<string> qs("hello", "C++", "programming", "language");
    Quad<double> qd(1.1, 2.2, 3.3, 4.4);

    cout << qi << endl;
    cout << qs << endl;
    cout << qd << endl;
}