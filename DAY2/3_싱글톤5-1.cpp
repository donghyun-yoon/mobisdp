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

	// 아래 코드가 "Double Check Locking Pattern" 이라고 불리는
	// DCLP 기술 입니다.
	// 생성시 : 2번의 if 문과 lock 사용 => if 문 1회의 오버헤드
	// 생성후 : 1번의 if 문 사용 - lock/unlock 이 없으므로 성능 향상. 
	// 하지만 C++에서는 사용하지 마세요. 
	static Cursor& getInstance()
	{
		if (pinstance == nullptr)
		{
			m.lock();

			if (pinstance == nullptr)
				pinstance = new Cursor;

			m.unlock();
		}

		return *pinstance;
	}
};

Cursor* Cursor::pinstance = nullptr;
std::mutex Cursor::m;

int main()
{
	Cursor& c1 = Cursor::getInstance();

}








