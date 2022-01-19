#include "StackNode.hpp"

class Stack
{
public:

	Stack()
	{
		this->top = nullptr;
	}
	~Stack()
	{
		
	}
	
	bool isEmpty();
	void push(const string & dateOfAbsences);
	void pop(StackNode& data);
	string peek();


private:
	StackNode* top;
};

void displayMenu();

void displaySubMenu();

int getOption();

string getCurrentDate();
