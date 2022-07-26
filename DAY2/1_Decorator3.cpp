#include <iostream>

// ���ּ��� ���ּ��� ����� �߰��ϴ� ��ü(���ڷ�����, ������)�� 
// ������ ��� Ŭ���� �ʿ�

// �������� ��ü�� ���������� "����� ��ü�� �ٽ� ����"�Ҽ� �ִ�.
struct Item
{
	virtual void Fire() = 0;
	virtual ~Item() {}
};


class SpaceShip : public Item
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};


class LeftMissile : public Item
{
	Item* ship;
public:
	LeftMissile(Item* s) : ship(s) {}

	void Fire()
	{
		ship->Fire();
		std::cout << "Fire Left Missile" << std::endl; 
	}
};

class RightMissile : public Item
{
	Item* ship;
public:
	RightMissile(Item* s) : ship(s) {}

	void Fire()
	{
		ship->Fire();
		std::cout << "Fire Right Missile" << std::endl;
	}
};


int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm(&ss);
	lm.Fire();

	RightMissile rm(&lm); // ����� �߰��� ��ü�� �ٽ� ��� �߰�
	rm.Fire();
}


