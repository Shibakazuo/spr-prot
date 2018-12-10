#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ImpArithmetic.h"

using namespace std;

int Avar::getvalue() {
	return value;
}

int Aplus::getvalue() {
	return value;
}

Aplus::Aplus(Avar left, Avar right) {
	result = left + right;
}
