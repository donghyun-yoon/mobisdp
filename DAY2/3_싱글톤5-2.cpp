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
				pinstance = new Cursor; // 1. 메모리 할당
										// 2. 생성자 호출

				// 위 한줄은 아래의 3줄처럼 동작합니다.
				// 1. Cursor* temp = sizeof(Cursor) 크기의 메모리할당;
				// 2. 할당된 temp 주소에 생성자 호출(Cursor::Cursor());
				// 3. pinstance = temp;

				// 그런데, 위 3줄에서 3, 2번의 순서를 변경하면
				// "temp" 변수를 없앨수 있습니다.
				// => 컴파일러가 최적화!!
				// 1. pinstance = 메모리할당
				// 2. pinstance 메모리에 생성자 호출

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








