#include <iostream>
#include <vector>

// 마지막 단계.
// => 코드 정리
class NotImplemented {}; // 예외로 사용할 클래스

class Shape
{
protected:
	int color;
public:
	void setColor(int c) { color = c; }
	int  getColor() const { return color; }

protected:
	// 가상함수     : 파생 클래스가 재정의 하지 않으면 디폴트 구현 제공하겠다는의도
	// 순수 가상함수 : 반드시 만들어야 한다고 시키는 것
	// 
	// 또한, 도형(Shape)은 추상적 개념이다. 
	// 현실세계에서 실제 객체가 존재할수 없고 그릴수도 없다.
//	virtual void drawImp() {std::cout << "draw Shape" << std::endl;	}
	virtual void drawImp() = 0;

public:
	void draw()
	{
		std::cout << "mutex.lock" << std::endl;
		drawImp();
		std::cout << "mutex.unlock" << std::endl;
	}
	// clone() 도 "가상함수" 보다는 "순수 가상함수" 좋습니다.
	// 그런데, 순수 가상함수는 "반드시 구현해라" 라는 의도 입니다.
	// 구현하지 않으면 "컴파일시간에러"
	// virtual Shape* clone() const = 0;
	
	// 그런데, 아래 처럼 구현하는 경우도 있습니다.
	// 1. 재정의 안했는데, 사용하지 않으면 에러 아님
	// 2. 재정의 안했는데, 사용하면 예외 발생(실행시간 발생)
	// 3. 사용하려면 "재정의 하라" 라는 의미를 담은 코드
	virtual Shape* clone() const
	{
		throw NotImplemented();
		return nullptr;
	}

	// Shape 는 기반 클래스로 사용됩니다.
	// 소멸자는 반드시 가상함수 이어야 합니다
	virtual ~Shape() {}

};

class Rect : public Shape
{
public:
	// 1. 가상함수 재정의시 꼭 "override" 붙이세요
	// 2. 가상함수 재정의시 예전에는 virtual 붙이라고 했는데,,
	//    현재는 override 있으므로 "virtual" 은 빼도 나쁘지는 않습니다.

	virtual void drawImp() override { std::cout << "draw Rect" << std::endl; }

	// 3. 가상함수 재정의시 반환 타입을 변경 가능합니다.
	//   => 단, 상속 관계의 타입으로만 가능. 
	virtual Rect* clone() const override
	{
		Rect* p1 = new Rect(*this);
		return p1;
	}
};

class Circle : public Shape
{
public:
	virtual void drawImp() override { std::cout << "draw Circle" << std::endl; }

	virtual Circle* clone() const override
	{
		Circle* p1 = new Circle(*this);
		return p1;
	}
};

class Triangle : public Shape
{
public:
	void draw() { std::cout << "draw Triangle" << std::endl; }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			v.push_back(new Rect);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw();
		}
		else if (cmd == 8)
		{
			std::cout << "몇번째 도형을 복사 할까요 >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->clone());
		}
		else if (cmd == -1) break;
	}
	for (auto p : v)
		delete p;
}

