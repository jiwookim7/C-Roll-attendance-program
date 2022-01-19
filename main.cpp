/***************************************************************************************
Programmer's name: Jiwoo Kim
Class: CptS 122 Spring 2021
(BONUS Assignment) Programming Assignment 7: Attendance Tracker w/ class Templates
Date: 04/22/21
Descrition: https://eecs.wsu.edu/~aofallon/cpts122/progassignments/PA7.htm
*****************************************************************************************/


#include "Stack.hpp"
#include "Node.hpp"

int main(void)
{
	ifstream infile;
	infile.open("classList.csv");

	ofstream outfile;
	outfile.open("masterList.txt");

	ofstream outfile2;
	outfile2.open("absences.txt");

	ofstream outfile3;
	outfile3.open("Absence.txt");

	

	int option = 0;

	Node <string> temp;
	Node <string> absences;
	List <string> list1;
	string IDAndName;
	string edit;
	string hold;
	string mark;
	string check;

	

	//	StackNode absences;

		//gets the current date
	string date = getCurrentDate();

	do
	{
		displayMenu();
		option = getOption();

		switch (option)
		{
		case 1: 
			
			//Option 1: Reads the .csv course file and overwrites the master list.
			
			
			while (!infile.eof())
			{
			
				infile >> temp;
				//reading info and storing to list1
				list1.insert(temp);

				cout << temp.getRecordNumber() << ends;
				cout << temp.getID() << ends;
				cout << temp.getName() << ends;
				cout << temp.getEmail() << ends;
				cout << temp.getUnits() << ends;
				cout << temp.getProgram() << ends;
				cout << temp.getLevel() << ends;

				cout << endl;
				
			}

			cout << "Course List imported to the List!" << endl << endl;

			break;

			//Option 2: Populates the master list with previous nodes from master.txt.

		case 2: //load master list  

			getline(infile, hold, '\n');

			while (!infile.eof())
			{
				
				infile >> temp;
				//temp.setAbsences("0");
				list1.insert(temp);

			}

			break;

		//Option 3: Stores the contents of the master list¡¯s nodes to master.txt.
		
		case 3: //store master list
			
		Node <string>* phead;

		phead = list1.getNode();

		while(phead != nullptr)
		{
				
				outfile << phead->getRecordNumber() << ",";
				outfile << phead->getID() << ",";
				outfile << phead->getName() << ",";
				outfile << phead->getEmail() << ",";
				outfile << phead->getUnits() << ",";
				outfile << phead->getProgram() << ",";
				outfile << phead->getLevel() << endl;

				phead = phead->getNode();
			}

			break;

			

		case 4: //mark absenses

			//displays each students' name from masters.txt

			Node <string>* absences1;
			absences1 = list1.getNode();

			while (absences1 != nullptr)
			{
			
				cout << absences1->getName() << endl;

				//prompts if he/she was absent for the current day
				cout << "Was this student absent on " << date << "?" << endl;
				cout << "Type 'y' for yes OR 'n' for no:" << endl;

				char yesOrNo;

				cin >> yesOrNo;

				if (yesOrNo == 'y')
				{

					cout << absences1->getName() << " was absent on " << date << ". " << endl << endl;
					
					int absence = stoi(absences1->getAbsences()); //convert string to int

					absence++; //increment 

					absences1->setAbsences(to_string(absence)); //convert back to string

				}
				else
				{

					cout << absences1->getName() << " wasn't absent on " << date << ". " << endl;

					cout << endl;
				}

				absences1 = absences1->getNode();
			}


			break;

		case 5: //BONUS: Option 5: Prompts for an ID number or name of student to edit. Prompts for the date of absence to edit.

			Node <string>* top;

			top = list1.getNode();


			cout << "Enter the ID number or Name of student to edit: " << endl;
			cin >> IDAndName;

			while (top != nullptr)
			{
			
				if (IDAndName.compare(top->getID()) == 0)
				{
					cout << "Enter the edit value of ID: " << endl;
					cin >> edit;

					top->setID(edit);
					

					//cout << top->getID() << endl;
				}
				else if (IDAndName.compare(top->getName()) == 0)
				{
					cout << "Enter the edit value of name: " << endl;
					cin >> edit;

					top->setName(edit);

					//cout << top->getName() << endl;
				}
				
				top = top->getNode();
			}
			
			break;

		case 6: //generate report

			displaySubMenu();

			int subOption = 0;
			subOption = getOption();

			switch (subOption)
			{
			case 1: // 1. generate report for all students (showing only the most recent absence for each student

				//print student's name with the date of absent
				cout << "Name with date absent: " << endl;

				Node <string>* absence1;
				absence1 = list1.getNode();
				check = "1";

				while (absence1 != nullptr)
				{
					if (absence1->getAbsences() == check)
					{
						outfile2 << absence1->getName() << endl;
						outfile2 << date << endl;

						cout << absence1->getName() << ends;
						cout << date;
						cout << endl;
					}

					absence1 = absence1->getNode();
				}

				break;
			case 2: // 2. generate report for students with absences that match or exceed (the number entered by the user)


				Node <string>* absence;
				absence = list1.getNode();

				cout << "Enter the number of absences you want to search: " << endl;
				cin >> mark;

				while (absence != nullptr)
				{
					
					if (mark.compare(absence->getAbsences()) == 0) //match
					{
						outfile3 << absence->getName() << endl;
						outfile3 << date << endl;
						cout << absence->getName() << endl;
						cout << date << endl;
					}
					else if (mark.compare(absence->getAbsences()) < 0) //exceed
					{
						outfile3 << absence->getName() << endl;
						outfile3 << date << endl;
						cout << absence->getName() << endl;
						cout << date << endl;
					}
					absence = absence->getNode();
				}

				break;
			}

			break;
		}

	} while (option != 7);

	infile.close();
	outfile.close();
	outfile2.close();
	outfile3.close();
	

	return 0;
}