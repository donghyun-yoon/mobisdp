#include <iostream>

// 방법 1. item 상태에 따른 조건 분기
// => 모든 동작 함수에 조건 분기문장이 있게 된다.
// => 새로운 아이템이 추가되면 모든 동작 함수가 수정된다.
class Charater
{
	int gold;
	int item;
public:
	void run()
	{ 
		if( item == 1)
			std::cout << "run" << std::endl; 

		else if( item == 2)
			std::cout << "fast run" << std::endl;
	}
	void attack() 
	{
		// 여기도 조건분기문.. 
		std::cout << "attack" << std::endl; 
	}
};


int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();
}



