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
	//セットでまとめられないため一時的処置		
	AssignNode XA, YB, Z0, ZZX, ZZY, ZZY2;
	BranchNode X10, Z20;
	FuncNode print;

	/*
	 * init Nodes
	 */ 
	XA.setLabel(1);
	YB.setLabel(2);
	Z0.setLabel(3);
	X10.setLabel(4);
	ZZX.setLabel(5);
	ZZY.setLabel(6);
	Z20.setLabel(7);
	ZZY2.setLabel(8);
	print.setLabel(9);

	/*
	 * set variables
	 */ 
	// XA
	Aconst* A = new Aconst(Ainit);
	// YB
	Aconst* B = new Aconst(Binit);
	// Z0
	Aconst* r3 = new Aconst(Zinit);
	// X10
	Avar* l4 = new Avar("X", Ainit);
	Bless* X4 = new Bless(l4, 10);
	// ZZX
	Avar* lplus5 = new Avar("Z", 0);
	Avar* rplus5 = new Avar("X", Ainit);
	Aplus* r5 = new Aplus(lplus5, rplus5);
	// ZZY
	Avar* lplus6 = new Avar("Z", 0);
	Avar* rplus6 = new Avar("Y", Binit);
	Aplus* r6 = new Aplus(lplus6, rplus6);

	initANode(&XA, 1, "X", A, &YB);
	initANode(&YB, 2, "Y", B, &Z0);
	initANode(&Z0, 3, "Z", r3, &X10);
	initBNode(&X10, 4, X4, &ZZX, &ZZY);
	initANode(&ZZX, 5, "Z", r5, &ZZY);
	initANode(&ZZY, 6, "Z", r6, &Z20);

	print.setNext(NULL);
	/*
	 * setNodes to init graph
	 */ 
	AssignNode assignNodes[aLength] = {XA, YB, Z0, ZZX, ZZY, ZZY2};
	BranchNode branchNodes[bLength] = {X10, Z20};
	FuncNode funcNodes[fLength] = {print};
 	setNodes(assignNodes, branchNodes, funcNodes);
	entry = &nodes.aNodes[0];
	exit = &nodes.fNodes[0];


	printNodes(entry);
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

void Graph::setNodes(AssignNode* assignNodes, BranchNode* branchNodes, FuncNode* funcNodes) {
	for (int i = 0; i < aLength; i++) {
		nodes.aNodes[i] = assignNodes[i];
	}
	for (int i = 0; i < bLength; i++) {
		nodes.bNodes[i] = branchNodes[i];
	}
	for (int i = 0; i < fLength; ++i) {
		nodes.fNodes[i] = funcNodes[i];
	}
	
	return;
}	

void Graph::printNodes(INode* node) {
	if(node->getLabel() > 6) return;
	printNodes(node->printAndSkip());
}