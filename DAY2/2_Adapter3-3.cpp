#include <stack> // �̾ȿ� �ִ� C++ ǥ�� stack ��
				 // �տ���(Adapter3-2) ���� �Ͱ� �����ϰ� �����Ǿ� �ֽ��ϴ�.
				 // ����, "stack adapter" ��� �θ��ϴ�.

int main()
{
	std::stack<int> s;  // ���������� std::deque �� ����մϴ�.
						// <deque> ��� ��� �˴ϴ�.
						// <stack> ����� ������ �˴ϴ�.

	s.push(10);
	s.push(20);

	std::stack<int, std::list<int>> s2;
						// �̷��� �Ϸ��� <list> �� ���ԵǾ�� �մϴ�.

}

