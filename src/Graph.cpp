#include <cstring>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Graph.h"

using namespace std;

// public
Graph::Graph() {
	entry = NULL;
	exit = NULL;
}

void Graph::srcGraphInit() {
	// 1
	Aconst* r1 = new Aconst(Ainit);
	// 2
	Aconst* r2= new Aconst(Binit);
	// 3
	Aconst* r3 = new Aconst(0);
	// 4
	Avar* lplus4 = new Avar("sum", 0);
	Aconst* rplus4 = new Aconst(studentNum);
	Aplus* r4 = new Aplus(lplus4, rplus4);
	// 5
	Avar* lplus5 = new Avar("sum", 0);
	Aconst* rplus5 = new Aconst(teacherNum);
	Aplus* r5 = new Aplus(lplus5, rplus5);

	initANode(&nodes.aNodes[0], 1, "student", r1, &nodes.aNodes[1]);
	nodes.aNodes[0].setEnv(0, 0, 0);
	initANode(&nodes.aNodes[1], 2, "teacher", r2, &nodes.aNodes[2]);
	initANode(&nodes.aNodes[2], 3, "sum", r3, &nodes.aNodes[3]);
	initANode(&nodes.aNodes[3], 5, "sum", r4, &nodes.aNodes[4]);
	initANode(&nodes.aNodes[4], 7, "sum", r5, &nodes.fNodes[0]);
	nodes.fNodes[0].setLabel(9);
	nodes.fNodes[0].setNext(NULL);
	entry = &nodes.aNodes[0];
	exit = &nodes.fNodes[0];

	/*
	 * print src code
	 */ 
	cout << "---- start of src code ----" << endl;
	printNodes(entry);
	cout << "---- end of src code ---" << endl;

}

void Graph::transform() {
	
}

void Graph::runTest() {
	testGraph(entry);
}

INode* Graph::getEntry() {
	return entry;
}


// private
void Graph::initANode(AssignNode* target, int label, string vname, Arithmetic* var, INode* nextNode) {
	target->setLabel(label);
	target->setValue(vname, var);
	target->setNext(nextNode);
}

void Graph::initBNode(BranchNode* target, int label, ImpBool* direction, INode* tNode, INode* fNode) {
	target->setLabel(label);
	target->setDirect(direction);
	target->setNext(tNode, fNode);
}

void Graph::testGraph(INode* node) {
	// if (node->getLabel() > 6) return; 
	if (node == NULL) return;
	node->runCode();
	testGraph(node->getNext());
}

void Graph::printNodes(INode* node) {
	if(node == NULL) return;	
	printNodes(node->printAndSkip());
	
}