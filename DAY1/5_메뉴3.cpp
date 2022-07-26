#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& s, int n) : title(s), id(n) {}

	std::string getTitle() const { return title; }

	void command()
	{
		std::cout << getTitle() << "메뉴 선택됨" << std::endl;
		_getch();
	}
};

class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& s) : title(s) {}

	void addMenu(MenuItem* p) { v.push_back(p); }

	// 팝업메뉴를 선택할때 해야 할일을 생각해보세요 - 핵심!
	void command()
	{
		while (1)
		{
			system("cls"); // 화면 지우기

			int sz = v.size();
			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->getTitle() << std::endl;
			}
			std::cout << sz + 1 << ". 종료" << std::endl;
			std::cout << "메뉴를 선택하세요"  << std::endl;

			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1) // 종료 선택시
				break;

			if (cmd < 1 || cmd > sz + 1) // 잘못된 선택
				continue;


			// 선택한 메뉴를 실행
			v[cmd - 1]->command();
		}



	}
};










int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	PopupMenu pm("오늘의 메뉴");
	pm.addMenu(&m1);
	pm.addMenu(&m2);
	pm.command(); // 팝업메뉴 선택시 할일을 생각해 보세요
}




