#include <iostream>

// 객체의 상태(캐릭터의 획득한 아이템의 종류)에 따라 모든 동작이 변경되어야 한다.
// => 단, 객체의 멤버 데이타는 계속유지

// 변해야 하는 동작을 담은 인터페이스 설계
struct IState
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IState() {}

	// 그외, jump(), slide()등
};
class Charater
{
	int gold;
	int item;
	IState* pstate = nullptr;
public:
	void setState(IState* p) { pstate = p; }
	void run()    { pstate->run(); }
	void attack() { pstate->attack(); }
};

// 이제 각 아이템별로 동작을 정의하면 됩니다.
class RedItem : public IState
{
public:
	void run()    { std::cout << "fast run" << std::endl; }
	void attack() { std::cout << "power" << std::endl; }
};
class BlueItem : public IState
{
public:
	void run() { std::cout << "run" << std::endl; }
	void attack() { std::cout << "power attack" << std::endl; }
};
class StarItem : public IState
{
public:
	void run() { std::cout << "fast run" << std::endl; }
	void attack() { std::cout << "power attack" << std::endl; }
};
class NoItem : public IState
{
public:
	void run()    { std::cout << "run" << std::endl; }
	void attack() { std::cout << "attack" << std::endl; }
};

int main()
{
	NoItem ni;
	RedItem ri;
	BlueItem bi;
	StarItem si;
	Charater* p = new Charater;
	p->setState(&ni);
	p->run();
	p->attack();

	p->setState(&ri);
	p->run();
	p->attack();

	p->setState(&si);
	p->run();
	p->attack();

	p->setState(&ni);
	p->run();
	p->attack();


}



