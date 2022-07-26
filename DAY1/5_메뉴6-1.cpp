#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 


struct NotImplemented {};

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& s) : title(s) {}
	virtual ~BaseMenu() {}

	std::string getTitle() const { return title; }

	virtual void command() = 0;

	virtual BaseMenu* getSubMenu(int idx)
	{
		throw NotImplemented();
		return nullptr;
	}
	virtual void addMenu(BaseMenu* )
	{
		throw NotImplemented();
	}
	virtual void removeMenu(BaseMenu*)
	{
		throw NotImplemented();
	}

};



class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& s, int n) : BaseMenu(s), id(n) {}

	void command()
	{
		std::cout << getTitle() << "메뉴 선택됨" << std::endl;
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v; // <<=== 핵심
public:
	PopupMenu(const std::string& s) : BaseMenu(s) {}

	void addMenu(BaseMenu* p) { v.push_back(p); }

	void command()
	{
		while (1)
		{
			system("cls");

			int sz = v.size();
			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->getTitle() << std::endl;
			}
			std::cout << sz + 1 << ". 종료" << std::endl;
			std::cout << "메뉴를 선택하세요" << std::endl;

			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1)
				break;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			v[cmd - 1]->command();
		}

	}

	// 하위 메뉴를 반환하는 함수
	BaseMenu* getSubMenu(int idx) { return v[idx]; }
};

int main()
{
	PopupMenu* root = new PopupMenu("root");
	PopupMenu* pm1 = new PopupMenu("해상도 변경");

	root->addMenu(pm1);

	pm1->addMenu(new MenuItem("HD", 11));
	pm1->addMenu(new MenuItem("FHD", 12));
	pm1->addMenu(new MenuItem("UHD", 13));
	pm1->addMenu(new MenuItem("8K", 14));


	root->getSubMenu(0)->addMenu(new MenuItem("16K", 15));
	root->getSubMenu(0)->getSubMenu(0)->addMenu(new MenuItem("16K", 15));
									// MenuItem은  addMenu 를 override 하지 않았으므로
									// 예외 발생
	root->command();
}
// Base* p = new Derived,  Base로 부터 파생된 클래스;
// p->f();
// static type check 언어 : 컴파일 시에 Base 안에 f()가 없으면 컴파일 에러

// dynamic type check(python) : 실행시간에 p가 가리키는 객체에 f()가 없으면
//								예외 발생
//								컴파일 시간은 항상 성공



