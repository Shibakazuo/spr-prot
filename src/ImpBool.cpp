#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ImpBool.h"

using namespace std;

void Bcomp::setDirect(Arithmetic* l, Arithmetic* r) {
	right = l;
	left = r;
	direct = left->getValue() > right->getValue() ? true : false;
}

bool Bcomp::getDirect() {
	return direct;
}

string Bcomp::getCode() {
	return left->getCode() + " > " + right->getCode();
}