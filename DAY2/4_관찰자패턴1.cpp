//1_관찰자패턴1 - 94 page
#include <iostream>
#include <vector>
using namespace std;


// 모든 그래프 객체가 지켜야하는 규칙(인터페이스)

struct IGraph
{
	virtual void Update(int data) = 0;
	virtual ~IGraph() {}
};

class Table
{
	vector<IGraph*> v; // 여러개의 관찰자(그래프)보관

	int value; // table 의 data 값
public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}
	void notify(int data)
	{
		// 등록된 모든 그래프에 알려준다.
		for (auto p : v)
			p->Update(data);
	}
	void edit()
	{
		while (1)
		{
			cout << "Data >>";
			cin >> value;

			notify(value); // 상태가 변경되었으므로 모든 그래프(관찰자)에게 통보한다.
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
	// table 에 관찰자(Graph)들을 부착하고
	BarGraph bg; t.attach(&bg);
	PieGraph pg; t.attach(&pg);
	PieGraph pg2; t.attach(&pg2);

	// table 편집 모드로 진입
	t.edit();
}

// 핵심 : 객체를 1 : N 의 관계로 설정한후 ( table 1, Graph N)
//		  객체의 상태 변화를 등록된 여러객체에 전달한다.




