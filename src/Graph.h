#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include "Node.h"

const int aLength = 6;
const int bLength = 2;
const int fLength = 1;
const int Ainit = 11;
const int Binit = 3;
const int Zinit = 0;

using namespace std;

struct InitNodes {
	AssignNode aNodes[aLength];
	BranchNode bNodes[bLength];
	FuncNode fNodes[fLength];
};

class Graph {
public:
	Graph();
	~Graph() { };
	void srcGraphInit();
	void runTest();
private: 
	InitNodes nodes;
	Environment input;
	INode* entry;
	INode* exit;
	void initANode(AssignNode* target, int label, string vname, Arithmetic* var, INode* nextNode);
	void initBNode(BranchNode* target, int label, ImpBool* direction, INode* tNode, INode* fNode);
	void setNodes(AssignNode* assignNodes, BranchNode* branchNodes, FuncNode* funcNodes);
	void printNodes(INode* node);
	void testGraph(INode* node);
};