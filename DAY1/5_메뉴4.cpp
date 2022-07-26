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
		std::cout << getTitle() << "�޴� ���õ�" << std::endl;
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
			std::cout << sz + 1 << ". ����" << std::endl;
			std::cout << "�޴��� �����ϼ���" << std::endl;

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
	MenuItem m1("��ġ���", 11);
	MenuItem m2("�Ұ����", 12);
	MenuItem m3("���",   13);
	MenuItem m4("������", 14);

	PopupMenu kimbam("����");
	kimbam.addMenu(&m1);
	kimbam.addMenu(&m2);

	PopupMenu pm("������ �޴�");
	pm.addMenu(&kimbam); // <<== �̺κ��� �� ������ �ٽ� �Դϴ�.
						 // ����� �����Դϴ�. 
						 // �� �ڵ尡 �����ϵ��� ����� ���� �̿����� �ٽ��Դϴ�.
	pm.addMenu(&m3);
	pm.addMenu(&m4);
	pm.command(); 
}




