#include <iostream>
#include <vector>


// �ٽ� 3. ��� �Ļ�Ŭ����(����)�� ������ Ư¡�� �ݵ�� ��� Ŭ����(Shape)����
//        �־�� �Ѵ�.
//        => �׷���, Shape* �� ��� ����Ҷ� �ش� Ư¡�� ����Ҽ� �ִ�.

// �ٽ� 4. ��� Ŭ���� ��� �Լ���, �Ļ� Ŭ������ �������ϰ� �Ǵ� ����
//		  �ݵ�� �����Լ��� ������ �Ѵ�.

class Shape 
{
protected:
	int color;
public:
	// �Ʒ� 2�� �Լ��� virtual �� �ұ�� ? ���� ����� ?
	// => �Ļ� Ŭ������ ������ �� �ʿ� �����ϴ�. �����Լ��� �� �ʿ�����ϴ�.
	void setColor(int c) { color = c; }
	int  getColor() const { return color; }

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
				p->draw();	// ������(Polymorphism)
							// ������ ǥ������ ��Ȳ�� ����(��ü�� ����)
							// �ٸ��� �����ϴ� ��

					// ���� : ���ο� ����(Triangle)�� �߰��Ǿ
					//       �� ������ ����� �ʿ� ����.
					//       OCP�� �����ϴ� ���� �ڵ��̴�.  
		}
	}
}

