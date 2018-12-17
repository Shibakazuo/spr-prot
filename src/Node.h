#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Environment {
	int x;
	int y;
	int z;
};

class Node {
public: 
	virtual ~Node() { }
	virtual Environment getEnv() = 0;
	virtual void setEnv(int x, int y, int z) = 0;
	virtual void setNext(Node* nextNode) = 0;
	virtual void setLabel(int label) = 0;
};

class AssignNode : public Node {
public:
	AssignNode();
	virtual ~AssignNode() { }
	virtual Environment getEnv();
	virtual void setEnv(int x, int y, int z);
	virtual void setNext(Node* nextNode);
	virtual void setLabel(int label);
private:
	Environment env;
	int label;
	Node* next;
};

class BranchNode : public Node {
public: 
	BranchNode(); 
	virtual ~BranchNode() { }
	virtual Environment getEnv();
	virtual void setEnv(int x, int y, int z);
	virtual void setNext(Node* nextNode);
	virtual void setLabel(int label);
private:
	Environment env;
	int label;
	Node* trueNode;
	Node* falseNode;
};



