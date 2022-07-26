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

	p->setState(&ri); // 객체의 상태(멤버데이타)는 유지되지만
	p->run();		  // 객체의 모든 동작이 변경됩니다.
	p->attack();      // "마치 다른 클래스를 사용하는 것 처럼 보입니다"

	p->setState(&si);
	p->run();
	p->attack();

	p->setState(&ni);
	p->run();
	p->attack();
}

// 변하는 것은 다른 클래스로 분리하고,
// 인터페이스 기반으로 교체를 하는 디자인 패턴은 3가지 입니다.
// 이 3가지 패턴은 "클래스 Diagram" 이 동일하고, 코딩도 거의 유사합니다.
// 그런데, 왜? 어떤의도(용도)로 사용하는가에 따라 패턴의 이름이 다릅니다.

// strategy : 객체가 사용하는 "알고리즘(전략, 정책)" 의 교체
//           => 바둑,체스 게임등에서 다음수 예측 방법을 level에 따라 교체 

// state : 객체의 상태(아이템 획득여부)에 따라, 객체의 모든(대부분의)동작 교체
//         마치 다른 클래스를 사용하는 것 처럼

// builder : 복잡한 객체의 생성에 사용.
//          동일한 공정으로 만드는데, 각 공정의 결과는 다를수 있을때. 



