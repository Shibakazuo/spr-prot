#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"

using namespace std;

// AssignNode
AssignNode::AssignNode() {
	nextNode = NULL;
}

void AssignNode::setLabel(int num) {
	label = num;
}

AssignNode::AssignNode(int label) {
	nextNode = NULL;
	label = label;
}

Environment AssignNode::getEnv() {
	return env;
}

int AssignNode::getLabel() {
	return label;
}

void AssignNode::setEnv(int x, int y, int z) {
	env.x = x;
	env.y = y;
	env.z = z;
}

INode* AssignNode::getNext() {
	return nextNode;
}

void AssignNode::setNext(INode* next) {
	nextNode = next;
}

void AssignNode::setValue(string vname, Arithmetic* var) {
	varName = vname;
	variable = var;
	if (vname == "x") {
		setEnv(var->getValue(), env.y, env.z);	
	} else if (vname == "y") {
		setEnv(env.x, var->getValue(), env.z);
	} else {
		setEnv(env.x, env.y, var->getValue());
	} 
} 

string AssignNode::getCode() {
	return varName + " := " + variable->getCode();
}

INode* AssignNode::printAndSkip() {
	cout << this->getCode() << endl;
	return nextNode;
}

// Branchnode
BranchNode::BranchNode() {
	trueNode = NULL;
	falseNode = NULL;
}

Environment BranchNode::getEnv() {
	return env;
}

int BranchNode::getLabel() {
	return label;
}

void BranchNode::setLabel(int num) {
	label = num;
}

void BranchNode::setEnv(int x, int y, int z) {
	env.x = x;
	env.y = y;
	env.z = z;
}

INode* BranchNode::getNext() {
	return direct->getDirect() ? trueNode : falseNode;
}

void BranchNode::setNext(INode* tNode, INode* fNode) {
	trueNode = tNode;
	falseNode = fNode;
}

void BranchNode::setDirect(ImpBool* di) {
	direct = di;
}

string BranchNode::getCode() {
	return direct->getCode();
}

INode* BranchNode::printAndSkip() {
	if (ifWhile(this, label)) {
		cout << "WHILE " + direct->getCode() << endl;
		cout << " " + trueNode->getCode() << endl;
		cout << "END WHILE" << endl;
	} else {
		cout << "IF " + direct->getCode() << endl;
		cout << " " + trueNode->getCode() << endl;
		cout << "END IF" << endl;
	}
	return falseNode;
}

bool BranchNode::ifWhile(INode* node, int label) {
	if (node->getNext() == NULL) {
		return false;
	} 
	if (node->getLabel() == label) {
		return true;
	}
	ifWhile(node->getNext(), label);
}


// FuncNode
FuncNode::FuncNode() {
	nextNode = NULL;
}

Environment FuncNode::getEnv() {
	return env; 
}

int FuncNode::getLabel() {
	return label;
}

void FuncNode::setEnv (int x, int y, int z) {
	env.x = x;
	env.y = y;
	env.z = z;
} 

void FuncNode::setLabel(int num) {
	label = num;
}

INode* FuncNode::getNext() {
	return nextNode;
}

void FuncNode::setNext(INode* next) {
	nextNode = next;
}

void FuncNode::skip() {
	while (nextNode->getLabel() > label) {
		nextNode = nextNode->getNext();
	}
}

void FuncNode::printEnv() {
	cout << env.x << " " << env.y << " " << env.z << endl; 
}

string FuncNode::getCode() {
	return "a";
}

INode* FuncNode::printAndSkip() {
	return NULL;
}
