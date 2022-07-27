#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

struct Stream
{
	virtual void Write(const std::string&) = 0;
	virtual ~Stream() {}
};

class FileStream : public Stream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void Write(const std::string& s)
	{
		printf("%s ����\n", s.c_str());
	}
};

int main()
{
	// ������ ���� ��ȣȭ �ؼ� ���� ����� �ʿ� �մϴ�.
	// ��� 1. ��ȣȭ�� �����ϰ� ���Ͽ� ����. 


	FileStream fs("a.txt");
	fs.Write("Hello");

}