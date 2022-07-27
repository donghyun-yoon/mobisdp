#include <iostream>
#include <string>
#include <map>

class Image
{
	std::string image_url;

	Image(std::string url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }

	// 자신의 객체를 생성하는 static 멤버 함수
	static std::map<std::string, Image*> image_map;

	static Image* Create(const std::string& url)
	{
		Image* img = nullptr;

		auto ret = image_map.find(url);
		
		if (ret == image_map.end())
		{
			img = new Image(url);
			image_map[url] = img;
		}
		else
			img = ret->second; // ret는 pair 인데
								// ret->first 는 키값(url)
								// ret->second 는 value(Image*)
		return img;
	}
};
std::map<std::string, Image*> Image::image_map;

int main()
{
	Image* img1 = Image::Create("www.naver.com/a.png");
	img1->Draw();
	Image* img2 = Image::Create("www.naver.com/a.png");
	img2->Draw();
}
// 핵심. 객체를 만들때 "static 멤버 함수"를 사용하는 것을 꼭 알아두세요

// 1. Image img("a.png"); // 만드는 것은 자유 롭다. 그런데, 파괴시점이 약속되어 있다.
// 2. new Image("a.png"); // 만드는 것은 자유 롭다. 파괴도 자유롭다.
// 
// 3. Image::Create("a.png"); // 객체 생성이 한곳으로 집중된다.
//							  // 다양한 제약을 줄수 있다.
//							오직 한개만 만들게 하고 싶다. : 싱글톤
//							속성이 동일하면 공유         : Flyweight

