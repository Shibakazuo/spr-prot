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

void AssignNode::setValue(string vname, Avar val) {
	valName = vname;
	value = val;

	switch (vname) {
		case "x":
			setEnv(val, env.y, env.z);
			break;
		case "y";
			setEnv(env.x, val, env.z);
		case "z";
			setEnv(env.x, env.y, val); 
	}
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
	return direct ? trueNode : falseNode;
}

void BranchNode::setNext(INode* tNode, INode* fNode) {
	trueNode = tNode;
	falseNode = fNode;
}

void BranchNode::setDirect(bool di) {
	direct = di;
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
