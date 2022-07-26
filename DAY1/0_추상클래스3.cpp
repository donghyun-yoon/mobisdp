//1_�߻�Ŭ����2.cpp
#include <iostream>



// ī�޶� ����ڿ� ī�޶� �����ڰ� ���Ѿ� �ϴ� ��Ģ�� ���� �����Ѵ�.
// ��Ģ : "��� ī�޶�� �Ʒ� Ŭ������ ���� �Ļ� �Ǿ�� �Ѵ�."

class ICamera
{
public:
	virtual void Take() = 0;
};

// ���� ī�޶� ���, ��Ģ�� �����Ƿ�
// ����ڴ� ��Ģ ��θ� ����ϸ� �˴ϴ�.
class People
{
public:
	void UseCamera(? p) { p->Take(); }
};










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





