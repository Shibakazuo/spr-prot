#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>

using namespace std;

class Graph {
public:
	Graph();
	~Graph() { };
	void srcGraphInit();
	void RunTest();
	list<INode*> nodes;
	Environment input;
	INode* entry;
	INode* exit;
};