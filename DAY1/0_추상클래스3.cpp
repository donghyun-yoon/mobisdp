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
	void UseCamera(ICamera* p) { p->Take(); }
};

// ���� ��� ī�޶�� �ݵ�� ��Ģ�� ���Ѿ� �մϴ�.
class Camera : public ICamera
{
public:
	void Take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void Take() { std::cout << "Take HD Picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void Take() { std::cout << "Take UHD Picture" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);

	HDCamera hc;
	p.UseCamera(&hc); // ok

	UHDCamera uhc;
	p.UseCamera(&uhc); // ok.. ���߿� �߰��� Ŭ������ 
						//		People Ŭ���� �������� ��밡��
						// OCP ��Ģ�� �����ϴ� ������ �ڵ�..!!

}





