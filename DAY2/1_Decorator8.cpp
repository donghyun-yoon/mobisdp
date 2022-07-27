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
//================
// 스트림에 기능을 추가하는 클래스들(Decorator.. 포장지)
// 포장지는 포장된 객체도 포장한다.( 동일 기반 클래스, Stream 이 필요)
class EncryptDecorator : public Stream  
{
	Stream* stream;
public:
	EncryptDecorator(Stream* s) : stream(s) {}

	void Write(const std::string& s)
	{
		std::string s2 = s + " 암호화"; // 전달된 데이타를 암호화 하고

		stream->Write(s2);      // 암호화 된 데이타를 원래 stream 객체에 전달
								// 파일스트림 뿐 아니라 다양한 stream 에 전달
	}
};


class ZipDecorator : public Stream
{
	Stream* stream;
public:
	ZipDecorator(Stream* s) : stream(s) {}

	void Write(const std::string& s)
	{
		std::string s2 = s + " 압축"; 

		stream->Write(s2);      
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.Write("Hello");

	EncryptDecorator ed(&fs); 
	ed.Write("Hello");	

	ZipDecorator zd(&ed);
	zd.Write("Hello");  

}
// C# 언어가 아래 처럼 되어 있습니다.
// 저장소      Stream 클래스      Stream 꾸미기(Decorator)
// 파일   <-   FileStream        EncryptDecorator
// 파이프 <-   PipeStream        ZipDecorator 
// N/W   <-   NetworkStream     XmlDecorator
//								JsonDecorator

// Folder 는 File 뿐 아니라 Folder 자체도 포함할수 있습니다.
// => FOlder, File의 공통의 기반 클래스 필요
// 
// Decrator 는 객체 뿐아니라 Decorator 를 다시 꾸밀수 있습니다.
// => 객체(우주선)과 Decorator는 동일 기반 클래스 필요

// 재귀적 포함을 사용한 디자인 패턴
// Composite : 재귀적 포함으로 "복합객체"를 만드는 패턴
// Decorator : 재귀적 포함으로 "객체에 동적인 기능추가"
//				여러개의 기능추가가 가능