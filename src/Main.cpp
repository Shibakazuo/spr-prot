#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Graph.h"

using namespace std;

int main() {
	Graph src, test;
	src.srcGraphInit();
	test = src;
	test.runTest();
    return 0;
}