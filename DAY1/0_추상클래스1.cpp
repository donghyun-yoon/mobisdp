// 1_�߻�Ŭ����1.cpp - 10page

// �߻� Ŭ���� : ���� �����Լ��� �Ѱ��̻� �ִ� Ŭ����
// �ǵ� : �Ļ� Ŭ���� �����ڿ��� Ư�� �Լ��� �ݵ�� ������ �����ϴ� ��
class Shape
{
public:
	virtual void Draw() = 0; // ���� �����Լ�(pure virtual function)
};

class Rect : public Shape
{
	// Draw �� ������ �������� ������ Rect �� �߻�Ŭ���� �̴�.
public:
	virtual void Draw() override {}  // �̷��� ������ �����ϸ� �߻� Ŭ������ �ƴϴ�.
};
int main()
{
//	Shape  s;	// error. �߻� Ŭ������ ��ü�� ����� ����.
//	Shape* p;	// ok..   �߻� Ŭ������ �����ʹ� ����� �ִ�.
//	Rect  r;	// error. - Draw ������ ���ٸ�.. 
}



// Ctrl + F5 �� ������ ���� �˴ϴ�.
// ����
// part 1. ������ ������ ���� C++ ����
// part 2. ������ ���� ������ ����
// part 3. ������ ���� ī�װ� ����. 