#include "Stack.hpp"
#pragma warning(disable : 4996)

bool Stack::isEmpty()
{
	bool success = false;

	if (this->top == nullptr)
	{
		success = true;
	}

	return success;
}


void Stack::push(const string & dateOfAbsences)
{
	StackNode* newnode = new StackNode(dateOfAbsences);

	if (isEmpty())
	{
		this->top = newnode;
	}
	else
	{
		newnode->setNextStackNode(this->top);
		this->top = newnode;
	}
}

void Stack::pop(StackNode & data)
{
	if (!isEmpty())
	{
		StackNode* temp = this->top;
		this->top = this->top->getNextStackNode();
		data.setDateOfAbsences(temp->getDateOfAbsences());
		delete temp;
	}
}


string Stack::peek()
{
	return this->top->getDateOfAbsences();
}


/***************************************************************************************************************/

//display menu
void displayMenu()
{
	cout << "Select from the following menu: " << endl;
	cout << "1. Import course list" << endl;
	cout << "2. Load master list" << endl;
	cout << "3. Store master list" << endl;
	cout << "4. Mark absences" << endl;
	cout << "5. BONUS: Edit absences" << endl;
	cout << "6. Generate report" << endl;
	cout << "7. Exit!" << endl << endl;
}

void displaySubMenu()
{
	cout << "1. Generate report for all students" << endl;
	cout << "2. Generate report for students wiht absences that match or exceed (the number entered by the user" << endl;
}

//get option from the user
int getOption()
{
	int option = 0;

	cin >> option;

	return option;
}

// retrieved from stackoverflow - http://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c

string getCurrentDate()
{
	time_t t = time(0);   // get time now

	struct tm* now = localtime(&t);

	//	cout << (now->tm_mon + 1) << '-' << now->tm_mday << '-' << (now->tm_year + 1900) << endl;

	string month, day, year;

	month = to_string(now->tm_mon + 1);
	day = to_string(now->tm_mday);
	year = to_string(now->tm_year + 1900);

	month.append("-");
	month.append(day);
	month.append("-");
	month.append(year);

	return month;
}
