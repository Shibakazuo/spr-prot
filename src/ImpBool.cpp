#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ImpBool.h"

using namespace std;

Bless::Bless(Arithmetic* l, int r) {
	right = r;
	left = l;
	direct = left->getValue() < right ? true : false;
}

void Bless::setDirect(Arithmetic* l, int r) {
	right = r;
	left = l;
	direct = left->getValue() < right ? true : false;
}

// Bless::Bless(Arithmetic* l, Arithmetic* r) {
// 	right = l;
// 	left = r;
// 	direct = left->getValue() > right->getValue() ? true : false;
// }

// void Bless::setDirect(Arithmetic* l, Arithmetic* r) {
// 	right = l;
// 	left = r;
// 	direct = left->getValue() > right->getValue() ? true : false;
// }

bool Bless::getDirect() {
	return direct;
}

string Bless::getCode() {
	return left->getCode() + " < " + to_string(right);
}

void Bless::resetDirect() {
	direct = left->getValue() < right ? true : false;
}

Arithmetic* Bless::getAvar() {
	return left;
}