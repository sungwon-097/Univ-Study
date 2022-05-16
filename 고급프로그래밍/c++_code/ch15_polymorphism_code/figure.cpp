#include <iostream>
using namespace std;

// Figure : abstract base class라고 부름
class Figure{

	public:
		// pure virtual function : 부모 class에서 function에 대한 definition coding 안한 것
		virtual void draw() = 0;
		// 도형을 화면 중앙에 draw그리는 함수
		void center() {
			draw();
		}
	private:
		int center_x, center_y;
};

class Rectangle : public Figure{ //사각형
	public:
		// function redefinition(함수 재정의)
		virtual void draw(){
			cout << "\nRectangle class draw function \n";
		}
	private:
		int width, height;
};

class Circle : public Figure{ // 원
	public:
		virtual void draw(){
			cout << "Circle class draw function \n";
		}
	private:
		int radius;
};

class Triangle : public Figure{ // 삼각형
	public:

		virtual void draw(){
			cout << "Triangle class draw function \n";
		}
	private:
		int bottom, height;
};


int main() {
    Rectangle r;
    Circle c;
	Triangle t;
	// abstract class인 경우는 object 선언 불가능 
	// => 즉 자식 class에서만 object로 선언하여 사용 가능
//	Figure f;  
    
    r.draw();  //Calls Rectangle class’s draw
    c.draw(); //Calls Circle class’s draw

	// center 함수는 부모class인 Figure의 member function을 이용하여
	// 자식 class의 draw function을 실행하고 싶음
	// center() function을 call하는 주체가 자식 class의 object인 경우에는
	// center() function내 virtual function으로 선언된 draw() function을 
	// 호출할 때 (run-time때) 자식 class의 draw() 함수를 실행함
	r.center();
	c.center();
	t.center();

    return 0;
}