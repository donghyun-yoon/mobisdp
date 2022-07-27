#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL 과 Adapter

// std::list 의 멤버 함수이름을 변경해서 stack 처럼 보이게 해봅시다.
// 상속을 사용한 클래스 어답터
// => stack 이 list 의 모든 인터페이스를 물려 받겠다는 것
// => list 의 모든 함수를 stack 도 노출하겠다...
// => 이 예제의 경우는 좋지 않다.
// => Text 와 TextView 예제(Adapter1) 은 상속이 좋다.

template<typename T> class stack : public std::list<T>
{
public:
	// list 의 멤버 함수 이름을 stack 처럼 보이도록 변경
	void push(const T& a) { std::list<T>::push_back(a); }
	void pop()			  { std::list<T>::pop_back(); }
	T&   top()            { return std::list<T>::back();}
};


int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);

//	s.push_front(30); // 스택이 망가졌다!!!!
}