#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include "ProgState.h"

using namespace std;

void ProgState::initStat() {
	int studentInput[4] = {0, 1, 0, 1};
	int teacherInput[4] = {1, 0, 0, 1};
	int sumOutput[4] = {110, 110, 110, 110};
	int exOutput[3] = {10, 100, 0};

	for (int i = 0; i < 3; i++) {
		negTestCase.studentInput.push_back(studentInput[i]);
		negTestCase.teacherInput.push_back(teacherInput[i]);
		negTestCase.sumOutput.push_back(sumOutput[i]);
		negTestCase.expectedOutput.push_back(exOutput[i]);
	}
	
	posTestCase.studentInput.push_back(studentInput[3]);
	posTestCase.teacherInput.push_back(teacherInput[3]);
	posTestCase.sumOutput.push_back(sumOutput[3]);

}	