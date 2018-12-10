#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"

using namespace std;

Node::Node() {
	next = NULL;
}

Node::Node(const Node& node) {
	next = node.next;
	value = node.value;

}

Node* Node::getNext() {
	return next;
}

int Node::getValue() {
	return value;
}

void Node::setValue(int val) {
	 value = val; 
}

void Node::setNext(Node* nextNode) {
	if(nextNode == NULL) {
		next = NULL;
	} else {
		next = nextNode;
	}
}


