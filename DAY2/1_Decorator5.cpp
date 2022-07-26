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
		printf("%s 쓰기\n", s.c_str() );
	}
};

int main()
{
	// 객체지향(C++)은 생성자/소멸자로 자원 관리하므로 편리합니다.
	FileStream fs("a.txt");
	fs.Write("Hello");

	if (실패)
		return 0; // 이순간 fs 의 소멸자가 fclose 수행하게 됩니다.


	// C 언어는 개발자가 직접 자원을 관리해야 하므로 불편합니다.
	/*
	FILE* f = fopen("a.txt", "wt");
	if (실패)
	{
		fclose(f);
		return 0;
	}
	fclose(f);
	*/
}