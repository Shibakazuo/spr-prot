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

void Graph::srcGraphInit() {
	AssignNode* XA = new AssignNode();
	AssignNode* YB = new AssignNode();
	AssignNode* Z0 = new AssignNode();
	BranchNode* X10 = new BranchNode();
	AssignNode* ZZX = new AssignNode();
	AssignNode* ZZY = new AssignNode();
	BranchNode* Z20 = new BranchNode();
	AssignNode* ZZY2 = new AssignNode();
	FuncNode* print = new FuncNode();

	XA->setLabel(1);
	YB->setLabel(2);
	Z0->setLabel(3);
	X10->setLabel(4);
	ZZX->setLabel(5);
	ZZY->setLabel(6);
	Z20->setLabel(7);
	ZZY2->setLabel(8);
	print->setLabel(9);

	XA->setEnv(7, 3, 0);
	YB->setEnv(2, 3, 0);
	Z0->setEnv(2, 3, 0);
	X10->setEnv(3, 9, 20);
	ZZX->setEnv(2, 3, 0);
	Z20->setEnv(7, 3, 21);
	// Boolクラスを書き終わるまでの一時的処置
	X10->setDirect(X10->getEnv().x < 10 ? true : false);
	Z20->setDirect(Z20->getEnv().z < 20 ? true : false);

	XA->setNext(YB);
	YB->setNext(Z0);
	Z0->setNext(X10);
	X10->setNext(ZZX, ZZY);
	ZZX->setNext(ZZY);
	ZZY->setNext(Z20);
	Z20->setNext(ZZY2, print);
	ZZY2->setNext(Z20);

	nodes.insert(XA);
	nodes.insert(YB);
	nodes.insert(Z0);
	nodes.insert(X10);
	nodes.insert(ZZX);
	nodes.insert(ZZY);
	nodes.insert(Z20);
	nodes.insert(ZZY2);
	nodes.insert(print);

	entry = XA;
	exit = print;

} 