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
			// Rect r;   // <= �̷��� �ϸ� {} ���� ���� ��� �ı��˴ϴ�.
						 //    ����ڰ� ��������� ���ﶧ ���� ���� �ְ� �Ϸ���
			v.push_back(new Rect); // �̷��� new �� �ϴ� ��� �ۿ� �����ϴ�.
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto p : v)	// p�� Shape* Ÿ���ε�
				p->draw();		// Shape ���� draw�� �����ϴ�.
								// �׷���, error �Դϴ�.
		}
	}
}
// ������ �ϸ� ���� �߻��մϴ�.
// ��, ��� ���� �ϱ�� ?
// �ذ�å�� ����� ?
