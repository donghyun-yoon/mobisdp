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

	friend class ImageFactory;
};

class ImageFactory
{
	std::map<std::string, Image*> image_map;
public:
	Image* Create(const std::string& url)
	{
		Image* img = nullptr;

		auto ret = image_map.find(url);

		if (ret == image_map.end())
		{
			img = new Image(url);
			image_map[url] = img;
		}
		else
			img = ret->second;
		return img;
	}
};

int main()
{
	ImageFactory factory;	// 이 경우 factory 는 싱글톤으로 하게되는 경우가
							// 많습니다.

	Image* img1 = factory.Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = factory.Create("www.naver.com/a.png");
	img2->Draw();
}


