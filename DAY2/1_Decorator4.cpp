#include <iostream>


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

// ���ּ� ��ü�� ����� �߰��ϴ� ��ü����
// ������ Ư¡�� ���� ������ �ֽ��ϴ�.
// �� ���� ��� Ŭ������ ���� ��ӹ޴°��� �����ϴ�.

class SpaceShipDecorator : public Item
{
	Item* ship;
public:
	SpaceShipDecorator(Item* s) : ship(s) {}
};

class LeftMissile : public SpaceShipDecorator
{
public:
	LeftMissile(Item* s) : SpaceShipDecorator(s) {}

	void Fire()
	{
		ship->Fire();
		std::cout << "Fire Left Missile" << std::endl;
	}
};
class RightMissile : public SpaceShipDecorator
{
public:
	RightMissile(Item* s) : SpaceShipDecorator(s) {}

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

	RightMissile rm(&lm); 
	rm.Fire();
}


