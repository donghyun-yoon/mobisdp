#include <iostream>
#include <vector>

// 핵심 8. template method 디자인 패턴
// => 변하지 않은 전체 적인 흐름을 담은 함수를 기반 클래스가 제공
// => 변해야 하는 부분만 가상함수화 해서 파생 클래스가 재정의 할수 있게
// => 가장 널리 사용되는 디자인 패턴중 하나..


class Shape
{
protected:
	int color;
public:
	void setColor(int c) { color = c; }
	int  getColor() const { return color; }

	// 공통성안에 있는 가변성을 찾아서 분리한다.
	// => 변하지 않은 흐름속에 있는 변하는 부분을 찾는다.
	// => 변하는 코드는 가상함수로 분리한다.
protected:
	virtual void drawImp() 
	{
		std::cout << "draw Shape" << std::endl; 
	} 

public:
	void draw() 
	{ 
		std::cout << "mutex.lock" << std::endl;
		drawImp();
		std::cout << "mutex.unlock" << std::endl;
	}



	
	virtual Shape* clone() const
	{
		Shape* p1 = new Shape(*this);
		
		return p1;
	}

};





class Rect : public Shape
{
public:
	void drawImp() { std::cout << "draw Rect" << std::endl; }

	virtual Shape* clone() const
	{
		Rect* p1 = new Rect(*this);
		return p1;
	}
};

class Circle : public Shape
{
public:
	void drawImp() { std::cout << "draw Circle" << std::endl; }

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

			v.push_back(v[k]->clone()); 
		}
	}
}

