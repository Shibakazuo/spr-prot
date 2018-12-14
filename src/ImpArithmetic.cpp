#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ImpArithmetic.h"

using namespace std;

// Avar
int Avar::getValue() {
	return value;
}

void Avar::setValue(int res) {
	value = res;
}

// Aplus 
Avar Aplus::getValue() {
	return value;
}

Aplus::Aplus(Avar l, Avar r) {
	left = l;
	right = r;
	int result = left.getValue() + right.getValue();
	value.setValue(result);
}

// Amult
Avar Amult::getValue() {
	return value;
}

Amult::Amult(Avar l, Avar r) {
	left = l;
	right = r;
	int result = left.getValue() * right.getValue();
	value.setValue(result);
}