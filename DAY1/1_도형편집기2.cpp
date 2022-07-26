#include <iostream>
#include <vector>

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
	std::vector<Shape*> v; 

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			// Rect r;   // <= 이렇게 하면 {} 벗어 날때 즉시 파괴됩니다.
						 //    사용자가 명시적으로 지울때 까지 남아 있게 하려면
			v.push_back(new Rect); // 이렇게 new 로 하는 방법 밖에 없습니다.
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto p : v)	// p는 Shape* 타입인데
				p->draw();		// Shape 에는 draw가 없습니다.
								// 그래서, error 입니다.
		}
	}
}
// 컴파일 하면 에러 발생합니다.
// 왜, 어디서 에러 일까요 ?
// 해결책은 뭘까요 ?
