#include <iostream>

class Cursor
{
private:
	Cursor() { std::cout << "Cursor()" << std::endl; }
public:
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

public:
	static Cursor* pinstance;

	static Cursor& getInstance()
	{
		if (pinstance == nullptr)
			pinstance = new Cursor; // ������ ��ü�� ���� ����

		return *pinstance;	
	}
};
Cursor* Cursor::pinstance = nullptr;

int main()
{
	Cursor& c1 = Cursor::getInstance();

}








