#include <iostream>

// Chain of responsibility(책임의전가)

struct Handler
{
	Handler* next = nullptr;

	void Handle(int problem)
	{
		// 자신이 먼저 처리를 시도 한다.
		if (HandleRequest(problem) == true)
			return;

		if (next != 0)
			next->Handle(problem);
	}

	// 문제를 처리하는 함수
	virtual bool HandleRequest(int problem) = 0;
};

//--------------
class TenHandler : public Handler
{
public:
	virtual bool HandleRequest(int problem)
	{
		std::cout << "TenHandler Start" << std::endl;

		if (problem == 10)
		{
			std::cout << "TenHandler 가 처리 완료" << std::endl;
			return true;
		}
		return false;
	}
};
class OddHandler : public Handler
{
public:
	virtual bool HandleRequest(int problem)
	{
		std::cout << "OddHandler Start" << std::endl;

		if (problem % 2 == 1)
		{
			std::cout << "OddHandler 가 처리 완료" << std::endl;
			return true;
		}
		return false;
	}
};
int main()
{
	TenHandler h1; // 문제번호 10번 처리
	OddHandler h2; // 홀수만 치리
	h1.next = &h2; // h1 -> h2 

	// 문제가 발생하면 1번째 팀에게 전달
//	h1.Handle(10); // h1이 처리
//	h1.Handle(11); // h1 -> h2 보내서 처리
	h1.Handle(12); // h1 -> h2 -> 처리 안됨.
}
// 위 패턴이 "Chain Of Responsibility" 입니다.
// 주로 GUI 에서 터치 이벤트 처리할때 많이 사용
// 자식윈도우터치시
// 자식윈도우 핸들러 -> 부모 윈도우 핸들러



