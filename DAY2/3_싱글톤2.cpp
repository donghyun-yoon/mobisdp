#include <iostream>

class Cursor
{
private:
	Cursor() { std::cout << "Cursor()" << std::endl; }
public:
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

public:
//	Cursor instance;   // error.
//	static Cursor instance;   // 2. ������ ��ü�� static ��� ����Ÿ

	static Cursor& getInstance()
	{
		static Cursor instance; // 1. ���� �Ѱ��� ��ü�� static ���������� 
		return instance;
	}
};
//Cursor Cursor::instance;

int main()
{
//	Cursor& c1 = Cursor::getInstance();

}








