//1_추상클래스2.cpp
#include <iostream>


// 약한 결한(loosely coupling, 느슨한 결합)
// => 클래스가 다른 클래스 사용시 규칙을 담은 인터페이스(추상 클래스)
//    를 통해서 사용하는 것
// => 유연하고 확장성 있는 디자인


// 추상 클래스 : 지켜야 하는 규칙만 담는 경우 + 다른 멤버들도 제공
// 인터 페이스 : 지켜야 하는 규칙만 담는 경우(순수가상함수)

// 다른 언어는 "abstract", "interface" 라는 키워드가 따로 존재..
// 하지만, C++은 추상 클래스 문법 만 존재



// 카메라 사용자와 카메라 제작자가 지켜야 하는 규칙을 먼저 설계한다.
// 규칙 : "모든 카메라는 아래 클래스로 부터 파생 되어야 한다." 라고 하지 말고
// 
// 규칙 : "모든 카메라는 ICamera 인터페이스를 구현해야 한다" 라고 표현합니다.

// class  : 접근지정자 생략시 private
// struct : 접근지정자 생략시 public, 인터페이스 만들때 많이 사용
struct ICamera
{
	virtual void Take() = 0;
	virtual ~ICamera() {}   // C++ 기본 문법
							// 기반 클래스로 사용되는 클래스는 반드시
							// 소멸자를 가상함수로 해야 한다.
							// "가상소멸자" 학습해 보세요 
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





