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

	// �Ʒ� �ڵ尡 "Double Check Locking Pattern" �̶�� �Ҹ���
	// DCLP ��� �Դϴ�.
	// ������ : 2���� if ���� lock ��� => if �� 1ȸ�� �������
	// ������ : 1���� if �� ��� - lock/unlock �� �����Ƿ� ���� ���. 
	// ������ C++������ ������� ������. 
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








