#include <iostream>
#include <string>
#include <conio.h>

// Validation 정책은 사용자가 변경할수 있어야 합니다.

class Edit
{
	std::string data;
public:

	// 핵심 : 변하지 않은 흐름 속에 있는 변해야 하는 코드 는 분리되어야 한다.
	// 변하는 코드를 "가상함수"로 분리한다.

	virtual bool validate(char c)
	{
		return true;
	}

	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch(); 

			if (c == 13) break;

//			if (isdigit(c))	 // 이렇게 하지 말고
			if (validate(c)) // 변해야 하는 부분은 "가상함수호출"로 변경
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << std::endl; 
		return data;
	}
};

// Validation 정책을 변경하려면 "파생클래스"를 만들어서 사용하면 됩니다.
class NumEdit : public Edit
{
public:
	virtual bool validate(char c) override
	{
		return isdigit(c);
	}
};

int main()
{
//	Edit e;
	NumEdit e;
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


