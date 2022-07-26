#include <iostream>
#include <vector>

// 핵심 5. 디자인 패턴 이란 ?
//        자주 사용되는 코딩 스타일에 "이름"을 부여 한것
//        1994년 4명의 개발자가 쓴 "Design Pattern 책"
//        23개의 이름을 정의

// 핵심 6. prototype 패턴 : 견본 객체를 만들고, 복사를 통해서 새로운 
//						  객체를 만드는 기술
//						  clone 가상함수
// C# 코드 : int[] a1 = {1,2,3}
//           int[] a2 = a1;  // a1과 같은 배열 사용
//           int[] a3 = a1.copy(); // 

// 핵심 7. 리팩토링 용어 입니다. 의미를 생각해 보세요

// "Replace Conditional With Polymorphism"



class Shape
{
protected:
	int color;
public:
	void setColor(int c) { color = c; }
	int  getColor() const { return color; }

	virtual void draw() { std::cout << "draw Shape" << std::endl; }

	// 자신의 복사본을 만드는 가상함수는 항상 유용하게 사용됩니다.
	virtual Shape* clone() const 
	{
		Shape* p1 = new Shape(*this); // 복사 생성자를 사용하거나 
		// p1->color = color   	      // 또는 여기서 모든 멤버를 복사
		return p1;
	}

};





class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect" << std::endl; }

	virtual Shape* clone() const
	{
		Rect* p1 = new Rect(*this);
		return p1;
	}
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle" << std::endl; }
	
	virtual Shape* clone() const
	{
		Circle* p1 = new Circle(*this);
		return p1;
	}
};

class Triangle : public Shape
{
public:
	void draw() { std::cout << "draw Triangle" << std::endl; }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			v.push_back(new Rect);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw();
		}
		else if (cmd == 8)
		{
			std::cout << "몇번째 도형을 복사 할까요 >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->clone()); // 다형성
								// k번째 도형이 어떤 종류 인지 조사할 필요 없다.
								// 새로운 도형이 추가되어도
								// 이 한줄은 변경 되지 않는다.
								// OCP를 만족하는 좋은 코드. 
		}
	}
}

