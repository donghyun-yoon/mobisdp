#include <iostream>
#include <mutex>

// ����ȭ ��ü�� ���� lock/unlock �ϸ� "deadlock" �� ���ɼ��� �ֽ��ϴ�.
// �׻� ������/�Ҹ��ڷ� �ڿ��� �����ϼ���.

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
			std::lock_guard<std::mutex> g(m); // �̹� C++ ǥ�ؿ� 
											// lock_guard�� �ֽ��ϴ�.
	//		lock_guard<std::mutex> g(m); // ������/�Ҹ��ڸ� ������ ������
	//		m.lock();

			if (pinstance == nullptr)
				pinstance = new Cursor; // ������ ��ü�� ���� ����

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








