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
		if (pinstance == nullptr)
		{
			m.lock();

			if (pinstance == nullptr)
			{
				pinstance = new Cursor; // 1. �޸� �Ҵ�
										// 2. ������ ȣ��

				// �� ������ �Ʒ��� 3��ó�� �����մϴ�.
				// 1. Cursor* temp = sizeof(Cursor) ũ���� �޸��Ҵ�;
				// 2. �Ҵ�� temp �ּҿ� ������ ȣ��(Cursor::Cursor());
				// 3. pinstance = temp;

				// �׷���, �� 3�ٿ��� 3, 2���� ������ �����ϸ�
				// "temp" ������ ���ټ� �ֽ��ϴ�.
				// => �����Ϸ��� ����ȭ!!
				// 1. pinstance = �޸��Ҵ�
				// 2. pinstance �޸𸮿� ������ ȣ��

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








