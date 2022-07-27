// 3_추상팩토리 - 147
#include <iostream>
using namespace std;


// QT 라이브러리의 특징
// calc.exe -style:OSX
// calc.exe -style:Windows


// 모든 종류의 컨트롤은 공통의 기반 클래스 필요
struct IButton
{
	virtual void Draw() = 0;
	virtual ~IButton() {}
};
struct IEdit
{
	virtual void Draw() = 0;
	virtual ~IEdit() {}
};


struct WinButton : public IButton
{
	void Draw() { cout << "Draw WinButton" << endl; }
};
struct WinEdit : public IEdit
{
	void Draw() { cout << "Draw WinEdit" << endl; }
};
struct OSXButton : public IButton
{
	void Draw() { cout << "Draw OSXButton" << endl; }
};
struct OSXEdit : public IEdit
{
	void Draw() { cout << "Draw OSXButton" << endl; }
};

//-------------------------------------------------------------

// 추상 팩토리(Abstract Factory) 패턴 : 제품의군을 생성하기 위한 공장의 인터페이스를 제공한다.
//									    공장을 교체하면 다양한 제품의 군을 변경할수 있다.

// "Factory 라는 패턴"은 없습니다.
// "Abstract Factory" 라는 패턴이 있습니다.

struct IFactory
{
	virtual IButton* CreateButton() = 0;
	virtual IEdit*   CreateEdit() = 0;
	virtual ~IFactory() {}
};

class WinFactory : public IFactory
{
public:
	IButton* CreateButton() { return new WinButton; }
	IEdit*   CreateEdit()   { return new WinEdit; }
};
class OSXFactory : public IFactory
{
public:
	IButton* CreateButton() { return new OSXButton; }
	IEdit*   CreateEdit()   { return new OSXEdit; }
};
int main(int argc, char** argv)
{
	IFactory* factory;

	if (strcmp(argv[1], "-style:OSX") == 0)
		factory = new OSXFactory;
	else
		factory = new WinFactory;



	// 이제 UI 가 필요하면 공장에서 만들면 됩니다.
	IButton* btn = factory->CreateButton();
	btn->Draw();
}









