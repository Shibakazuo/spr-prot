#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"

using namespace std;


void printEnv (Node* node) {
	cout << node->getEnv().x << " " << node->getEnv().y << " " << node->getEnv().z << endl; 
}

int main() {
    AssignNode* head = new AssignNode();

    head->setEnv(1, 0, 1);
    printEnv(head);
    
    return 0;
}