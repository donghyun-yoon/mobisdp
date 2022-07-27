#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TextView
{
	string data;
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

// Adapter �� ����
// Ŭ���� ����� : Ŭ������ �������̽��� �����ϴ� ��
// ��ü   ����� : ��ü�� �������̽��� �����ϴ� ��

// �Ʒ� �ڵ�� Ŭ���� ����� �Դϴ�.
class Text : public TextView, public Shape
{
public:
	Text(const std::string& s) : TextView(s) {}

	virtual void Draw() override { TextView::Show(); }
};

// ��ü ����� �Դϴ�.
class Text2 : public Shape
{
	TextView* tv;	// �ٽ�. ������ �Ǵ� ���� �̾�� �մϴ�.
					// �̹� "�����ϴ� ��ü"�� ����Ű�� ��
public:
	Text2(TextView* p) : tv(p) {}

	virtual void Draw() override { tv->Show(); }
};

int main()
{
	vector<Shape*> v;

	TextView tv("Hello"); // TextView : Ŭ����,
						  // tv       : ��ü �Դϴ�.

	// �̹� ������ "TextView Ÿ���� ��ü tv" �� v�� ������ ������� ?
	//v.push_back(&tv); // error. Shape �� ���� ��ӵ��� �ʾҴ�.

	// tv ��� ��ü�� "���� �ý��ۿ� �����ϱ� ����", "��ü �����"�� ����ϴ� �ڵ�
	v.push_back( new Text2(&tv) );
}

// Decorator : ����� �߰�
// Adapter   : �������̽��� ����






