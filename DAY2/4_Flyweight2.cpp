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



