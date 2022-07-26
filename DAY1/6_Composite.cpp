#include <iostream>
#include <vector>
#include <string>

// ���հ�ü(Folder, PopupMenu) �� 
// ������ü(File, MenuItem)�� �ƴ϶�
// ���հ�ü �ڽŵ� ���� �����Ҽ� �ִ�.
// => ������ ��� Ŭ������ �ʿ� �ϴ�.

// ������ü�� ���հ�ü�� ������ �����ϴ�.
// => ��� Ŭ������ �Լ�(����)�� ������ �Ѵ�

class Item
{
	std::string name;
public:
	Item(const std::string& s) : name(s) {}

	std::string getName() const { return name; }

	// ���ϰ� ���� ��� ũ�⸦ ���Ҽ� �ִ�.
	virtual int getSize() const = 0;
};

class File  : public Item
{
	int size;
public:
	File(const std::string& name, int sz) : Item(name), size(sz) {}

	virtual int getSize() const override
	{
		return size;
	}
};

class Folder : public Item
{
	std::vector<Item*> v; // <=== "Composite ������ �ٽ� �ڵ�"
public:
	Folder(const std::string& name) : Item(name) {}

	void addItem(Item* p) { v.push_back(p); }

	virtual int getSize() const override
	{
		int size = 0;

		for (auto p : v)
			size += p->getSize(); 

		return size;
	}
};



int main()
{
	Folder* root = new Folder("ROOT");
	Folder* fo1  = new Folder("A");
	Folder* fo2  = new Folder("B");
	
	root->addItem(fo1);
	root->addItem(fo2);

	File* f1 = new File("a.txt", 10);
	File* f2 = new File("b.txt", 20);

	fo1->addItem(f1);
	root->addItem(f2);

	// ������ �ڽŸ��� ũ��� �ֽ��ϴ�.
	// ������ �ڽŸ��� ũ��� ������ ũ�⸦ ���Ҽ� �ֽ��ϴ�.
	std::cout << f2->getSize() << std::endl; // 20
	std::cout << fo1->getSize() << std::endl; // 10
	std::cout << root->getSize() << std::endl; // 30
}

// Folder/File �� ������ 
// PopupMenu/MenuItem �� ������ �����մϴ�.
// ��, �̷� ��Ÿ�� �ڵ尡 �ʹ� ���Ƽ� "Composite" ���� �̶�� �̸��� �ο� �߽��ϴ�.

// ���� ���� ���� �̸�

// template method : ���ϴ� ���� �����Լ�ȭ!
// strategy
// state
// builder
// composite
// prototype : ���� ��ü�� �����ؼ� ���ο� ��ü ����
