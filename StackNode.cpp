#include "StackNode.hpp"


StackNode::StackNode()
{
	dateOfAbsences = "";
	this->nextStackNode = nullptr;


}

StackNode::StackNode(const string& dateOfAbsences)
{
	this->dateOfAbsences = dateOfAbsences;
	this->nextStackNode = nullptr;
}

void StackNode::setNextStackNode(StackNode* next)
{
	this->nextStackNode = next;
}

StackNode* StackNode::getNextStackNode() const
{
	return nextStackNode;
}

void StackNode::setDateOfAbsences(const string & newDate)
{
	dateOfAbsences = newDate;
}

string StackNode::getDateOfAbsences() const
{
	return dateOfAbsences;
}


void StackNode::insertDateOfAbsences(const StackNode & absence)
{
	StackNode* newStackNode = new StackNode(absence);

	newStackNode->setNextStackNode(nextStackNode);
	nextStackNode = newStackNode;
}
