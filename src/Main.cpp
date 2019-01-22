#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Graph.h"

using namespace std;

int main() {
	Graph src, test;
	ProgState progStat;
	src.srcGraphInit();
	progStat.initStat();
	test = src;
	test.runTest();
    return 0;
}