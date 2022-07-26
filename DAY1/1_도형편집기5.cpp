#include <iostream>
#include <vector>

// �ٽ� 8. template method ������ ����
// => ������ ���� ��ü ���� �帧�� ���� �Լ��� ��� Ŭ������ ����
// => ���ؾ� �ϴ� �κи� �����Լ�ȭ �ؼ� �Ļ� Ŭ������ ������ �Ҽ� �ְ�
// => ���� �θ� ���Ǵ� ������ ������ �ϳ�..


class Shape
{
protected:
	int color;
public:
	void setColor(int c) { color = c; }
	int  getColor() const { return color; }

	// ���뼺�ȿ� �ִ� �������� ã�Ƽ� �и��Ѵ�.
	// => ������ ���� �帧�ӿ� �ִ� ���ϴ� �κ��� ã�´�.
	// => ���ϴ� �ڵ�� �����Լ��� �и��Ѵ�.
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
			std::cout << "���° ������ ���� �ұ�� >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->clone()); 
		}
	}
}

