#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ImpArithmetic.h"

using namespace std;

// コード出力：Avarは'変数名'、Aplusは'変数名＋定数'or'定数＋定数'、Amultは'変数名＋定数'or'定数＋定数',Aconstは'定数'

// Avar
int Avar::getValue() {
	return value;
}

void Avar::setValue(string vname, int val) {
	value = val;
	varName = vname;
}

string Avar::getCode() {
	return varName;
}

// Aplus 
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

// Amult
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

// const

int Aconst::getValue() {
	return value;
}

void Aconst::setValue(int val) {
	value = val;
} 

string Aconst::getCode() {
	return to_string(value);
}