#include <iostream>
#include <string>
#include <conio.h>

// 28 page 
// Edit �� �Է°��� validation �ϴ� ����� �߰��� ���ô�.

class Edit
{
	std::string data;
public:
	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch(); // ���ڸ� �Է�
			
			if (c == 13) break; // enter Ű �Է�

			if (isdigit(c))   // �Է°��� ���� ��ȿ�� ����
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << std::endl; // ����
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


