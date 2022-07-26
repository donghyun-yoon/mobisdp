#include <iostream>
#include <vector>
#include <string>

// 복합객체(Folder, PopupMenu) 는 
// 개별객체(File, MenuItem)뿐 아니라
// 복합객체 자신도 같이 보관할수 있다.
// => 공통의 기반 클래스가 필요 하다.

// 개별객체와 복합객체의 사용법이 동일하다.
// => 기반 클래스에 함수(선언)를 만들어야 한다

class Item
{
	std::string name;
public:
	Item(const std::string& s) : name(s) {}

	std::string getName() const { return name; }

	// 파일과 폴더 모두 크기를 구할수 있다.
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
	std::vector<Item*> v; // <=== "Composite 패턴의 핵심 코드"
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

	// 파일은 자신만의 크기는 있습니다.
	// 폴더는 자신만의 크기는 없지만 크기를 구할수 있습니다.
	std::cout << f2->getSize() << std::endl; // 20
	std::cout << fo1->getSize() << std::endl; // 10
	std::cout << root->getSize() << std::endl; // 30
}

