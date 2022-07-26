#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 메뉴 항목을 관리하는 클래스
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
int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 11);

	m1.command(); // 메뉴 선택시 호출되는 함수
}




