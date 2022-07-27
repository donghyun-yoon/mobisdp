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
	//	=> �׷���, �̷� �۾��� ���� �Ѵٸ� ??!!

	// ��� 2. FileStream �ȿ� EncrpytWrite() �Լ� �߰�
	//  => NetworkStream �� �ٸ� Stream Ŭ������ �ʿ� �ϴ�.
	//  => �䱸 ������ ���������� ���� Ŭ������ �����ϴ°��� ���� �ʴ�.
	//     OCP ����

	// ���3. ���� Ŭ������ �������� ����� �߰��Ҽ� �־�� �Ѵ�.
	//       Decorator ���� ���

	FileStream fs("a.txt");
	fs.Write("Hello");

	EncryptDecorator ed(&fs); // fs�Ӿƴ϶� ������, ��Ʈ��ũ ��Ʈ��������
	ed.Write("Hello");	// 1. ����Ÿ�� ��ȣȭ �ϰ�  <= �߰� ���
						// 2. fs.Write() �� ����  <= ���� ���

	ZipDecorator zd(&ed);
	zd.Write("Hello");  // 1. ����Ÿ�� �����ϰ�
					    // 2. ed.Write()�� ����

}