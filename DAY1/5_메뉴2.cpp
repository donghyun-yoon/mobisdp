#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// �޴� �׸��� �����ϴ� Ŭ����
class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& s, int n) : title(s), id(n) {}

	std::string getTitle() const { return title; }

	void command()
	{
		std::cout << getTitle() << "�޴� ���õ�" << std::endl;
		_getch();
	}
};
int main()
{
	MenuItem m1("���", 11);
	MenuItem m2("���", 11);

	m1.command(); // �޴� ���ý� ȣ��Ǵ� �Լ�
}




