// 7_싱글톤1 - 123 page
#include <iostream>

// 싱글톤 : 오직 한개의 객체만 존재하는 것.
// => 오직 한개의 객체만 존재하며
// => 프로그램의 어디서도 "동일한 방법"으로 오직 한개인 객체에 접근할수 있다.

// => 결국 전역변수 입니다.!!
// => 싱글톤을 사용한다는 것은 결국 전역변수를 사용하는 것과 유사합니다.
// => 각 모듈의 "의존성"이 높아지고 좋지 않습니다. 그래서, 비판이 많은 패턴!!
//    


class Cursor
{
	// 규칙 1. 생성자를 private 놓아서, 외부에서 객체생성할수 없게 한다.
private:
	Cursor() {}

public:
	// 규칙 2. 컴파일러에게 복사 생성자와 대입연산자를 만들지 못하게
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;


	// 규칙 3. 오직 한개의 객체만 만드는 static 멤버 함수 제공
public:
	static Cursor& getInstance()
	{
		static Cursor instance;
		return instance;
	}
};
int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

	Cursor c3 = c1; // 이렇게 만들어지는 것도 막아야 합니다.

//	Cursor c1, c2;
}








