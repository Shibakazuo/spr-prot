#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;


class Graph {
public:
	Graph();
	~Graph() { };
	void SrcGraphInit();
	void RunTest();
private:
	set<Node*> nodes;
	Environment input;
	Node* entry;
	Node* exit;
};