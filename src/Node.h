#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Node {
public: 
	virtual ~Node() { }
	Node* getNext();
	int getValue();
	virtual void setNext(Node* nextNode) = 0;
	void setValue(int val);

private:
	Node* next;
};

class AssignNode : public Node {
public:
	AssignNode();
	virtual ~AssignNode() { }
	virtual void setNext(Node* nextNode);

private: 
	int value;
}

class BranchNode : public Node {
public: 
	BranchNode(); 
	virtual ~BranchNode() { }
	virtual void setNext(Node* nextNode);
}



