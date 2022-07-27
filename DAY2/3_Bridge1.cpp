// 6_Bridge1 - 90 page
#include <iostream>
using namespace std;

// 브릿지 패턴의 핵심

// 구현(IMP3, IPod)과 추상(MP3) 를 분리해서
// 상호 독립적인 update 가 가능하게 한다.






// 모든 MP3 기기의 인터페이스 
// 인터페이스 불변의 법칙(인터페이스는 수정되면 안된다)
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

// MP3의 실제 구현과 People 의 사용자 사이에
// 중간 계층을 설계 합니다.
// 계층이 많아 지면 "유연성은 좋아집니다."
// 단, 성능의 저하됩니다.
class MP3
{
	IMP3* mp3;
public:
	MP3(IMP3* p = nullptr) : mp3(p)
	{
		if (mp3 == nullptr)
			mp3 = new IPod;
	}
	// 모든 연산(함수)의 구현은
	// "독립된 구현부에 의존 합니다."
	void Play() { mp3->Play(); }
	void Stop() { mp3->Stop(); }
	void PlayOneMinute() 
	{ 
		mp3->Play();
		// 1분 경과후
		mp3->Stop();
	}
};

class People
{
public:
//	void Use(IPod* p) // 사람은 "애플의 IPod" 만 사용할수 있다.
//	void Use(IMP3* p) // 특정 제품이 아닌 다양한 MP3 제품을 사용할수 있다.
					  // 인터페이스를 사용하면 교체가 가능한 설계

	void Use(MP3* p) // IMP3를 직접 사용하지 말고, 간접층 사용
	{
		p->Play();
		p->Stop();

		// 사용자의 요구사항이 자주 추가/변경된다.
		// p가 IMP3* 타입이라면
		// 인터페이스 수정이 필요하다.(인터페이스를 변경하는 것은 거의 불가능하다.)
		p->PlayOneMinute();
	}
};

int main()
{
	People p;
	MP3 mp3;
	p.Use(&mp3);
}


// 객체지향 디자인의 핵심 
// => 간접층(중간층)을 만들어서 사용하는 것 
// => 왜??, 어떤 이유로 간접층을 만들었는가 ??
// 
// 사용자	 ===> stack     ===> list				adapter : 인터페이스변경을위해
// 사용자	 ===> TCPServer ===> IPAddress, socket	facade  : 포괄적인터페이스(사용하기 쉽게)
// 사용자 ===> Calc      ===>	 서버				proxy   : 다양한 용도로사용하기 위한 대행자
// 사용자 ===> MP3       ===>	 IMP3				bridge : update를 편리하게..