#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ImpArithmetic.h"

using namespace std;

// コード出力：Avarは'変数名'、Aplusは'変数名＋定数'or'定数＋定数'、Amultは'変数名＋定数'or'定数＋定数',Aconstは'定数'

// Avar
Avar::Avar(string vname, int val) {
	value = val;
	varName = vname;
}

int Avar::getValue() {
	return value;
}

void Avar::setValue(string vname, int val) {
	value = val;
	varName = vname;
}

void Avar::setResult(int res) {
	value = res;
}

string Avar::getCode() {
	return varName;
}

bool Avar::isVarOrConst() {
	return true;
}


// Aplus
Aplus::Aplus(Arithmetic* l, Arithmetic* r) {
	left = l;
	right = r;
	value = left->getValue() + right->getValue();
} 

int Aplus::getValue() {
	return value;
}

void Aplus::setValue(Arithmetic* l, Arithmetic* r) {
	left = l;
	right = r;
	value = left->getValue() + right->getValue();
}

string Aplus::getCode() {
	return left->getCode() + " + " + right->getCode();
}

void Aplus::setResult(int res) {
	value = res;
}

bool Aplus::isVarOrConst() {
	return false;
}

// Amult
Amult::Amult(Arithmetic* l, Arithmetic* r) {
	left = l;
	right = r;
	value = left->getValue() * right->getValue();
}

int Amult::getValue() {
	return value;
}

void Amult::setValue(Arithmetic* l, Arithmetic* r) {
	left = l;
	right = r;
	value = left->getValue() * right->getValue();
}

string Amult::getCode() {
	return left->getCode() + " * " + right->getCode();
}

void Amult::setResult(int res) {
	value = res;
}

bool Amult::isVarOrConst() {
	return false;
}


// const
Aconst::Aconst(int val) {
	value = val;
} 

int Aconst::getValue() {
	return value;
}

string Aconst::getCode() {
	return to_string(value);
}

void Aconst::setResult(int res) {
	value = res;
}

bool Aconst::isVarOrConst() {
	return true;
}
