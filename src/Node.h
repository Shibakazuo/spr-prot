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
	int getLabel();
	Node* getNextNode();
private:
	Environment env;
	int label;
	Node* nextNode;
};

class AssignNode : public Node {
public:
	AssignNode();
	AssignNode(int label);
	virtual ~AssignNode() { }
	virtual Environment getEnv();
	virtual void setEnv(int x, int y, int z);
	void setNext(Node* next);
private:
	Environment env;
	int label;
	Node* nextNode;
};

class BranchNode : public Node {
public: 
	BranchNode(); 
	BranchNode(int label);
	virtual ~BranchNode() { }
	virtual Environment getEnv();
	virtual void setEnv(int x, int y, int z);
	void setNext(Node* tNode, Node* fNode);
private:
	Environment env;
	int label;
	Node* trueNode;
	Node* falseNode;
};

class FuncNode: public Node {
public:
	FuncNode();
	FuncNode(int label);
	virtual ~FuncNode() { }
	virtual Environment getEnv();
	virtual void setEnv(int x, int y, int z);
	void skip();
	void printEnv();
	void setNext(Node* next);
private:
	Environment env;
	int label;
	Node* nextNode;
};


