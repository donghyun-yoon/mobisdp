#include <iostream>
#include <vector>


class Shape
{
protected:
	int color;
public:
	int type; // 도형의 종류를 관리

	void setColor(int c) { color = c; }
	int  getColor() const { return color; }

	virtual void draw() { std::cout << "draw Shape" << std::endl; }
};





class Rect : public Shape
{
public:
	Rect() { type = 1; }
	void draw() { std::cout << "draw Rect" << std::endl; }
};

class Circle : public Shape
{
public:
	Circle() { type = 2; }
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
				p->draw();
		}
		else if (cmd == 8)
		{
			std::cout << "몇번째 도형을 복사 할까요 >> ";

			int k;
			std::cin >> k;

			// 만약 아래 처럼 했다면 좋은 코드일까요 ?
			// 문제점은 뭘까요 ?
			switch (v[k]->type)
			{
			case 1: v.push_back(new Rect); break;
			case 2: v.push_back(new Circle); break;
			}
		}
	}
}

