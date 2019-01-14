#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Graph.h"

using namespace std;

int main() {
	Graph src, test;

	src.srcGraphInit();

	cout << src.getEntry()->getNext() << endl;
	cout << src.getEntry()->getNext()->getCode() << endl;
	cout << src.getEntry()->getNext() << endl;
	cout << src.getEntry()->getNext()->getLabel() << endl;
    return 0;
}