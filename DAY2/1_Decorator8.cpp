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
//================
// ��Ʈ���� ����� �߰��ϴ� Ŭ������(Decorator.. ������)
// �������� ����� ��ü�� �����Ѵ�.( ���� ��� Ŭ����, Stream �� �ʿ�)
class EncryptDecorator : public Stream  
{
	Stream* stream;
public:
	EncryptDecorator(Stream* s) : stream(s) {}

	void Write(const std::string& s)
	{
		std::string s2 = s + " ��ȣȭ"; // ���޵� ����Ÿ�� ��ȣȭ �ϰ�

		stream->Write(s2);      // ��ȣȭ �� ����Ÿ�� ���� stream ��ü�� ����
								// ���Ͻ�Ʈ�� �� �ƴ϶� �پ��� stream �� ����
	}
};


class ZipDecorator : public Stream
{
	Stream* stream;
public:
	ZipDecorator(Stream* s) : stream(s) {}

	void Write(const std::string& s)
	{
		std::string s2 = s + " ����"; 

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
// C# �� �Ʒ� ó�� �Ǿ� �ֽ��ϴ�.
// �����      Stream Ŭ����      Stream �ٹ̱�(Decorator)
// ����   <-   FileStream        EncryptDecorator
// ������ <-   PipeStream        ZipDecorator 
// N/W   <-   NetworkStream     XmlDecorator
//								JsonDecorator

// Folder �� File �� �ƴ϶� Folder ��ü�� �����Ҽ� �ֽ��ϴ�.
// => FOlder, File�� ������ ��� Ŭ���� �ʿ�
// 
// Decrator �� ��ü �Ӿƴ϶� Decorator �� �ٽ� �ٹм� �ֽ��ϴ�.
// => ��ü(���ּ�)�� Decorator�� ���� ��� Ŭ���� �ʿ�

// ����� ������ ����� ������ ����
// Composite : ����� �������� "���հ�ü"�� ����� ����
// Decorator : ����� �������� "��ü�� ������ ����߰�"
//				�������� ����߰��� ����