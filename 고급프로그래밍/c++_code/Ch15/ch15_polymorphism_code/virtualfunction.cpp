#include <iostream>
using namespace std;

class Person{

public:
	virtual void speak(){
		cout << "Person class speak function \n";
	}
};

class Student : public Person{ //학생
	public:
		// virtual이라는 keyword가 없으면 function redefinition
		virtual void speak(){
			cout << "\nStudent class speak function \n";
		}
};

class Professor : public Person{ // 교수
	public:

		virtual void speak(){
			cout << "Professor class speak function \n";
		}
};


int main() {
    Student s1;
    Professor p1;
    Person* arr[2];

	s1.speak();
	p1.speak();
    
	// Parent(Base) class와 Child(Derived) class는 is-a relationship을 가지기 때문에
	// 자식을 부모 class로 data type을 변경 가능
    arr[0] = &s1;
    arr[1] = &p1;
	// 부모 class로 자동 형변환을 했더라도, virtual function으로 선언된 것은
	// 부모 class의 virtual function이 실행하는 것이 아니라, 
	// 자식 class의 virtual function이 실행됨
    for (int i=0; i <2; i++)
       arr[i]->speak();

    return 0;
}