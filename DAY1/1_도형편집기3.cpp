#include <iostream>
#include <vector>


// 핵심 3. 모든 파생클래스(도형)의 공통의 특징은 반드시 기반 클래스(Shape)에도
//        있어야 한다.
//        => 그래야, Shape* 로 묶어서 사용할때 해당 특징을 사용할수 있다.

// 핵심 4. 기반 클래스 멤버 함수중, 파생 클래스가 재정의하게 되는 것은
//		  반드시 가상함수로 만들어야 한다.

class Shape 
{
protected:
	int color;
public:
	// 아래 2개 함수는 virtual 로 할까요 ? 하지 말까요 ?
	// => 파생 클래스가 재정의 할 필요 없습니다. 가상함수로 할 필요없습니다.
	void setColor(int c) { color = c; }
	int  getColor() const { return color; }

	// p->draw() 할때
	// 일반 멤버 함수 : 포인터 타입으로 함수 결정(Shape draw 호출)
	// 가상 함수     : 포인터가 가리키는 객체 조사후 함수 결정
	virtual void draw() { std::cout << "draw Shape" << std::endl; }
};





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
				p->draw();	// 다형성(Polymorphism)
							// 동일한 표현식이 상황에 따라(객체의 종류)
							// 다르게 동작하는 것

					// 장점 : 새로운 도형(Triangle)이 추가되어도
					//       이 한줄은 변경될 필요 없다.
					//       OCP를 만족하는 좋은 코드이다.  
		}
	}
}

