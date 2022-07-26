#include <iostream>
#include <vector>

// ������ �ܰ�.
// => �ڵ� ����
class NotImplemented {}; // ���ܷ� ����� Ŭ����

class Shape
{
protected:
	int color;
public:
	void setColor(int c) { color = c; }
	int  getColor() const { return color; }

protected:
	// �����Լ�     : �Ļ� Ŭ������ ������ ���� ������ ����Ʈ ���� �����ϰڴٴ��ǵ�
	// ���� �����Լ� : �ݵ�� ������ �Ѵٰ� ��Ű�� ��
	// 
	// ����, ����(Shape)�� �߻��� �����̴�. 
	// ���Ǽ��迡�� ���� ��ü�� �����Ҽ� ���� �׸����� ����.
//	virtual void drawImp() {std::cout << "draw Shape" << std::endl;	}
	virtual void drawImp() = 0;

public:
	void draw()
	{
		std::cout << "mutex.lock" << std::endl;
		drawImp();
		std::cout << "mutex.unlock" << std::endl;
	}
	// clone() �� "�����Լ�" ���ٴ� "���� �����Լ�" �����ϴ�.
	// �׷���, ���� �����Լ��� "�ݵ�� �����ض�" ��� �ǵ� �Դϴ�.
	// �������� ������ "�����Ͻð�����"
	// virtual Shape* clone() const = 0;
	
	// �׷���, �Ʒ� ó�� �����ϴ� ��쵵 �ֽ��ϴ�.
	// 1. ������ ���ߴµ�, ������� ������ ���� �ƴ�
	// 2. ������ ���ߴµ�, ����ϸ� ���� �߻�(����ð� �߻�)
	// 3. ����Ϸ��� "������ �϶�" ��� �ǹ̸� ���� �ڵ�
	virtual Shape* clone() const
	{
		throw NotImplemented();
		return nullptr;
	}

	// Shape �� ��� Ŭ������ ���˴ϴ�.
	// �Ҹ��ڴ� �ݵ�� �����Լ� �̾�� �մϴ�
	virtual ~Shape() {}

};

class Rect : public Shape
{
public:
	// 1. �����Լ� �����ǽ� �� "override" ���̼���
	// 2. �����Լ� �����ǽ� �������� virtual ���̶�� �ߴµ�,,
	//    ����� override �����Ƿ� "virtual" �� ���� �������� �ʽ��ϴ�.

	virtual void drawImp() override { std::cout << "draw Rect" << std::endl; }

	// 3. �����Լ� �����ǽ� ��ȯ Ÿ���� ���� �����մϴ�.
	//   => ��, ��� ������ Ÿ�����θ� ����. 
	virtual Rect* clone() const override
	{
		Rect* p1 = new Rect(*this);
		return p1;
	}
};

class Circle : public Shape
{
public:
	virtual void drawImp() override { std::cout << "draw Circle" << std::endl; }

	virtual Circle* clone() const override
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

			v.push_back(v[k]->clone());
		}
		else if (cmd == -1) break;
	}
	for (auto p : v)
		delete p;
}

