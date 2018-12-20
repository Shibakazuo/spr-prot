#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h" 
#include "Graph.h"

using namespace std;

Graph::Graph() {
	entry = NULL;
	exit = NULL;
}

void Graph::SrcGraphInit() {
	AssignNode* XA = new AssignNode();
	AssignNode* YB = new AssignNode();
	AssignNode* Z0 = new AssignNode();
	BranchNode* X10 = new BranchNode();
	AssignNode* ZZX = new AssignNode();
	AssignNode* ZZY = new AssignNode();
	BranchNode* Z20 = new BranchNode();
	AssignNode* ZZY2 = new AssignNode();
	FuncNode* print = new FuncNode();

	nodes.insert(XA);
	nodes.insert(YB);
	nodes.insert(Z0);
	nodes.insert(X10);
	nodes.insert(ZZX);
	nodes.insert(ZZY);
	nodes.insert(Z20);
	nodes.insert(ZZY2);
	nodes.insert(print);

	XA->setNext(YB);
	XA->setEnv(7, 3, 0);
	YB->setNext(Z0);
	Z0->setNext(X10);
	X10->setNext(ZZX, ZZY);
	ZZX->setNext(ZZY);
	ZZY->setNext(Z20);
	Z20->setNext(ZZY2, print);

} 