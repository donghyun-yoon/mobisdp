#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 아래 클래스가 이미 있었다가 가정해 봅시다.
// TextView : 문자열을 보관했다가 화면에 이쁘게 출력해 주는 클래스
class TextView
{
	string data;
	// 폰트종류, 색상, 크기, 스타일등, 화면출력에 필요한 모든것을 지원
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

// Rect, Circle 뿐 아니라 "문자열"도 관리하고 싶다.
// 기존에 있던 TextView 를 사용할수 없을까 ?
// TextView : Show() 함수 제공
// 도형편집기 시스템 : Draw()를 만들어야 한다.


// Show()를 Draw()로 이름을 변경하는 클래스를 만들자
class Text : public TextView, public Shape
{
public:
	Text(const std::string& s) : TextView(s) {}

	// 아래 코드가 결국 "Show()" 이름을 "Draw()" 로 변경하는 작업수행
	virtual void Draw() override { TextView::Show(); }
};

int main()
{
	vector<Shape*> v;

	v.push_back(new Text("hello"));
	v[0]->Draw();
}







