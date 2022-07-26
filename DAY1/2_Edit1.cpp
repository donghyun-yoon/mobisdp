#include <iostream>
#include <string>
#include <conio.h>

// 28 page 
// Edit 에 입력값을 validation 하는 기능을 추가해 봅시다.

class Edit
{
	std::string data;
public:
	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch(); // 한자만 입력
			
			if (c == 13) break; // enter 키 입력

			if (isdigit(c))   // 입력값에 대한 유효성 검증
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


