#include <cstring>
#include <stdio.h>
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
	AssignNode XA, YB, Z0, ZZX, ZZY, ZZY2;
	BranchNode X10, Z20;
	FuncNode print;

	XA.setLabel(1);
	YB.setLabel(2);
	Z0.setLabel(3);
	X10.setLabel(4);
	ZZX.setLabel(5);
	ZZY.setLabel(6);
	Z20.setLabel(7);
	ZZY2.setLabel(8);
	print.setLabel(9);

	XA.setEnv(7, 3, 0);
	YB.setEnv(2, 3, 0);
	Z0.setEnv(2, 3, 0);
	X10.setEnv(3, 9, 20);
	ZZX.setEnv(2, 3, 0);
	Z20.setEnv(7, 3, 21);
	// Boolクラスを書き終わるまでの一時的処置
	X10.setDirect(X10.getEnv().x < 10 ? true : false);
	Z20.setDirect(Z20.getEnv().z < 20 ? true : false);

	XA.setNext(&YB);
	YB.setNext(&Z0);
	Z0.setNext(&X10);
	X10.setNext(&ZZX, &ZZY);
	ZZX.setNext(&ZZY);
	ZZY.setNext(&Z20);
	Z20.setNext(&ZZY2, &print);
	ZZY2.setNext(&Z20);

	nodes.push_back(&XA);
	nodes.push_back(&YB);
	nodes.push_back(&Z0);
	nodes.push_back(&X10);
	nodes.push_back(&ZZX);
	nodes.push_back(&ZZY);
	nodes.push_back(&Z20);
	nodes.push_back(&ZZY2);
	nodes.push_back(&print);


	 entry = &XA;
	 exit = &print;

	cout << entry->getNext()->getLabel() << endl;
	cout << (*nodes.begin())->getLabel() << endl;
} 