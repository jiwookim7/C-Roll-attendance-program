#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using std::ifstream;
using std::ofstream;
using std::istream;
using std::fstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ends;
using std::getline;
using std::stoi;
using std::to_string;

//Node class, which contains a data member of type T (this will be replaced by the type class Data) 
//when it is instantiated, along with a pointer to the next Node.


template <class T>

class Node
{
public:
	Node();
	Node(Node<T>& data);

	void setNextNode(Node<T>* next);
	Node<T>* getNode() const;


	void setRecordNumber(T newRecordNumber);
	void setID(T newID);
	void setName(T newName);
	void setEmail(T newEmail);
	void setUnits(T newUnits);
	void setProgram(T newProgram);
	void setLevel(T newLevel);
	void setAbsences(T newAbsences);

	T getRecordNumber() const;
	T getID() const;
	T getName() const;
	T getEmail() const;
	T getUnits() const;
	T getProgram() const;
	T getLevel() const;
	T getAbsences() const;



private:

	T recordNumber;
	T ID;
	T name;
	T email;
	T units;
	T program;
	T level;
	T absences;

	Node<T>* next;

};


template<class T>

ifstream& operator >> (ifstream& lhs, Node<T>& rhs);

template <class T>
ofstream& operator << (ofstream& lhs, Node<T>& rhs);


template <class T>

Node<T>::Node()
{
	recordNumber = "";
	ID = "";
	name = "";
	email = "";
	units = "";
	program = "";
	level = "";
	absences = "";

	this->next = nullptr;
}

template <class T>

Node<T>::Node(Node<T>& data)
{
	recordNumber = data.recordNumber;
	ID = data.ID;
	name = data.name;
	email = data.email;
	units = data.units;
	program = data.program;
	level = data.level;
	absences = data.absences;

	this->next = nullptr;

}

template <class T>

void Node<T>::setNextNode(Node<T>* next)
{
	this->next = next;
}

template <class T>

Node<T>* Node<T>::getNode() const
{
	return this->next;
}

template <class T>

void Node<T>::setRecordNumber(T newRecordNumber)
{
	recordNumber = newRecordNumber;
}

template <class T>

void Node<T>::setID(T newID)
{
	ID = newID;
}

template <class T>

void Node<T>::setName(T newName)
{
	name = newName;
}

template <class T>

void Node<T>::setEmail(T newEmail)
{
	email = newEmail;
}

template <class T>

void Node<T>::setUnits(T newUnits)
{
	units = newUnits;
}

template <class T>

void Node<T>::setProgram(T newProgram)
{
	program = newProgram;
}

template <class T>

void Node<T>::setLevel(T newLevel)
{
	level = newLevel;
}

template <class T>

void Node<T>::setAbsences(T newAbsences)
{
	absences = newAbsences;
}

template <class T>

T Node<T>::getRecordNumber() const
{
	return recordNumber;
}

template <class T>

T Node<T>::getID() const
{
	return ID;
}
template <class T>
T Node<T>::getName() const
{
	return name;
}
template <class T>
T Node<T>::getEmail() const
{
	return email;
}
template <class T>
T Node<T>::getUnits() const
{
	return units;
}
template <class T>
T Node<T>::getProgram() const
{
	return program;
}
template <class T>
T Node<T>::getLevel() const
{
	return level;
}
template <class T>
T Node<T>::getAbsences() const
{
	return absences;
}



template <class T>

class List
{
public:
	List()
	{
		this->head = nullptr;
	}

	Node<T>* getNode() const;
	void setNode(Node<T>* head);

	void insert(Node<T> & head);


private:
	Node<T>* head;
};

template <class T>

Node<T>* List<T>::getNode() const
{
	return this->head;
}

template <class T>

void List<T>::setNode(Node<T>* head)
{
	this->head = head;
}

template <class T>
void List<T>::insert(Node<T> & head)
{
	Node<T>* newnode = new Node<T>(head);
	Node<T>* temp = new Node<T>(head);

	if (this->head == nullptr)
	{
		this->head = newnode;
	}
	else
	{
		newnode->setNextNode(this->head);
		this->head = newnode;
	}

}




template<class T>

ifstream& operator >> (ifstream& lhs, Node<T>& rhs)
{
	string RecordNum;
	getline(lhs, RecordNum, ',');
	rhs.setRecordNumber(RecordNum);

	string ID;
	getline(lhs, ID, ',');
	rhs.setID(ID);

	/*
	string name;
	getline(lhs, name, ',');
	rhs.setName(name);
	*/

	string lastName, firstName;
	getline(lhs, lastName, ',');
	getline(lhs, firstName, ',');
	lastName.append(", ");
	lastName.append(firstName);

	rhs.setName(lastName);

	string email;
	getline(lhs, email, ',');
	rhs.setEmail(email);

	string units;
	getline(lhs, units, ',');
	rhs.setUnits(units);

	string program;
	getline(lhs, program, ',');
	rhs.setProgram(program);

	string level;
	getline(lhs, level);
	rhs.setLevel(level);

	string absence;
	absence = "0";
	rhs.setAbsences(absence);

	//getline(lhs, level, ' ');

	return lhs;
}


template <class T>
ofstream& operator << (ofstream& lhs, Node<T>& rhs)
{
	lhs << rhs.getRecordNumber() << endl << rhs.getID() << endl << rhs.getName() << endl
		<< rhs.getEmail() << endl << rhs.getUnits() << endl << rhs.getProgram() << endl << rhs.getLevel() << endl;

	return lhs;

}