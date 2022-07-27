#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 포함을 사용한 어답터
// => list 의 인터페이스(멤버함수)를 stack 이 내부적으로만 사용하고
// => 외부 노출을 하지는 않겠다는 의도
template<typename T> class stack
{
	std::list<T> c;  // 값 타입의 멤버 입니다.
					 // => stack 생성시 list도 생성되므로 클래스 어답터
//	std::list<T>* s; // 이렇게 만들면(또는 참조)
					 // 이미 만들어진 list 를 가리킬수 있으므로
					 // 객체 어답터
public:
	void push(const T& a)	{ c.push_back(a); }
	void pop()				{ c.pop_back(); }
	T& top()				{ return c.back(); }
};

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);

	
}