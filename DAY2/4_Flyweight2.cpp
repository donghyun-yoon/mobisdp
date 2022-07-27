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
			img = ret->second; // ret�� pair �ε�
								// ret->first �� Ű��(url)
								// ret->second �� value(Image*)
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
// �ٽ�. ��ü�� ���鶧 "static ��� �Լ�"�� ����ϴ� ���� �� �˾Ƶμ���

// 1. Image img("a.png"); // ����� ���� ���� �Ӵ�. �׷���, �ı������� ��ӵǾ� �ִ�.
// 2. new Image("a.png"); // ����� ���� ���� �Ӵ�. �ı��� �����Ӵ�.
// 
// 3. Image::Create("a.png"); // ��ü ������ �Ѱ����� ���ߵȴ�.
//							  // �پ��� ������ �ټ� �ִ�.
//							���� �Ѱ��� ����� �ϰ� �ʹ�. : �̱���
//							�Ӽ��� �����ϸ� ����         : Flyweight

