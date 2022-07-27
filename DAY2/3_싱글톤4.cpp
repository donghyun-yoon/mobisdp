#include <iostream>
#include <mutex>

// 동기화 객체를 직접 lock/unlock 하면 "deadlock" 의 가능성이 있습니다.
// 항상 생성자/소멸자로 자원을 관리하세요.

template<typename T> 
class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); };
	~lock_guard()             { mtx.unlock(); }
};





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



	static Cursor& getInstance()
	{
		{
			std::lock_guard<std::mutex> g(m); // 이미 C++ 표준에 
											// lock_guard가 있습니다.
	//		lock_guard<std::mutex> g(m); // 생성자/소멸자를 생각해 보세요
	//		m.lock();

			if (pinstance == nullptr)
				pinstance = new Cursor; // 유일한 객체를 힙에 생성

	//		m.unlock();
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








