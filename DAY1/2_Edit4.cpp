#include <iostream>
#include <string>
#include <conio.h>


class Edit
{
	std::string data;

	// validation 정책을 "함수 포인터"로 교체 하면 어떤가요 ?
	using HANDLER = bool(*)(const std::string&);

	HANDLER validate = nullptr;

public:
	void setValidator(HANDLER f) { validate = f; }

	// 가능합니다. 그런데, 이 경우 iscomplete 까지 생각하면 복잡해 집니다.
	// 인터페이스 기반 교체 : 여러개 함수를 한번에 교체!!



	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch(); 

			if (c == 13) break;

			if (isdigit(c))   
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << std::endl; // 개행
		return data;
	}
};

int main()
{
	Edit e;
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


