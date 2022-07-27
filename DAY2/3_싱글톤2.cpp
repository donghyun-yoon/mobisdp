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
//	static Cursor instance;   // 2. 유일한 객체가 static 멤버 데이타

	static Cursor& getInstance()
	{
		static Cursor instance; // 1. 오직 한개의 객체를 static 지역변수로 
		return instance;
	}
};
//Cursor Cursor::instance;

int main()
{
//	Cursor& c1 = Cursor::getInstance();

}








