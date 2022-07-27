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

	static Cursor& getInstance()
	{
		// C++11 부터는 메모리 펜스를 사용하면 DCLP 를 안전하게 사용가능합니다
		// release 이전의 코드는 acquire 이후에서 반드시 적용되어야 한다.
		if (pinstance == nullptr)
		{
			std::atomic_thread_fence(std::memory_order_acquire);

			m.lock();

			if (pinstance == nullptr)
			{
				pinstance = new Cursor; 

				std::atomic_thread_fence(std::memory_order_release);
			}

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








