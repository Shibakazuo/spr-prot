#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h" 
#include "Graph.h"

using namespace std;

void SrcGraphInit() {
	AssignNode* XA = new AssignNode(1);
	AssignNode* YB = new AssignNode(2);
	AssignNode* Z0 = new AssignNode(3);
	BranchNode* X10 = new BranchNode(4);
	AssignNode* ZZX = new AssignNode(5);
	AssignNode* ZZY = new AssignNode(6);
	BranchNode* Z20 = new BranchNode(7);
	AssignNode* ZZY2 = new AssignNode(8);
	FuncNode* print = new FuncNode(9);

	XA->setNext(YB);
	XA->setEnv(7, 3, 0);
	YB->setNext(Z0);
	Z0->setNext(X10);
	X10->setNext(ZZX, ZZY);
	ZZX->setNext(ZZY);
	ZZY->setNext(Z20);
	Z20->setNext(ZZY2, print);

} 