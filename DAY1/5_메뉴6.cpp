#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 


class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& s) : title(s) {}
	virtual ~BaseMenu() {}

	std::string getTitle() const { return title; }

	// 모든 메뉴는 선택될수 있다.
	virtual void command() = 0;
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


	// 아래 한줄을 생각해 봅시다.
	// 1. getSubMenu 가 BaseMenu* 로 반환하므로 "static_cast<PopupMenu*>" 로
	//    캐스팅후 사용하게 하자.
	// 2. addMenu 를 BaseMenu 에 선언해주고, 캐스팅 없이 사용하게 하자.
	//    단, MenuItem 에 대해서 addMenu 호출시 예외 나오게 하자.
	root->getSubMenu(0)->addMenu(new MenuItem("16K", 15));
	//<- 해상도 변경 메뉴 ->



	// 이제 최상위 메뉴를 누르면 시작됩니다.
	root->command();
}




