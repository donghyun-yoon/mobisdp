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
// 도형편집기 예제


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

// Adapter 의 종류
// 클래스 어답터 : 클래스의 인터페이스를 변경하는 것
// 객체   어답터 : 객체의 인터페이스를 변경하는 것

// 아래 코드는 클래스 어답터 입니다.
class Text : public TextView, public Shape
{
public:
	Text(const std::string& s) : TextView(s) {}

	virtual void Draw() override { TextView::Show(); }
};

// 객체 어답터 입니다.
class Text2 : public Shape
{
	TextView* tv;	// 핵심. 포인터 또는 참조 이어야 합니다.
					// 이미 "존재하는 객체"를 가리키는 것
public:
	Text2(TextView* p) : tv(p) {}

	virtual void Draw() override { tv->Show(); }
};

int main()
{
	vector<Shape*> v;

	TextView tv("Hello"); // TextView : 클래스,
						  // tv       : 객체 입니다.

	// 이미 생성된 "TextView 타입의 객체 tv" 를 v에 넣을수 있을까요 ?
	//v.push_back(&tv); // error. Shape 로 부터 상속되지 않았다.

	// tv 라는 객체를 "기존 시스템에 연결하기 위해", "객체 어답터"를 사용하는 코드
	v.push_back( new Text2(&tv) );
}

// Decorator : 기능의 추가
// Adapter   : 인터페이스의 변경






