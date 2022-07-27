// 1_Flyweight - 167
#include <iostream>
#include <string>
#include <map>


// �Ӽ��� ������ ��ü��  ���� �Ҽ� �ְ� ����.

// Image : �׸��� �ٿ�ε��ؼ� ȭ�鿡 �׸��� ��ɼ���
class Image
{
	std::string image_url;
public:
	Image(std::string url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
	void Draw() { std::cout << "Draw " << image_url << std::endl; }
};

int main()
{
	Image* img1 = new Image("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = new Image("www.naver.com/a.png");
	img2->Draw();

}


