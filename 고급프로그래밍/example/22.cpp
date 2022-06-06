#include <iostream>

using namespace std;

class A{
    public:
        A(){cout << "A : exec\n";}
        ~A(){cout << "A : end\n";}
        int a;
};
class B : public A{
    public:
        B(){cout << "B : exec\n";}
        ~B(){cout << "B : end\n";}
        int b;
};
class C : public B{
    public:
        C(){cout << "C : exec\n";}
        ~C(){cout << "C : end\n";}
        int c;
};
int main(){
    C* pc = new C;
    delete pc;
}
