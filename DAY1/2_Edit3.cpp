#include <iostream>
#include <string>
#include <conio.h>

// 클래스에서 변하는 것을 분리하는 2가지 기술
// 1. 변하는 것을 가상함수로 분리
// 2. 변하는 것을 다른 클래스로 분리 => 교체 가능해야 한다. 
//								   인터페이스 기반 설계

struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool iscomplete(const std::string& s) { return true; }
	virtual ~IValidator() {}
};
// 주민 등록 번호 : 901  1     확인

class Edit
{
	std::string data;
	
	IValidator* pval = nullptr;	// 입력값의 유효성을 확인할 객체
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

			if (pval == nullptr || pval->validate(data, c)) // 입력값의 유효성 여부를
			{											// 다른 객체에 위임.
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << std::endl; 
		return data;
	}
};
// 이제 다양한 정책을 가진 Validator를 만들어서 제공하면 됩니다.
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
	LimitDigitValidator v(5); // 입력 값의 유효성을 확인하는 객체
	e.setValidator(&v);
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


