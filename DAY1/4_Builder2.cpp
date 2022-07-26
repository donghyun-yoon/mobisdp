// 2_Builder
#include <iostream>
#include <string>

// �౸���� ĳ���͸� ������ ���ô�.
// ����, ������, �Źߵ��� �����Ҽ� �ֽ��ϴ�.
typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}��� ����

// ���ӿ��� ���� ���ÿ� ���� ĳ������ ����� �޶����ϴ�.
struct IBuilder
{
	virtual Hat     makeHat() = 0;
	virtual Uniform makeUniform() = 0;
	virtual Hat     makeShoes() = 0;

	virtual ~IBuilder() {}
};

// ĳ���͸� ����� Ŭ����
class Director
{
	IBuilder* builder = nullptr;
public:
	void setBuilder(IBuilder* p) { builder = p; }

	Character construct()
	{
		// ĳ���͸� ����� ������ ����������
		// �� ������ ����� �޶����� �ֽ��ϴ�.
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
	virtual Hat makeHat() override	       { return Hat("��"); }
	virtual Uniform makeUniform() override { return Uniform("�Ѻ�"); }
	virtual Shoes makeShoes()  override    { return Shoes("����"); }
};
class American : public IBuilder
{
public:
	virtual Hat makeHat() override { return Hat("�߱�����"); }
	virtual Uniform makeUniform() override { return Uniform("�纹"); }
	virtual Shoes makeShoes()  override { return Shoes("����"); }
};

int main()
{
	Korean k;
	American a;
	Director d;
	d.setBuilder(&k); // ���� ������ �����ϸ� �� �κп��� �ٸ� ������ �����ϸ�˴ϴ�.
	Character c = d.construct();
	std::cout << c << std::endl;

}