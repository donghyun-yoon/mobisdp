#include <stack> // 이안에 있는 C++ 표준 stack 이
				 // 앞에서(Adapter3-2) 만든 것과 유사하게 구현되어 있습니다.
				 // 흔히, "stack adapter" 라로 부릅니다.

int main()
{
	std::stack<int> s;  // 내부적으로 std::deque 를 사용합니다.
						// <deque> 헤더 없어도 됩니다.
						// <stack> 헤더만 있으면 됩니다.

	s.push(10);
	s.push(20);

	std::stack<int, std::list<int>> s2;
						// 이렇게 하려면 <list> 가 포함되어야 합니다.

}

