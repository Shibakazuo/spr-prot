#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>

using namespace std;

struct InitNodes {
	AssignNode aNodes[7];
	BranchNode bNodes[2];
};

class Graph {
public:
	Graph();
	~Graph() { };
	void srcGraphInit();
	void RunTest();
	InitNodes nodes;
	Environment input;
	INode* entry;
	INode* exit;
};