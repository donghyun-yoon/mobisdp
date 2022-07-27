#include <iostream>
#include <list>
#include <vector>
#include <deque>

template<typename T, typename C = std::deque<T> > class stack
{
	C c;  
public:
	void push(const T& a) { c.push_back(a); }
	void pop() { c.pop_back(); }
	T& top() { return c.back(); }
};

int main()
{
	stack<int, std::list<int>>   s;	// list �� stack ó�� ����Ҽ�
									// �ְ� �ش޶�. 
	stack<int, std::vector<int>> s2;

	stack<int> s3; // std::deque ���
	s.push(10);
	s.push(20);


}