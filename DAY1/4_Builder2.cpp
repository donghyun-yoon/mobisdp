// 2_Builder
#include <iostream>
#include <string>

// 축구게임 캐릭터를 생각해 봅시다.
// 모자, 유니폼, 신발등을 변경할수 있습니다.
typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}라고 가정

// 게임에서 국가 선택에 따라 캐릭터의 모양이 달라집니다.
struct IBuilder
{
	virtual Hat     makeHat() = 0;
	virtual Uniform makeUniform() = 0;
	virtual Hat     makeShoes() = 0;

	virtual ~IBuilder() {}
};

// 캐릭터를 만드는 클래스
class Director
{
	IBuilder* builder = nullptr;
public:
	void setBuilder(IBuilder* p) { builder = p; }

	Character construct()
	{
		// 캐릭터를 만드는 공정은 동일하지만
		// 각 공정의 결과는 달라질수 있습니다.
		Character c;
		c = c + builder->makeHat();
		c = c + builder->makeUniform();
		c = c + builder->makeShoes();
		return c;
	}
};
class Korean : public IBuilder
{
public:
	virtual Hat makeHat() override	       { return Hat("갓"); }
	virtual Uniform makeUniform() override { return Uniform("한복"); }
	virtual Shoes makeShoes()  override    { return Shoes("고무신"); }
};
class American : public IBuilder
{
public:
	virtual Hat makeHat() override { return Hat("야구모자"); }
	virtual Uniform makeUniform() override { return Uniform("양복"); }
	virtual Shoes makeShoes()  override { return Shoes("구두"); }
};

int main()
{
	Korean k;
	American a;
	Director d;
	d.setBuilder(&k); // 국가 선택을 변경하면 이 부분에서 다른 빌더를 전달하면됩니다.
	Character c = d.construct();
	std::cout << c << std::endl;

}