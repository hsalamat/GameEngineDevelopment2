#include <functional>
#include <iostream>
#include <string>
using namespace std;


template <typename T>
class Command
{
public:
	std::function<void(T&)> action;
};


class A
{
public:
	void moveLeft() 
	{
		cout << "Moving Left..." << endl;
	}

	void moveRight()
	{
		cout << "Moving Right..." << endl;
	}
};


class SceneNode {
public:
	void moveLeft()
	{
		cout << "Node Moving Left..." << endl;
	}

	void moveRight()
	{
		cout << "Node Moving Right..." << endl;
	}
};

class Command2
{
public:
	std::function<void(SceneNode&)> action;
};


int main(void)
{
	A a;
	Command<A> b;
	b.action = &A::moveLeft;
	b.action(a);

	b.action = &A::moveRight;
	b.action(a);


	SceneNode node;
	Command2 c;
	c.action = &SceneNode::moveLeft;
	c.action(node);

	c.action = &SceneNode::moveRight;
	c.action(node);


	string bye = "bye";
	getline(cin, bye);

	return 0;
}