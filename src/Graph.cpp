#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include "Node.h" 
#include "Graph.h"

using namespace std;

void SrcGraphInit() {
	AssignNode XA = new AssignNode();
	AssignNode YB = new AssignNode();
	AssignNode Z0 = new AssignNode();
	BranchNode X10 = new BranchNode();
	AssignNode ZZX = new AssignNode();
	AssignNode ZZY = new AssignNode();
	BranchNode Z20 = new BranchNode();
	AssignNode ZZY2 = new AssignNode();

	XA.setNext(YB);
	XA.setLabel(1);
	XA.setEnv(7, 3, 0);
	YB.setNext(Z0);
	YB.setLabel(2);
	Z0.setNext(X10);
	Z0.setLabel(3);
	X10.setNext(ZZX)
} 