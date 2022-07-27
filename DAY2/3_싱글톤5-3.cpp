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
		// C++11 ���ʹ� �޸� �潺�� ����ϸ� DCLP �� �����ϰ� ��밡���մϴ�
		// release ������ �ڵ�� acquire ���Ŀ��� �ݵ�� ����Ǿ�� �Ѵ�.
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








