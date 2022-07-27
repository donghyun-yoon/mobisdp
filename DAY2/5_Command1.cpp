#include <iostream>
#include <vector>

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};

// command : ����� ĸ��ȭ�ؼ� ����/����/��� ���� �����ϰ� �Ѵ�.

struct ICommand
{
	virtual void execute() = 0;
	virtual bool canUndo() { return false; }
	virtual void undo() {}
	virtual ~ICommand() {}
};

// �簢���� �߰��ϴ� ���
class AddRectCommand : public ICommand
{
	std::vector<Shape*>& v; // �����Դϴ�.
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {}

	virtual void execute() override { v.push_back(new Rect); };
	virtual bool canUndo() override { return true; }
	virtual void undo()    override 
	{
		Shape* p = v.back();
		v.pop_back();

		delete p;
	}
};
class AddCircleCommand : public ICommand
{
	std::vector<Shape*>& v; 
public:
	AddCircleCommand(std::vector<Shape*>& v) : v(v) {}

	virtual void execute() override { v.push_back(new Circle); };
	virtual bool canUndo() override { return true; }
	virtual void undo()    override
	{
		Shape* p = v.back();
		v.pop_back();

		delete p;
	}
};

class DrawCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	DrawCommand(std::vector<Shape*>& v) : v(v) {}

	virtual void execute() override
	{
		for (auto p : v) p->draw();
	};

	virtual bool canUndo() override { return true; }
	virtual void undo()    override
	{
		system("cls");
	}
};

#include <stack>

int main()
{
	std::vector<Shape*> v;

	std::stack<ICommand*> cmd_stk;

	ICommand* pcmd = nullptr;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			pcmd = new AddRectCommand(v);
			pcmd->execute();
	
			cmd_stk.push(pcmd);
		}
		else if (cmd == 2)
		{
			pcmd = new AddCircleCommand(v);
			pcmd->execute();

			cmd_stk.push(pcmd);
		}
		else if (cmd == 9)
		{
			pcmd = new DrawCommand(v);
			pcmd->execute();

			cmd_stk.push(pcmd);
		}
	}
}




