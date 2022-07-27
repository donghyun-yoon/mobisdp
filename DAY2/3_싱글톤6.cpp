#include <iostream>
#include <thread>
#include <chrono>

class Cursor
{

private:
	Cursor() 
	{
		std::cout << "Cursor ������ ����" << std::endl;

		std::this_thread::sleep_for(std::chrono::seconds(10));

		std::cout << "Cursor ������ ����" << std::endl;
	}

public:
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

public:
	// �Ʒ� �ڵ�� ��Ƽ�����忡 ���� �ұ�� ?
	// => C++11 ���� ���� �մϴ�.
	// => C++11 �������� �������� �ʾҽ��ϴ�.
	// => java, C# �� ��κ��� ���� ��� �����մϴ�.
	//    ��� ����� �߿��� ��� �����Դϴ�.
	static Cursor& getInstance()
	{
		std::cout << std::this_thread::get_id() << " ����" << std::endl;
		static Cursor instance;
		std::cout << std::this_thread::get_id() << " ��ȯ" << std::endl;

		return instance;
	}
};
int main()
{
	std::thread t1(&Cursor::getInstance);

	std::this_thread::sleep_for(std::chrono::seconds(3));

	std::thread t2(&Cursor::getInstance);

	t1.join();
	t2.join();
}








