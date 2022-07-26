#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

class FileStream
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
		printf("%s ����\n", s.c_str() );
	}
};

int main()
{
	// ��ü����(C++)�� ������/�Ҹ��ڷ� �ڿ� �����ϹǷ� ���մϴ�.
	FileStream fs("a.txt");
	fs.Write("Hello");

	if (����)
		return 0; // �̼��� fs �� �Ҹ��ڰ� fclose �����ϰ� �˴ϴ�.


	// C ���� �����ڰ� ���� �ڿ��� �����ؾ� �ϹǷ� �����մϴ�.
	/*
	FILE* f = fopen("a.txt", "wt");
	if (����)
	{
		fclose(f);
		return 0;
	}
	fclose(f);
	*/
}