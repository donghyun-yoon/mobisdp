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

struct ICommand
{
	virtual void execute() = 0;
	virtual bool canUndo() { return false; }
	virtual void undo() {}
	virtual ~ICommand() {}
};

// ������ �߰��ϴ� ����� ������ �κ��� �����ϴ�.
// ��� Ŭ������ �����ϸ� ���մϴ�.

class AddCommand : public ICommand
{
	std::vector<Shape*>& v; 
public:
	AddCommand(std::vector<Shape*>& v) : v(v) {}

	virtual void execute() override { v.push_back( CreateShape() ); };
	virtual bool canUndo() override { return true; }
	virtual void undo()    override
	{
		Shape* p = v.back();
		v.pop_back();
		delete p;
	}
	// Factory Method ����
	// ��ü�� ����� ���� �������̽��� �����ϰ�, ���������
	// � ��ü�� �������� �Ļ�Ŭ������ �����Ѵ�.
	// ��ü�� ���� ������ ����Ŭ������ ����.

	// �ڵ� ������ "template method" �� ����

	// template method : �˰����� ����
	// factory  method : � ��ü�� ������ ��ü�� Ÿ���� ����
	
	virtual Shape* CreateShape() = 0;
};

class AddRectCommand : public AddCommand
{
public:
	AddRectCommand(std::vector<Shape*>& v) : AddCircleCommand(v) {}

	virtual Shape* CreateShape() { return new Rect; }
};

class AddCircleCommand : public ICommand
{
public:
	AddCircleCommand(std::vector<Shape*>& v) : AddCircleCommand(v) {}

	virtual Shape* CreateShape() { return new Circle; }

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
		else if (cmd == 0)
		{
			if (!cmd_stk.empty())
			{
				pcmd = cmd_stk.top();
				cmd_stk.pop();

				if (pcmd->canUndo())
					pcmd->undo();

				delete pcmd; 
			}
		}
	}
}




