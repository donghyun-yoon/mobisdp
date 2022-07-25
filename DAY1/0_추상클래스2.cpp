//1_추상클래스2.cpp
#include <iostream>

// OCP
// 기능 확장에는 열려 있고(Open, 새로운 클래스/모듈이 추가되어도)
// 코드 수정에는 닫혀 있어야(Close)
// 한다는 원칙(Principle)
// "개방 폐쇄의 법칙"

// 강한 결합(tightly coupling)
// => 하나의 클래스가 다른 클래스 사용시, 클래스 이름을 직접 사용하는 것
// => 교체 불가능한, 확장성없는, 경직된 디자인 








class Camera
{
public:	
	void Take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera
{
public:
	void Take() { std::cout << "Take HD Picture" << std::endl; }
};

class People
{
public:	
	void UseCamera(Camera* p) { p->Take(); }
	void UseCamera(HDCamera* p) { p->Take(); }
};

int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);

	HDCamera hc;
	p.UseCamera(&hc); // ?
}





