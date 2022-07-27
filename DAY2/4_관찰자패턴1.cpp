//1_����������1 - 94 page
#include <iostream>
#include <vector>
using namespace std;


// ��� �׷��� ��ü�� ���Ѿ��ϴ� ��Ģ(�������̽�)

struct IGraph
{
	virtual void Update(int data) = 0;
	virtual ~IGraph() {}
};

class Table
{
	vector<IGraph*> v; // �������� ������(�׷���)����

	int value; // table �� data ��
public:
	void attach(IGraph* p) { v.push_back(p); }
	void detach(IGraph* p) {}
	void notify(int data)
	{
		// ��ϵ� ��� �׷����� �˷��ش�.
		for (auto p : v)
			p->Update(data);
	}
	void edit()
	{
		while (1)
		{
			cout << "Data >>";
			cin >> value;

			notify(value); // ���°� ����Ǿ����Ƿ� ��� �׷���(������)���� �뺸�Ѵ�.
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
	// table �� ������(Graph)���� �����ϰ�
	BarGraph bg; t.attach(&bg);
	PieGraph pg; t.attach(&pg);
	PieGraph pg2; t.attach(&pg2);

	// table ���� ���� ����
	t.edit();
}

// �ٽ� : ��ü�� 1 : N �� ����� �������� ( table 1, Graph N)
//		  ��ü�� ���� ��ȭ�� ��ϵ� ������ü�� �����Ѵ�.




