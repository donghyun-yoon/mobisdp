#include <iostream>
#include <string>
#include <conio.h>

// Ŭ�������� ���ϴ� ���� �и��ϴ� 2���� ���
// 1. ���ϴ� ���� �����Լ��� �и�
// 2. ���ϴ� ���� �ٸ� Ŭ������ �и� => ��ü �����ؾ� �Ѵ�. 
//								   �������̽� ��� ����

struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool iscomplete(const std::string& s) { return true; }
	virtual ~IValidator() {}
};
// �ֹ� ��� ��ȣ : 901  1     Ȯ��

class Edit
{
	std::string data;
	
	IValidator* pval = nullptr;	// �Է°��� ��ȿ���� Ȯ���� ��ü
public:
	void setValidator(IValidator* p) { pval = p; }

	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch(); 

			if (c == 13 && (pval == nullptr || pval->iscomplete(data))) 
				break;

			if (pval == nullptr || pval->validate(data, c)) // �Է°��� ��ȿ�� ���θ�
			{											// �ٸ� ��ü�� ����.
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << std::endl; 
		return data;
	}
};
// ���� �پ��� ��å�� ���� Validator�� ���� �����ϸ� �˴ϴ�.
class LimitDigitValidator : public IValidator
{
	int value;
public:
	LimitDigitValidator(int n) : value(n) {}

	virtual bool validate(const std::string& s, char c) override
	{
		return s.size() < value && isdigit(c);
	}
};

int main()
{
	Edit e;
	LimitDigitValidator v(5); // �Է� ���� ��ȿ���� Ȯ���ϴ� ��ü
	e.setValidator(&v);
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


