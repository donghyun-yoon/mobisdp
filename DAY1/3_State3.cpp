#include <iostream>

// ��� 2. ���ϴ� ���� �����Լ���.. 

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

	p = new RedItemCharacter; // ���ڵ�� ���� ĳ����(��ü)�� ���ۺ����� �ƴ�
	p->run();				// ������ ����� ���ο� ĳ���͸� �����
	p->attack();			// ��, ���� ��ü�� ��ȭ�� ����, ���ο� ��ü ����

}



