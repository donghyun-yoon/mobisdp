#include <iostream>
#include <list>
#include <vector>
#include <deque>

// ������ ����� �����
// => list �� �������̽�(����Լ�)�� stack �� ���������θ� ����ϰ�
// => �ܺ� ������ ������ �ʰڴٴ� �ǵ�
template<typename T> class stack
{
	std::list<T> c;  // �� Ÿ���� ��� �Դϴ�.
					 // => stack ������ list�� �����ǹǷ� Ŭ���� �����
//	std::list<T>* s; // �̷��� �����(�Ǵ� ����)
					 // �̹� ������� list �� ����ų�� �����Ƿ�
					 // ��ü �����
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