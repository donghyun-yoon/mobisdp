// 6_Bridge1 - 90 page
#include <iostream>
using namespace std;

// �긴�� ������ �ٽ�

// ����(IMP3, IPod)�� �߻�(MP3) �� �и��ؼ�
// ��ȣ �������� update �� �����ϰ� �Ѵ�.






// ��� MP3 ����� �������̽� 
// �������̽� �Һ��� ��Ģ(�������̽��� �����Ǹ� �ȵȴ�)
struct IMP3
{
	virtual void Play() = 0;
	virtual void Stop() = 0;
//	virtual void PlayOneMinute() = 0;
	virtual ~IMP3() {}
};
class IPod : public IMP3
{
public:
	void Play() { cout << "Play MP3 with IPod" << endl; }
	void Stop() { cout << "Stop" << endl; }
};
//------------------------------

// MP3�� ���� ������ People �� ����� ���̿�
// �߰� ������ ���� �մϴ�.
// ������ ���� ���� "�������� �������ϴ�."
// ��, ������ ���ϵ˴ϴ�.
class MP3
{
	IMP3* mp3;
public:
	MP3(IMP3* p = nullptr) : mp3(p)
	{
		if (mp3 == nullptr)
			mp3 = new IPod;
	}
	// ��� ����(�Լ�)�� ������
	// "������ �����ο� ���� �մϴ�."
	void Play() { mp3->Play(); }
	void Stop() { mp3->Stop(); }
	void PlayOneMinute() 
	{ 
		mp3->Play();
		// 1�� �����
		mp3->Stop();
	}
};

class People
{
public:
//	void Use(IPod* p) // ����� "������ IPod" �� ����Ҽ� �ִ�.
//	void Use(IMP3* p) // Ư�� ��ǰ�� �ƴ� �پ��� MP3 ��ǰ�� ����Ҽ� �ִ�.
					  // �������̽��� ����ϸ� ��ü�� ������ ����

	void Use(MP3* p) // IMP3�� ���� ������� ����, ������ ���
	{
		p->Play();
		p->Stop();

		// ������� �䱸������ ���� �߰�/����ȴ�.
		// p�� IMP3* Ÿ���̶��
		// �������̽� ������ �ʿ��ϴ�.(�������̽��� �����ϴ� ���� ���� �Ұ����ϴ�.)
		p->PlayOneMinute();
	}
};

int main()
{
	People p;
	MP3 mp3;
	p.Use(&mp3);
}


// ��ü���� �������� �ٽ� 
// => ������(�߰���)�� ���� ����ϴ� �� 
// => ��??, � ������ �������� ������°� ??
// 
// �����	 ===> stack     ===> list				adapter : �������̽�����������
// �����	 ===> TCPServer ===> IPAddress, socket	facade  : �������������̽�(����ϱ� ����)
// ����� ===> Calc      ===>	 ����				proxy   : �پ��� �뵵�λ���ϱ� ���� ������
// ����� ===> MP3       ===>	 IMP3				bridge : update�� ���ϰ�..