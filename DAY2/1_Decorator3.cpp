#include <iostream>

// 우주선과 우주선이 기능을 추가하는 객체(데코레이터, 포장지)는 
// 공통의 기반 클래스 필요

// 포장지는 객체를 포장하지만 "포장된 객체를 다시 포장"할수 있다.
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

	RightMissile rm(&lm); // 기능을 추가한 객체에 다시 기능 추가
	rm.Fire();
}


