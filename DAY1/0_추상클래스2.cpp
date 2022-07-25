//1_�߻�Ŭ����2.cpp
#include <iostream>

// OCP
// ��� Ȯ�忡�� ���� �ְ�(Open, ���ο� Ŭ����/����� �߰��Ǿ)
// �ڵ� �������� ���� �־��(Close)
// �Ѵٴ� ��Ģ(Principle)
// "���� ����� ��Ģ"

// ���� ����(tightly coupling)
// => �ϳ��� Ŭ������ �ٸ� Ŭ���� ����, Ŭ���� �̸��� ���� ����ϴ� ��
// => ��ü �Ұ�����, Ȯ�强����, ������ ������ 








class Camera
{
public:	
	void Take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera
{
public:
	void Take() { std::cout << "Take HD Picture" << std::endl; }
};

class People
{
public:	
	void UseCamera(Camera* p) { p->Take(); }
	void UseCamera(HDCamera* p) { p->Take(); }
};

int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);

	HDCamera hc;
	p.UseCamera(&hc); // ?
}





