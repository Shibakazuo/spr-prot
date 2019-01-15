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

// Bequal
void Beuqal::setDirect(Arithmetic* l, int r) {
	right = r;
	left = l;
	direct = left->getValue() == right ? true : false;
}

bool Beuqal::getDirect() {
	return direct;
}

string Beuqal::getCode() {
	return left->getCode() + " == " + to_string(right);
}

void Beuqal::resetDirect() {
	direct = left->getValue() == right ? true : false;
}

Arithmetic* Beuqal::getAvar() {
	return left;
}




