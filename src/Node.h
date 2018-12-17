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
	virtual void setLabel(int num) = 0;
};

class AssignNode : public Node {
public:
	AssignNode();
	virtual ~AssignNode() { }
	virtual Environment getEnv();
	virtual void setEnv(int x, int y, int z);
	virtual void setLabel(int num);
	void setNext(Node* next);
private:
	Environment env;
	int label;
	Node* nextNode;
};

class BranchNode : public Node {
public: 
	BranchNode(); 
	virtual ~BranchNode() { }
	virtual Environment getEnv();
	virtual void setEnv(int x, int y, int z);
	virtual void setLabel(int num);
	void setNext(Node* tNode, Node* fNode);
private:
	Environment env;
	int label;
	Node* trueNode;
	Node* falseNode;
};



