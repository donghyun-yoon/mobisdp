#include <iostream>
#include <vector>

// 핵심 1. 모든 도형을 "타입" 으로 설계 하면 편리하다.
// 
// 핵심 2. 모든 도형의 공통의 기반 클래스(Shape) 가 있다면
//        모든 도형을 하나의 컨테이너(vector)에 보관할수 있다..

class Shape {};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect" << std::endl; }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle" << std::endl; }
};

int main()
{
//	std::vector<Rect*> v; // Rect만 보관 가능한 vector
//	std::vector<void*> v; // 모든 타입의 주소를 보관
	std::vector<Shape*> v; // 모든 종류의 도형을 보관

}

