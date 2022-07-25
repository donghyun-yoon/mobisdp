// 1_추상클래스1.cpp - 10page

// 추상 클래스 : 순수 가상함수가 한개이상 있는 클래스
// 의도 : 파생 클래스 설계자에게 특정 함수를 반드시 만들라고 지시하는 것
class Shape
{
public:
	virtual void Draw() = 0; // 순수 가상함수(pure virtual function)
};

class Rect : public Shape
{
	// Draw 의 구현을 제공하지 않으면 Rect 도 추상클래스 이다.
public:
	virtual void Draw() override {}  // 이렇게 구현을 제공하면 추상 클래스가 아니다.
};
int main()
{
//	Shape  s;	// error. 추상 클래스는 객체를 만들수 없다.
//	Shape* p;	// ok..   추상 클래스라도 포인터는 만들수 있다.
//	Rect  r;	// error. - Draw 구현이 없다면.. 
}



// Ctrl + F5 로 빌드해 보면 됩니다.
// 교재
// part 1. 디자인 패턴을 위한 C++ 문법
// part 2. 예제로 배우는 디자인 패턴
// part 3. 디자인 패턴 카테고리 정리. 