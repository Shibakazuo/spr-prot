#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
const int aLength = 6;
const int bLength = 2;
const int fLength = 1;

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
	void RunTest();
private: 
	InitNodes nodes;
	Environment input;
	INode* entry;
	INode* exit;
	void setNodes(AssignNode* assignNodes, BranchNode* branchNodes, FuncNode* funcNodes);
};