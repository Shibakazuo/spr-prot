#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include "Node.h" 

using namespace std;


class Graph {
public:
	~Graph() { };
	void GraphInit();
private:
	set<Node> nodes;
	Node entry;
	Node exit;
}