// 3_�߻����丮 - 147
#include <iostream>
using namespace std;


// QT ���̺귯���� Ư¡
// calc.exe -style:OSX
// calc.exe -style:Windows


// ��� ������ ��Ʈ���� ������ ��� Ŭ���� �ʿ�
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

// �߻� ���丮(Abstract Factory) ���� : ��ǰ�Ǳ��� �����ϱ� ���� ������ �������̽��� �����Ѵ�.
//									    ������ ��ü�ϸ� �پ��� ��ǰ�� ���� �����Ҽ� �ִ�.

// "Factory ��� ����"�� �����ϴ�.
// "Abstract Factory" ��� ������ �ֽ��ϴ�.

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



	// ���� UI �� �ʿ��ϸ� ���忡�� ����� �˴ϴ�.
	IButton* btn = factory->CreateButton();
	btn->Draw();
}









