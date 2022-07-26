// Decorator - 65 page
#include <iostream>

class SpaceShip // ���� ���༱
{
public:
	void Fire()	{ std::cout << "Fire Missile" << std::endl; }
};
// ����� ����� ����� �߰�
// => ��ü�� ��� �߰��� �ƴ϶�, Ŭ������ ����� �߰��Ѱ�
// => ������ ��� �߰��� �ƴ�, ����(�ڵ� �ۼ���) ����� �߰�.
class LeftMissile : public SpaceShip
{
public:
	void Fire()
	{
		SpaceShip::Fire(); // ���� ����� ����ϰ�
		std::cout << "Fire Left Missile" << std::endl; // ���ο� ����߰�
	}
};

int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm;	// ss��� ��ü�� ����� �߰��� ���� �ƴ϶�
				    // ����� �߰��� ���ο� ��ü�� ���� �Ѱ�
	lm.Fire();
}





// github.com/codenuri/mobisdp  

// ���� "DAY2_�����ҽ�.zip"

// ������Ʈ �޴�,  DAY2�Ӽ� �޴�
// �÷��� ��������, Windows SDK ���� ����