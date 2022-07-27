#define USING_GUI
#include "cppmaster.h"

// ������ ����ϴ� Ŭ���� ���� - Proxy ����
// �����ڸ� ����� ����
// ����
// 1. Client �����ڴ� IPC ���� �ڵ带 �� �ʿ� ����.
// 2. ���� ���Ǵ� ��û�� ���� Cache ���� ����� �߰��Ҽ��� �ִ�.
// 3. ���� ���� ��ɵ� �߰��Ҽ��� �ִ�.

// 4. Proxy : "�Լ� ȣ��" �� "��� �ڵ�" �� �����ϴ� ����
//    Stub  : "��� �ڵ�" �� "�Լ� ȣ��" �� �����ϴ� ������ �ִ� �ڵ�

// ������ ����ϴ� ������(proxy)
// proxy�� ������
// => proxy �� ���� �پ��� �߰� ����� �����Ҽ� �ִ�.
// => ���� ���Ǵ� ��û�� ���� "cache" �� ���� �������
// => id/passwd üũ�� ���ؼ� ���� ��ɰ�ȭ ���� �Ҽ� �ִ�.
// ��, �پ��� ������ ����� ���� ����� ����. 
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
	// ������ �����Ϸ��� 
	// ������ ����ϴ� "Calc Ŭ����"��ü�� ����ϸ� �ȴ�.
	Calc* pCalc = new Calc;

	std::cout << pCalc->Add(1, 2) << std::endl;
	std::cout << pCalc->Sub(1, 2) << std::endl;

	delete pCalc;
}





