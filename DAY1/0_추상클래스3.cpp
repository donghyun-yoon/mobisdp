//1_추상클래스2.cpp
#include <iostream>



// 카메라 사용자와 카메라 제작자가 지켜야 하는 규칙을 먼저 설계한다.
// 규칙 : "모든 카메라는 아래 클래스로 부터 파생 되어야 한다."

class ICamera
{
public:
	virtual void Take() = 0;
};

// 실제 카메라가 없어도, 규칙이 있으므로
// 사용자는 규칙 대로만 사용하면 됩니다.
class People
{
public:
	void UseCamera(? p) { p->Take(); }
};










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





