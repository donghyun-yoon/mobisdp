#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

// 모든 Stream 은 사용법이 동일한 것이 좋습니다.
// Stream 이 지켜야 하는 규칙(함수이름)을 인터페이스로 설계
struct Stream
{
	virtual void Write(const std::string&) = 0;
	virtual ~Stream() {}

	// 그외에 Read() 등 다양한 입출력 함수의 이름을 약속
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
		printf("%s 쓰기\n", s.c_str());
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.Write("Hello");

	// 파일이 아닌 파이프, 네트워크 등에 쓰는 클래스도 있다고 가정해 봅시다.
	PipeStream ps("namedpipe");
	ps.Write("Hello");

	NetworkStream ns("200.100.100.100", 3000);
	ns.Write("Hello");

}