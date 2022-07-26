// 2_메뉴1.cpp  - 55 page
#include <iostream>

// C 언어   : 프로그램이란 main 함수 부터 순차적으로 실행되는 실행흐름이다.
// C++ 언어(객체지향) : 프로그램이란 객체를 생성하고, 관계를 맺고, 객체간 통신하는것

int main()
{
	printf("1. 김밥\n");
	printf("2. 라면\n");
	printf("메뉴를 선택하세요 >> ");

	int cmd;
	std::cin >> cmd;

	switch (cmd)
	{
	case 1: break;
	case 2: break;
	}

}


