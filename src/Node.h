#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ImpBool.h"

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
	virtual INode* getNext() = 0;
	virtual string getCode() = 0;
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
	virtual INode* getNext();
	virtual string getCode();
	void setValue(string vname, Arithmetic* var);
	void setNext(INode* next);
private:
	INode* nextNode;
	Environment env;
	int label;
	string varName;
	Arithmetic* variable;
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
	virtual INode* getNext();
	virtual string getCode();
	void setDirect(bool di);
	void setNext(INode* tNode, INode* fNode);
private:
	INode* trueNode;
	INode* falseNode;
	Environment env;
	bool direct;
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
	virtual string getCode();
	void skip();
	void printEnv();
	virtual INode* getNext();
	void setNext(INode* next);
private:
	INode* nextNode;
	Environment env;
	int label;
};


