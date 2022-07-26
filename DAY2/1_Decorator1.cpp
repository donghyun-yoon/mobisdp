// Decorator - 65 page
#include <iostream>

class SpaceShip // 우주 비행선
{
public:
	void Fire()	{ std::cout << "Fire Missile" << std::endl; }
};
// 상속을 사용한 기능의 추가
// => 객체에 기능 추가가 아니라, 클래스에 기능을 추가한것
// => 동적인 기능 추가가 아닌, 정적(코드 작성시) 기능을 추가.
class LeftMissile : public SpaceShip
{
public:
	void Fire()
	{
		SpaceShip::Fire(); // 원래 기능을 사용하고
		std::cout << "Fire Left Missile" << std::endl; // 새로운 기능추가
	}
};

int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm;	// ss라는 객체에 기능이 추가된 것이 아니라
				    // 기능이 추가된 새로운 객체를 생성 한것
	lm.Fire();
}





// github.com/codenuri/mobisdp  

// 에서 "DAY2_사전소스.zip"

// 프로젝트 메뉴,  DAY2속성 메뉴
// 플랫폼 도구집합, Windows SDK 버전 설정