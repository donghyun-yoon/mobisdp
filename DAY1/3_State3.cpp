#include <iostream>

// 방법 2. 변하는 것을 가상함수로.. 

class Charater
{
	int gold;
	int item;
public:
	void run() { dorun(); }
	void attack() { doattack(); }

	virtual void dorun() { std::cout << "run" << std::endl; }
	virtual void doattack() { std::cout << "attack" << std::endl; }
};

class RedItemCharacter : public Charater
{
public:
	virtual void dorun() { std::cout << "fast run" << std::endl; }
	virtual void doattack() { std::cout << "power attack" << std::endl; }
};
int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();

	p = new RedItemCharacter; // 이코드는 기존 캐릭터(객체)의 동작변경이 아닌
	p->run();				// 동작이 변경된 새로운 캐릭터를 만든것
	p->attack();			// 즉, 기존 객체는 변화가 없고, 새로운 객체 생성

}



