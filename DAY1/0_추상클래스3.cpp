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
	void UseCamera(ICamera* p) { p->Take(); }
};

// 이제 모든 카메라는 반드시 규칙을 지켜야 합니다.
class Camera : public ICamera
{
public:
	void Take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void Take() { std::cout << "Take HD Picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void Take() { std::cout << "Take UHD Picture" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);

	HDCamera hc;
	p.UseCamera(&hc); // ok

	UHDCamera uhc;
	p.UseCamera(&uhc); // ok.. 나중에 추가한 클래스도 
						//		People 클래스 수정없이 사용가능
						// OCP 규칙을 만족하는 유연한 코드..!!

}





