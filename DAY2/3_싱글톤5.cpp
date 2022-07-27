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

	// �Ʒ� �ڵ�� 
	// 1. ������ ��ü�� �����Ҷ� lock/unlock �մϴ�. <= �ʿ��մϴ�.
	// 2. �̹� ������ ��ü�� ��ȯ �Ҷ��� lock/unlock �մϴ�. <= ������!
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








