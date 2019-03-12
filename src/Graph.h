#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include "ProgState.h"

const int aLength = 6;
const int bLength = 2;
const int fLength = 1;
const int Ainit = 1;
const int Binit = 1;
const int teacherNum = 10;
const int studentNum = 100;

using namespace std;

struct InitNodes {
	AssignNode aNodes[20];
	BranchNode bNodes[10];
	FuncNode fNodes[10];
};

struct AbstConds {
	BranchNode nodes[10];
};

class Graph {
public:
	Graph();
	~Graph() { };
	void srcGraphInit();
	void runTest();
	void runTestWithInputs(int studentInput, int teacherInput);
	INode* getEntry();
	int getOutput();
	
private: 
	InitNodes nodes;
	AbstConds abstConds;
	Environment input;
	INode* entry;
	INode* exit;
	void initANode(AssignNode* target, int label, string vname, Arithmetic* var, INode* nextNode);
	void initBNode(BranchNode* target, int label, ImpBool* direction, INode* tNode, INode* fNode);
	void printNodes(INode* node);
	void testGraph(INode* node);
};