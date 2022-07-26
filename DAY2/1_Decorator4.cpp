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

// 우주선 객체에 기능을 추가하는 객체들은
// 공통의 특징이 많이 있을수 있습니다.
// 이 경우는 기반 클래스를 만들어서 상속받는것이 좋습니다.

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


