// 7_�̱���1 - 123 page
#include <iostream>

// �̱��� : ���� �Ѱ��� ��ü�� �����ϴ� ��.

class Cursor
{
	// ��Ģ 1. �����ڸ� private ���Ƽ�, �ܺο��� ��ü�����Ҽ� ���� �Ѵ�.
private:
	Cursor() {}

	// ��Ģ 2. �����Ϸ����� ���� �����ڿ� ���Կ����ڸ� ������ ���ϰ�
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;


	// ��Ģ 3. ���� �Ѱ��� ��ü�� ����� static ��� �Լ� ����
public:
	static Cursor& getInstance()
	{
		static Cursor instance;
		return instance;
	}
};
int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

//	Cursor c3 = c1; // �̷��� ��������� �͵� ���ƾ� �մϴ�.

//	Cursor c1, c2;
}








