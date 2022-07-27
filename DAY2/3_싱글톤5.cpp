#include <iostream>
#include <mutex>

class Cursor
{
private:
	Cursor() { std::cout << "Cursor()" << std::endl; }
public:
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

public:
	static Cursor* pinstance;
	static std::mutex m;

	// 아래 코드는 
	// 1. 유일한 객체를 생성할때 lock/unlock 합니다. <= 필요합니다.
	// 2. 이미 생성된 객체를 반환 할때도 lock/unlock 합니다. <= 문제점!
	static Cursor& getInstance()
	{
		m.lock();

		if (pinstance == nullptr)
			pinstance = new Cursor; 

		m.unlock();

		return *pinstance;
	}
};

Cursor* Cursor::pinstance = nullptr;
std::mutex Cursor::m;

int main()
{
	Cursor& c1 = Cursor::getInstance();

}








