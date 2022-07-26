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
};



int main()
{
	MenuItem m1("참치김밥", 11);
	MenuItem m2("소고기김밥", 12);
	MenuItem m3("라면",   13);
	MenuItem m4("떡볶이", 14);

	PopupMenu kimbam("김밥류");
	kimbam.addMenu(&m1);
	kimbam.addMenu(&m2);

	PopupMenu pm("오늘의 메뉴");
	pm.addMenu(&kimbam); // <<== 이부분이 이 예제의 핵심 입니다.
						 // 현재는 에러입니다. 
						 // 이 코드가 가능하도록 만드는 것이 이예제의 핵심입니다.
	pm.addMenu(&m3);
	pm.addMenu(&m4);
	pm.command(); 
}




