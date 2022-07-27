#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
using namespace std::placeholders;

// ������(Mediator) ����
// ��ü���� ��ȣ ���谡 �����ϸ� �����ڸ� �����ض�
// ��ü���� M:N �� ���踦 �����ڿ� ��ü�� 1:N �� ����� �����ϴ� ����
// => ��ü������ ������ ���縦 ���ʿ� ����.
// => �����ڸ� �˸� �ǰ�, 
// => �����ڰ� ��� ��ü�� �˸� �ȴ�.









class NotificationCenter
{
//	using HANDLER = void(*)(void*); // �̷��� �ϸ� ��¥ �Լ��� �˴ϴ�.
									// ����ǥ���ĵ�, ���ڰ� �������� �Լ�����
									// ��� ��ƽ��ϴ�.
	using HANDLER = std::function<void(void*)>; // �̰� �����ϴ�.
									// �Լ������͸� ���� ���� ��Ų Ÿ��

	std::map<std::string, std::vector<HANDLER> > notif_map;
public:
	void addObserver(const std::string& key, HANDLER f)
	{
		notif_map[key].push_back(f);
	}

	void postNotificationWithName(const std::string& key, void* hint)
	{
		for (auto f : notif_map[key]) // notif_map[key] : vector�Դϴ�.
			f(hint);
	}
};
void foo(void* p) { std::cout << "foo : " << (int)p << std::endl; }
void goo(void* p) { std::cout << "goo : " << (int)p << std::endl; }
//void goo(void* p, int a) { std::cout << "goo : " << (int)p << std::endl; }

int main()
{
	NotificationCenter nc; // ������.

	nc.addObserver("LOWBATTERY", &foo);
	nc.addObserver("LOWBATTERY", &goo);
	nc.addObserver("DISCONNECT_WIFI", &goo);
	nc.addObserver("DISCONNECT_WIFI", 
		[](void* p) { std::cout << "lambda" << std::endl; } );

	// ���͸� ����ʿ��� ���͸��� ����������
	nc.postNotificationWithName("LOWBATTERY", (void*)30);
	nc.postNotificationWithName("DISCONNECT_WIFI", (void*)0);
	nc.postNotificationWithName("FILE_DELETE", (void*)0);
}




