#include <iostream>
#include <vector>

// �ٽ� 1. ��� ������ "Ÿ��" ���� ���� �ϸ� ���ϴ�.
// 
// �ٽ� 2. ��� ������ ������ ��� Ŭ����(Shape) �� �ִٸ�
//        ��� ������ �ϳ��� �����̳�(vector)�� �����Ҽ� �ִ�..

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
//	std::vector<Rect*> v; // Rect�� ���� ������ vector
//	std::vector<void*> v; // ��� Ÿ���� �ּҸ� ����
	std::vector<Shape*> v; // ��� ������ ������ ����

}

