#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Graph.h"

using namespace std;

// void printNodes(INode* node) {
// 	cout << node->getLabel();
// 	cout << " x:" << node->getEnv().x << " y:" << node->getEnv().y << " z:" << node->getEnv().z << endl;
// 	if (node->getNext() == NULL) return;
// 	printNodes(node->getNext());
	
// }

int main() {
	Graph* test = new Graph();
	test->srcGraphInit();
	// cout << test->entry->getNext()->getNext()->getNext()->getLabel() << endl;
	// printNodes(test->entry);
    return 0;
}