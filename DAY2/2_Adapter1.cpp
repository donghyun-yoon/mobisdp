#include <iostream>
#include <string>
#include <vector>
using namespace std;

// �Ʒ� Ŭ������ �̹� �־��ٰ� ������ ���ô�.
// TextView : ���ڿ��� �����ߴٰ� ȭ�鿡 �̻ڰ� ����� �ִ� Ŭ����
class TextView
{
	string data;
	// ��Ʈ����, ����, ũ��, ��Ÿ�ϵ�, ȭ����¿� �ʿ��� ������ ����
public:
	TextView(string s) : data(s) {}

	void Show() { cout << data << endl; }
};
//=============================================
// ���������� ����


class Shape
{
public:
	virtual void Draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void Draw() override { cout << "Draw Rect" << endl; }
};
class Circle : public Shape
{
public:
	void Draw() override { cout << "Draw Circle" << endl; }
};

// Rect, Circle �� �ƴ϶� "���ڿ�"�� �����ϰ� �ʹ�.
// ������ �ִ� TextView �� ����Ҽ� ������ ?
// TextView : Show() �Լ� ����
// ���������� �ý��� : Draw()�� ������ �Ѵ�.


// Show()�� Draw()�� �̸��� �����ϴ� Ŭ������ ������
class Text : public TextView, public Shape
{
public:
	Text(const std::string& s) : TextView(s) {}

	// �Ʒ� �ڵ尡 �ᱹ "Show()" �̸��� "Draw()" �� �����ϴ� �۾�����
	virtual void Draw() override { TextView::Show(); }
};

int main()
{
	vector<Shape*> v;

	v.push_back(new Text("hello"));
	v[0]->Draw();
}







