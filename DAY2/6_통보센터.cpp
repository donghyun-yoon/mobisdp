#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
using namespace std::placeholders;

// 중재자(Mediator) 패턴
// 객체간의 상호 관계가 복잡하면 중재자를 도입해라
// 객체간의 M:N 의 관계를 중재자와 객체의 1:N 의 관계로 변경하는 패턴
// => 객체간에는 서로의 존재를 알필요 없다.
// => 중재자만 알면 되고, 
// => 중재자가 모든 객체를 알면 된다.









class NotificationCenter
{
	using HANDLER = void(*)(void*);

	std::map<std::string, std::vector<HANDLER> > notif_map;
public:
	void addObserver(const std::string& key, HANDLER f)
	{
		notif_map[key].push_back(f);
	}

	void postNotificationWithName(const std::string& key, void* hint)
	{
		for (auto f : notif_map[key]) // notif_map[key] : vector입니다.
			f(hint);
	}
};

void foo(void* p) { std::cout << "foo : " << (int)p << std::endl; }
void goo(void* p) { std::cout << "goo : " << (int)p << std::endl; }
//void goo(void* p, int a) { std::cout << "goo : " << (int)p << std::endl; }


int main()
{
	NotificationCenter nc;

	nc.addObserver("LOWBATTERY", &foo);
	nc.addObserver("LOWBATTERY", &goo);

	// 배터리 모듈쪽에서 배터리가 부족해지면
	nc.postNotificationWithName("LOWBATTERY", (void*)30);
}




