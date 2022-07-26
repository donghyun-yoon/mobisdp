#include <iostream>

class SpaceShip 
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};

// 상속                : 클래스에 기능을 추가하는 것
// 포함(포인터또는 참조) : 객체에 기능을 추가할수 있다.
class LeftMissile 
{
	SpaceShip* ship;  // 핵심 : 포인터 또는 참조..
					  //       결국 외부에 이미 만들어진 객체를 가리키는 것
public:
	LeftMissile(SpaceShip* s) : ship(s) {}

	void Fire()
	{
		ship->Fire(); // 기존 객체의 기능을 사용하고, 
		std::cout << "Fire Left Missile" << std::endl; // 새로운 기능추가
	}
};

int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm(&ss); // ss 객체에 기능을 추가하는 lm 객체
	lm.Fire();
}


