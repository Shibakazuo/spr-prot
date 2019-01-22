#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <typeinfo>
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
	env.student = x;
	env.teacher = y;
	env.sum = z;
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
		string vlname = variable->getLeft()->getCode();
		string vrname = variable->getRight()->getCode();
		if (getSelectedEnv(variable->getRight()->getCode()) == -1) {
			variable->getLeft()->setResult(getSelectedEnv(vlname));
			variable->recalc();
		} else {
			variable->getLeft()->setResult(getSelectedEnv(vlname));
			variable->getRight()->setResult(getSelectedEnv(vrname));
			variable->recalc();
		}	
	}

	if (varName == "student") {
		setEnv(variable->getValue(), env.teacher, env.sum);
	} else if (varName == "teacher") {
		setEnv(env.student, variable->getValue(), env.sum);
	} else {
		setEnv(env.student, env.teacher, variable->getValue()); 
	}

	if (nextNode != NULL) {
		nextNode->setEnv(env.student, env.teacher, env.sum);	
	}

	cout << label << " student = " << env.student << " teacher = " << env.teacher << " sum = " << env.sum << endl; 
}

int AssignNode::getSelectedEnv(string name) {
	if (name == "student") {
		return env.student;
	} else if (name == "teacher") {
		return env.teacher;
	} else if (name == "sum"){
		return env.sum;
	} else {
		return -1;
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
	env.student = x;
	env.teacher = y;
	env.sum = z;
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
	if (direct->getAvar()->getCode() == "student") {
		// cout << "pass" << endl;
		direct->getAvar()->setResult(env.student);
		direct->resetDirect();
	} else if (direct->getAvar()->getCode() == "teacher") {
		direct->getAvar()->setResult(env.teacher);
		direct->resetDirect();
	} else {
		direct->getAvar()->setResult(env.sum);
		direct->resetDirect();
	}

	if (getNext() != NULL) {
		getNext()->setEnv(env.student, env.teacher, env.sum);	
	}
	cout << label << " if " << getCode() << " : student = " << env.student << " teacher = " << env.teacher <<  " sum = " << env.sum << endl; 
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
	env.student = x;
	env.teacher = y;
	env.sum = z;
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
	cout << env.student << " " << env.teacher << " " << env.sum << endl; 
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
