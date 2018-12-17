#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"

using namespace std;

// AssignNode
AssignNode::AssignNode() {
	next = NULL;
}

Environment AssignNode::getEnv() {
	return env;
}

void AssignNode::setEnv(int x, int y, int z) {
	env.x = x;
	env.y = y;
	env.z = z;
}

void AssignNode::setNext(Node* next) {
	nextNode = next
}

void AssignNode::setLabel(int num) {
	label = num;
}


// Branchnode
BranchNode::BranchNode() {
	next = NULL;
}

Environment BranchNode::getEnv() {
	return env;
}

void BranchNode::setEnv(int x, int y, int z) {
	env.x = x;
	env.y = y;
	env.z = z;
}

void BranchNode::setNext(Node* tNode, Node* fNode) {
	trueNode = tNode;
	falseNode = fNode;
}

void AssignNode::setLabel(int num) {
	label = num;
}
