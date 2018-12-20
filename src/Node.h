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

class INode {
public: 
	virtual ~INode() { }
	virtual Environment getEnv() = 0;
	virtual void setEnv(int x, int y, int z) = 0;
	virtual void setLabel(int num) = 0;
	virtual int getLabel() = 0;
};


class AssignNode : public INode {
public:
	AssignNode();
	AssignNode(int num);
	virtual ~AssignNode() { }
	virtual Environment getEnv();
	virtual void setEnv(int x, int y, int z);
	virtual int getLabel();
	virtual void setLabel(int num);
	INode* getNext();
	void setNext(INode* next);
private:
	INode* nextNode;
	Environment env;
	int label;
};


class BranchNode : public INode {
public: 
	BranchNode(); 
	BranchNode(int num);
	virtual ~BranchNode() { }
	virtual Environment getEnv();
	virtual void setEnv(int x, int y, int z);
	virtual void setLabel(int num);
	virtual int getLabel();
	INode* getTrue();
	INode* getFalse();
	void setNext(INode* tNode, INode* fNode);
private:
	INode* trueNode;
	INode* falseNode;
	Environment env;
	int label;
};

class FuncNode: public INode {
public:
	FuncNode();
	FuncNode(int num);
	virtual ~FuncNode() { }
	virtual Environment getEnv();
	virtual void setEnv(int x, int y, int z);
	virtual void setLabel(int num);
	virtual int getLabel();
	void skip();
	void printEnv();
	INode* getNext();
	void setNext(INode* next);
private:
	INode* nextNode;
	Environment env;
	int label;
};


