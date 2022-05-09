#include <iostream>

using namespace std;

class A{
    public:
        int memVar; // member variable
        A(){cout << "Constructor in class A executed\n";} // constructor
        ~A(){cout << "Destructor  in class A executed\n";} // destructor
};


class B : public A{
    public:
        int memVar;
        B(){cout << "Constructor in class B executed\n";}
        ~B(){cout << "Destructor  in class B executed\n";}
};

class C : public B{
    public:
        int memVar;
        C(){cout << "Constructor in class C executed\n";}
        ~C(){cout << "Destructor  in class C executed\n";}
};

int main(){
    C* pc = new C;
    delete pc;
}

