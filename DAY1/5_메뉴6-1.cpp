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
		std::cout << getTitle() << "�޴� ���õ�" << std::endl;
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v; // <<=== �ٽ�
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

	// ���� �޴��� ��ȯ�ϴ� �Լ�
	BaseMenu* getSubMenu(int idx) { return v[idx]; }
};

int main()
{
	PopupMenu* root = new PopupMenu("root");
	PopupMenu* pm1 = new PopupMenu("�ػ� ����");

	root->addMenu(pm1);

	pm1->addMenu(new MenuItem("HD", 11));
	pm1->addMenu(new MenuItem("FHD", 12));
	pm1->addMenu(new MenuItem("UHD", 13));
	pm1->addMenu(new MenuItem("8K", 14));


	root->getSubMenu(0)->addMenu(new MenuItem("16K", 15));
	root->getSubMenu(0)->getSubMenu(0)->addMenu(new MenuItem("16K", 15));
									// MenuItem��  addMenu �� override ���� �ʾ����Ƿ�
									// ���� �߻�
	root->command();
}
// Base* p = new Derived,  Base�� ���� �Ļ��� Ŭ����;
// p->f();
// static type check ��� : ������ �ÿ� Base �ȿ� f()�� ������ ������ ����

// dynamic type check(python) : ����ð��� p�� ����Ű�� ��ü�� f()�� ������
//								���� �߻�
//								������ �ð��� �׻� ����



