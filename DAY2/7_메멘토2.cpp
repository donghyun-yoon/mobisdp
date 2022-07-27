// 8_메멘토 - 178
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Graphics
{
	// 저장해야 하는 멤버 데이타만 모아서 별도의 구조체로..
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

	int token = g.Save(); // 현재 객체의 상태를 저장했다가.. 나중에 복구 할수 있게 하자.
						  // "Memento(기억)"의 패턴
						  // 객체의 상태를 저장했다가 복구할수 있게 하는 패턴.

	g.SetStrokeColor(1);
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);

	// 처음에 그렸던 선과 동일하게 그리고 싶다.
	g.Restore(token); // token 을 가지고 상태를 복구
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);
}









