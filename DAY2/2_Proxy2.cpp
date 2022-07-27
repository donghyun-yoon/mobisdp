#define USING_GUI
#include "cppmaster.h"

// 서버를 대신하는 클래스 도입 - Proxy 패턴
// 대행자를 만드는 패턴
// 장점
// 1. Client 제작자는 IPC 관련 코드를 알 필요 없다.
// 2. 자주 사용되는 요청에 대한 Cache 등의 기능을 추가할수도 있다.
// 3. 보안 관련 기능도 추가할수도 있다.

// 4. Proxy : "함수 호출" 을 "명령 코드" 로 변경하는 도구
//    Stub  : "명령 코드" 를 "함수 호출" 로 변경하는 서버에 있는 코드

// 서버를 대신하는 대행자(proxy)
// proxy가 있으면
// => proxy 를 통해 다양한 추가 기능을 수행할수 있다.
// => 자주 사용되는 요청에 대해 "cache" 를 만들어서 성능향상
// => id/passwd 체크를 통해서 보안 기능강화 등을 할수 있다.
// 즉, 다양한 이유로 대신할 것을 만드는 패턴. 
class Calc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b);}
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

int main()
{
	// 서버에 접속하려면 
	// 서버를 대신하는 "Calc 클래스"객체를 사용하면 된다.
	Calc* pCalc = new Calc;

	std::cout << pCalc->Add(1, 2) << std::endl;
	std::cout << pCalc->Sub(1, 2) << std::endl;

	delete pCalc;
}





