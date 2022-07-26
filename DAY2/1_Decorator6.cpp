#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

// ��� Stream �� ������ ������ ���� �����ϴ�.
// Stream �� ���Ѿ� �ϴ� ��Ģ(�Լ��̸�)�� �������̽��� ����
struct Stream
{
	virtual void Write(const std::string&) = 0;
	virtual ~Stream() {}

	// �׿ܿ� Read() �� �پ��� ����� �Լ��� �̸��� ���
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
	FileStream fs("a.txt");
	fs.Write("Hello");

	// ������ �ƴ� ������, ��Ʈ��ũ � ���� Ŭ������ �ִٰ� ������ ���ô�.
	PipeStream ps("namedpipe");
	ps.Write("Hello");

	NetworkStream ns("200.100.100.100", 3000);
	ns.Write("Hello");

}