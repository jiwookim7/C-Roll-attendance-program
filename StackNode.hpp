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

class StackNode
{
public:

	StackNode();
	StackNode(const string & dateOfAbsences);

	//setters/getters
	void setNextStackNode(StackNode* next);
	StackNode* getNextStackNode() const;
	void setDateOfAbsences(const string & newDate);

	string getDateOfAbsences() const;

	void insertDateOfAbsences(const StackNode & absence);

private:

	string dateOfAbsences;

	StackNode* nextStackNode;


};
