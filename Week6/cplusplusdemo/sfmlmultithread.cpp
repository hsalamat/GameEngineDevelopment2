#include <iostream>
#include <SFML\Window.hpp>
using namespace std;


// example 1: non member function with one argument
void threadFunc(int argument)
{
	cout << "non member function with one argument" << endl; 
}

class Task1
{
public:
	void run()
	{		
		cout << "member function" << endl;
	}
};

struct Task2
{
	void operator()() {
		cout << "functor" << endl;
	}
};




int main() {

	sf::Thread thread1(&threadFunc, 5);
	thread1.launch(); // start the thread (internally calls threadFunc(5))

	Task1 task;
	sf::Thread thread2(&Task1::run, &task);
	thread2.launch(); // start the thread (internally calls task.run())

	Task2 task2;
	sf::Thread thread3(task2);
	thread3.launch(); // start the thread (internally calls operator() on the Task instance)

	system("pause");
	return 0;
}