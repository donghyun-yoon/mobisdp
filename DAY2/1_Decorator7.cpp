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
		printf("%s 쓰기\n", s.c_str());
	}
};

int main()
{
	// 파일을 쓸때 암호화 해서 쓰는 기능이 필요 합니다.
	// 방법 1. 암호화를 먼저하고 파일에 쓰자. 
	//	=> 그런데, 이런 작업을 자주 한다면 ??!!

	// 방법 2. FileStream 안에 EncrpytWrite() 함수 추가
	//  => NetworkStream 등 다른 Stream 클래스도 필요 하다.
	//  => 요구 사항이 있을때마다 기존 클래스를 변경하는것은 좋지 않다.
	//     OCP 위반

	// 방법3. 기존 클래스의 수정없이 기능을 추가할수 있어야 한다.
	//       Decorator 패턴 사용

	FileStream fs("a.txt");
	fs.Write("Hello");

	EncryptDecorator ed(&fs); // fs뿐아니라 파이프, 네트워크 스트림도가능
	ed.Write("Hello");	// 1. 데이타를 암호화 하고  <= 추가 기능
						// 2. fs.Write() 로 쓰기  <= 원래 기능

	ZipDecorator zd(&ed);
	zd.Write("Hello");  // 1. 데이타를 압축하고
					    // 2. ed.Write()로 전달

}