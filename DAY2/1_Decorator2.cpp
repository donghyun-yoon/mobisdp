#include <iostream>

class SpaceShip 
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};

// ���                : Ŭ������ ����� �߰��ϴ� ��
// ����(�����ͶǴ� ����) : ��ü�� ����� �߰��Ҽ� �ִ�.
class LeftMissile 
{
	SpaceShip* ship;  // �ٽ� : ������ �Ǵ� ����..
					  //       �ᱹ �ܺο� �̹� ������� ��ü�� ����Ű�� ��
public:
	LeftMissile(SpaceShip* s) : ship(s) {}

	void Fire()
	{
		ship->Fire(); // ���� ��ü�� ����� ����ϰ�, 
		std::cout << "Fire Left Missile" << std::endl; // ���ο� ����߰�
	}
};

int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm(&ss); // ss ��ü�� ����� �߰��ϴ� lm ��ü
	lm.Fire();
}


