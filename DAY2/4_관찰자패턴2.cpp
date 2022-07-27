//1_관찰자패턴1 - 94 page
#include <iostream>
#include <vector>
using namespace std;


struct IGraph
{
	virtual void Update(int data) = 0;
	virtual ~IGraph() {}
};

// 관리하는 데이타에 상관없이 관찰자 패턴의 로직은 변하지 않는다.
// 관찰자 패턴의 기본 로직을 제공하는 기반 클래스를 설계 하자!
// GoF's 책에서는 관찰의 대상을 "Subject" 라고 합니다.
// 변하지 않은 것은 : "기반 클래스에"
// 변해야 하는 것은 : "가상함수로 만들어서 파생클래스가 재정의 할수 있게"

class Subject
{
	vector<IGraph*> v;
public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}
	void notify(int data)
	{
		for (auto p : v)
			p->Update(data);
	}
};

class Table : public Subject
{
	int value;
public:
	void edit()
	{
		while (1)
		{
			cout << "Data >>";
			cin >> value;

			notify(value); 
		}
	}
};
//----------------------
class BarGraph : public IGraph
{
public:
	void Update(int n) override
	{
		cout << "Bar Graph : ";

		for (int i = 0; i < n; i++)
			cout << "*";

		cout << endl;
	}
};

class PieGraph : public IGraph
{
public:
	void Update(int n) override
	{
		cout << "Pie Graph : ";

		for (int i = 0; i < n; i++)
			cout << ")";

		cout << endl;
	}
};

int main()
{
	Table t;
	BarGraph bg; t.attach(&bg);
	PieGraph pg; t.attach(&pg);
	t.edit();
}





