// 8_�޸��� - 178
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Graphics
{
	// �����ؾ� �ϴ� ��� ����Ÿ�� ��Ƽ� ������ ����ü��..
	struct Memento
	{
		int color;
		int width;
	};
	
	static int key;
	static std::map<int, Memento*> history;

	int penWidth = 1;
	int penColor = 0;
	int temporary_data;

public:
	int Save()
	{
		++key;

		Memento* p = new Memento;
		p->color = penColor;
		p->width = penWidth;

		history[key] = p;
		return key;
	}

	void Restore(int key)
	{
		Memento* p = history[key];
		penColor = p->color;
		penWidth = p->width;
	}
	void DrawLine(int x1, int y1, int x2, int y2)
	{
	}
	void SetStrokeColor(int c) { penColor = c; }
	void SetStrokeWidth(int w) { penWidth = w; }
};
int Graphics::key = 0;
std::map<int, Graphics::Memento*> Graphics::history;

int main()
{
	Graphics g;

	g.SetStrokeColor(0);
	g.SetStrokeWidth(10);
	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 200, 200); 

	int token = g.Save(); // ���� ��ü�� ���¸� �����ߴٰ�.. ���߿� ���� �Ҽ� �ְ� ����.
						  // "Memento(���)"�� ����
						  // ��ü�� ���¸� �����ߴٰ� �����Ҽ� �ְ� �ϴ� ����.

	g.SetStrokeColor(1);
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);

	// ó���� �׷ȴ� ���� �����ϰ� �׸��� �ʹ�.
	g.Restore(token); // token �� ������ ���¸� ����
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);
}









