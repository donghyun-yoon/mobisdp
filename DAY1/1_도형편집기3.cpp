#include <iostream>
#include <vector>


// �ٽ� 3. ��� �Ļ�Ŭ����(����)�� ������ Ư¡�� �ݵ�� ��� Ŭ����(Shape)����
//        �־�� �Ѵ�.
//        => �׷���, Shape* �� ��� ����Ҷ� �ش� Ư¡�� ����Ҽ� �ִ�.

// �ٽ� 4. ��� Ŭ���� ��� �Լ���, �Ļ� Ŭ������ �������ϰ� �Ǵ� ����
//		  �ݵ�� �����Լ��� ������ �Ѵ�.

class Shape 
{
public:
	// p->draw() �Ҷ�
	// �Ϲ� ��� �Լ� : ������ Ÿ������ �Լ� ����(Shape draw ȣ��)
	// ���� �Լ�     : �����Ͱ� ����Ű�� ��ü ������ �Լ� ����
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
	}
}

