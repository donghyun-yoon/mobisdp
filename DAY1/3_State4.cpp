#include <iostream>

// ��ü�� ����(ĳ������ ȹ���� �������� ����)�� ���� ��� ������ ����Ǿ�� �Ѵ�.
// => ��, ��ü�� ��� ����Ÿ�� �������

// ���ؾ� �ϴ� ������ ���� �������̽� ����
struct IState
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IState() {}

	// �׿�, jump(), slide()��
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

// ���� �� �����ۺ��� ������ �����ϸ� �˴ϴ�.
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

	p->setState(&ri); // ��ü�� ����(�������Ÿ)�� ����������
	p->run();		  // ��ü�� ��� ������ ����˴ϴ�.
	p->attack();      // "��ġ �ٸ� Ŭ������ ����ϴ� �� ó�� ���Դϴ�"

	p->setState(&si);
	p->run();
	p->attack();

	p->setState(&ni);
	p->run();
	p->attack();
}

// ���ϴ� ���� �ٸ� Ŭ������ �и��ϰ�,
// �������̽� ������� ��ü�� �ϴ� ������ ������ 3���� �Դϴ�.
// �� 3���� ������ "Ŭ���� Diagram" �� �����ϰ�, �ڵ��� ���� �����մϴ�.
// �׷���, ��? ��ǵ�(�뵵)�� ����ϴ°��� ���� ������ �̸��� �ٸ��ϴ�.

// strategy : ��ü�� ����ϴ� "�˰���(����, ��å)" �� ��ü
//           => �ٵ�,ü�� ���ӵ�� ������ ���� ����� level�� ���� ��ü 

// state : ��ü�� ����(������ ȹ�濩��)�� ����, ��ü�� ���(��κ���)���� ��ü
//         ��ġ �ٸ� Ŭ������ ����ϴ� �� ó��

// builder : ������ ��ü�� ������ ���.
//          ������ �������� ����µ�, �� ������ ����� �ٸ��� ������. 



