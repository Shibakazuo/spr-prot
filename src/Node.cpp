#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"

using namespace std;

// Node

int Node::getLabel() {
	return label;
}

Node* Node::getNextNode() {
	return nextNode;
}

// AssignNode
AssignNode::AssignNode() {
	nextNode = NULL;
}

AssignNode::AssignNode(int label) {
	nextNode = NULL;
	label = label;
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
	nextNode = next;
}


// Branchnode
BranchNode::BranchNode() {
	trueNode = NULL;
	falseNode = NULL;
}

BranchNode::BranchNode(int label) {
	trueNode = NULL;
	falseNode = NULL;
	label = label;
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


// FuncNode
FuncNode::FuncNode() {
	nextNode = NULL;
}

FuncNode::FuncNode(int label) {
	nextNode = NULL; 
	label = label;
}

Environment FuncNode::getEnv() {
	return env; 
}

void FuncNode::setEnv (int x, int y, int z) {
	env.x = x;
	env.y = y;
	env.z = z;
} 

void FuncNode::setNext(Node* next) {
	nextNode = next;
}

void FuncNode::skip() {
	while (nextNode->getLabel() > label) {
		nextNode = nextNode->getNextNode();
	}
}

void FuncNode::printEnv() {
	cout << env.x << " " << env.y << " " << env.z << endl; 
}
