#include <iostream>
#include <string>
#include <conio.h>


class Edit
{
	std::string data;

	// validation ��å�� "�Լ� ������"�� ��ü �ϸ� ����� ?
	using HANDLER = bool(*)(const std::string&);

	HANDLER validate = nullptr;

public:
	void setValidator(HANDLER f) { validate = f; }

	// �����մϴ�. �׷���, �� ��� iscomplete ���� �����ϸ� ������ ���ϴ�.
	// �������̽� ��� ��ü : ������ �Լ��� �ѹ��� ��ü!!



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


