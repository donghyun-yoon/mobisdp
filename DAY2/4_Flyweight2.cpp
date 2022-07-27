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

	// �ڽ��� ��ü�� �����ϴ� static ��� �Լ�
	static Image* Create(const std::string& url)
	{
		Image* img = new Image(url);
		return img;
	}
};

int main()
{
	Image* img1 = Image::Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = Image::Create("www.naver.com/a.png");
	img2->Draw();

}



