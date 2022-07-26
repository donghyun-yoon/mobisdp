#include <iostream>
#include <vector>

// �ٽ� 5. ������ ���� �̶� ?
//        ���� ���Ǵ� �ڵ� ��Ÿ�Ͽ� "�̸�"�� �ο� �Ѱ�
//        1994�� 4���� �����ڰ� �� "Design Pattern å"
//        23���� �̸��� ����

// �ٽ� 6. prototype ���� : �ߺ� ��ü�� �����, ���縦 ���ؼ� ���ο� 
//						  ��ü�� ����� ���
//						  clone �����Լ�
// C# �ڵ� : int[] a1 = {1,2,3}
//           int[] a2 = a1;  // a1�� ���� �迭 ���
//           int[] a3 = a1.copy(); // 

// �ٽ� 7. �����丵 ��� �Դϴ�. �ǹ̸� ������ ������

// "Replace Conditional With Polymorphism"



class Shape
{
protected:
	int color;
public:
	void setColor(int c) { color = c; }
	int  getColor() const { return color; }

	virtual void draw() { std::cout << "draw Shape" << std::endl; }

	// �ڽ��� ���纻�� ����� �����Լ��� �׻� �����ϰ� ���˴ϴ�.
	virtual Shape* clone() const 
	{
		Shape* p1 = new Shape(*this); // ���� �����ڸ� ����ϰų� 
		// p1->color = color   	      // �Ǵ� ���⼭ ��� ����� ����
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
			std::cout << "���° ������ ���� �ұ�� >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->clone()); // ������
								// k��° ������ � ���� ���� ������ �ʿ� ����.
								// ���ο� ������ �߰��Ǿ
								// �� ������ ���� ���� �ʴ´�.
								// OCP�� �����ϴ� ���� �ڵ�. 
		}
	}
}

