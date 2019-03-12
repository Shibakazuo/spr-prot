#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "CondSynthesizer.h"

using namespace std;

void CondSynthesizer::condSynthesize(Graph* target, ProgState* progStat) {
	NegT negTestCase = progStat->getNegT();
	PosT posTestCase = progStat->getPosT();
	runExec(target, negTestCase.studentInput, negTestCase.teacherInput)
}

// Exec(<p,n>, I, ε, ε)
void CondSynthesizer::runExec(Graph* target, Vector<int> studentInput, Vector<int> teacherInput) {
	target->runTestWithInput(studentInput, teacherInput);

} 