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

// 도형을 추가하는 명령은 유사한 부분이 많습니다.
// 기반 클래스를 도입하면 편리합니다.

class AddCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCommand(std::vector<Shape*>& v) : v(v) {}
	// new T
	virtual void execute() override { v.push_back(CreateShape()); };
	virtual bool canUndo() override { return true; }
	virtual void undo()    override
	{
		Shape* p = v.back();
		v.pop_back();
		delete p;
	}
	virtual Shape* CreateShape() = 0;
};

class AddRectCommand : public AddCommand
{
public:
	AddRectCommand(std::vector<Shape*>& v) : AddCommand(v) {}

	virtual Shape* CreateShape() { return new Rect; }
};

class AddCircleCommand : public AddCommand
{
public:
	AddCircleCommand(std::vector<Shape*>& v) : AddCommand(v) {}

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


class MacroCommand : public ICommand // "Composite" 패턴의 기본 모양
{
	std::vector<ICommand*> v;
public:
	void addCommand(ICommand* p) { v.push_back(p); }
	
	void execute()
	{
		for (auto p : v)
			p->execute();
	}
};

int main()
{
	std::vector<Shape*> v;

	MacroCommand* mc1 = new MacroCommand;
	mc1->addCommand(new AddRectCommand(v));
	mc1->addCommand(new AddCircleCommand(v));
	mc1->addCommand(new DrawCommand(v));
	
	mc1->execute();


	MacroCommand* mc2 = new MacroCommand;
	mc2->addCommand(new AddRectCommand(v));
	mc2->addCommand( mc1 );
	mc2->execute();



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




