#include <iostream>
#include <thread>
#include <chrono>

class Cursor
{

private:
	Cursor() 
	{
		std::cout << "Cursor 생성자 시작" << std::endl;

		std::this_thread::sleep_for(std::chrono::seconds(10));

		std::cout << "Cursor 생성자 종료" << std::endl;
	}

public:
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

public:
	// 아래 코드는 멀티스레드에 안전 할까요 ?
	static Cursor& getInstance()
	{
		std::cout << std::this_thread::get_id() << " 도착" << std::endl;
		static Cursor instance;
		std::cout << std::this_thread::get_id() << " 반환" << std::endl;

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








