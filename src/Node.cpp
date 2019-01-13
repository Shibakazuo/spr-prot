#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"

using namespace std;

// AssignNode
AssignNode::AssignNode() {
	nextNode = NULL;
}

void AssignNode::setLabel(int num) {
	label = num;
}

AssignNode::AssignNode(int label) {
	nextNode = NULL;
	label = label;
}

Environment AssignNode::getEnv() {
	return env;
}

int AssignNode::getLabel() {
	return label;
}

void AssignNode::setEnv(int x, int y, int z) {
	env.x = x;
	env.y = y;
	env.z = z;
}

INode* AssignNode::getNext() {
	return nextNode;
}

void AssignNode::setNext(INode* next) {
	nextNode = next;
}

void AssignNode::setValue(string vname, Arithmetic* var) {
	varName = vname;
	variable = var;
} 

string AssignNode::getCode() {
	return varName + " := " + variable->getCode();
}

INode* AssignNode::printAndSkip() {
	cout << this->getCode() << endl;
	return nextNode;
}

// コード実行、また次のノードがNULLじゃない場合envを渡す
void AssignNode::runCode() { 
	// テスト例では右辺が一つの場合は初期値のみであるため数値を代入する必要がない。	
	if (! variable->isVarOrConst()) {
		// 右辺が引数2つ以上の場合
		string vlname = &variable->getCode().front();
		string vrname = &variable->getCode().back();
		Avar* vleft = new Avar(vlname, getSelectedEnv(vlname));
		Avar* vright = new Avar(vrname, getSelectedEnv(vrname));
		variable->setValue(vleft, vright);
	}

	if (varName == "X") {
		setEnv(variable->getValue(), env.y, env.z);
	} else if (varName == "Y") {
		setEnv(env.x, variable->getValue(), env.z);
	} else {
		setEnv(env.x, env.y, variable->getValue());
	} 	

	if (nextNode != NULL) {
		nextNode->setEnv(env.x, env.y, env.z);	
	}

	cout << label << " x = " << env.x << " y = " << env.y << " z = " << env.z << endl; 
}

int AssignNode::getSelectedEnv(string name) {
	if (name == "X") {
		return env.x;
	} else if (name == "Y") {
		return env.y;
	} else {
		return env.z;
	}
}

// Branchnode
BranchNode::BranchNode() {
	trueNode = NULL;
	falseNode = NULL;
}

Environment BranchNode::getEnv() {
	return env;
}

int BranchNode::getLabel() {
	return label;
}

void BranchNode::setLabel(int num) {
	label = num;
}

void BranchNode::setEnv(int x, int y, int z) {
	env.x = x;
	env.y = y;
	env.z = z;
}

INode* BranchNode::getNext() {
	return direct->getDirect() ? trueNode : falseNode;
}

void BranchNode::setNext(INode* tNode, INode* fNode) {
	trueNode = tNode;
	falseNode = fNode;
}

void BranchNode::setDirect(ImpBool* di) {
	direct = di;
}

string BranchNode::getCode() {
	return direct->getCode();
}

INode* BranchNode::printAndSkip() {
	if (ifWhile(trueNode, label)) {
		cout << "WHILE " + direct->getCode() << endl;
		cout << " " + trueNode->getCode() << endl;
		cout << "END WHILE" << endl;
	} else {
		cout << "IF " + direct->getCode() << endl;
		cout << " " + trueNode->getCode() << endl;
		cout << "END IF" << endl;
	}
	return falseNode;
}

bool BranchNode::ifWhile(INode* node, int label) {
	if (node->getNext()->getLabel() == label) {
		return true;
	}
	return false;
}

void BranchNode::runCode() {
	if (direct->getAvar()->getCode() == "X") {
		// cout << "pass" << endl;
		direct->getAvar()->setResult(env.x);
		direct->resetDirect();
	} else if (direct->getAvar()->getCode() == "Y") {
		direct->getAvar()->setResult(env.y);
		direct->resetDirect();
	} else {
		direct->getAvar()->setResult(env.z);
		direct->resetDirect();
	} 
	if (getNext() != NULL) {
		getNext()->setEnv(env.x, env.y, env.z);	
	}
	cout << label << " " << getCode() << " : x = " << env.x << " y = " << env.y << " z = " << env.z << endl; 
}

// FuncNode
FuncNode::FuncNode() {
	nextNode = NULL;
}

Environment FuncNode::getEnv() {
	return env; 
}

int FuncNode::getLabel() {
	return label;
}

void FuncNode::setEnv (int x, int y, int z) {
	env.x = x;
	env.y = y;
	env.z = z;
} 

void FuncNode::setLabel(int num) {
	label = num;
}

INode* FuncNode::getNext() {
	return nextNode;
}

void FuncNode::setNext(INode* next) {
	nextNode = next;
}

void FuncNode::skip() {
	while (nextNode->getLabel() > label) {
		nextNode = nextNode->getNext();
	}
}

void FuncNode::printEnv() {
	cout << env.x << " " << env.y << " " << env.z << endl; 
}

string FuncNode::getCode() {
	return "a";
}

INode* FuncNode::printAndSkip() {
	cout << "PRINT" << endl; 
	return NULL;
}
void FuncNode::runCode() {
	 printEnv();
}
