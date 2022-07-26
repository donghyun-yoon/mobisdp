#include <iostream>
#include <string>
#include <conio.h>

// Validation ��å�� ����ڰ� �����Ҽ� �־�� �մϴ�.

class Edit
{
	std::string data;
public:

	// �ٽ� : ������ ���� �帧 �ӿ� �ִ� ���ؾ� �ϴ� �ڵ� �� �и��Ǿ�� �Ѵ�.
	// ���ϴ� �ڵ带 "�����Լ�"�� �и��Ѵ�.

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

//			if (isdigit(c))	 // �̷��� ���� ����
			if (validate(c)) // ���ؾ� �ϴ� �κ��� "�����Լ�ȣ��"�� ����
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << std::endl; 
		return data;
	}
};

// Validation ��å�� �����Ϸ��� "�Ļ�Ŭ����"�� ���� ����ϸ� �˴ϴ�.
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


