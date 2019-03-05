#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <vector>
#include "Node.h"

using namespace std;

struct NegT {
	vector<int> studentInput;
	vector<int> teacherInput;
	vector<int> sumOutput;
};

struct PosT {
	vector<int> studentInput;
	vector<int> teacherInput;
	vector<int> sumOutput;
};

class ProgState {
public: 
	~ProgState() { };
	void initStat();
	NegT getNegT();
	PosT getPosT();

private:
// stand for <l, σ1, σ2, I(include NegT and PosT), O, D1, D2, R1, R2, S1, S2> in SPR paper
	int currentLabel;
	Environment env1;
	Environment env2;
	NegT negTestCase;
	PosT posTestCase;
	vector<int> output;
	vector<bool> futureAbstcond1;
	vector<bool> futureAbstcond2;
	vector<bool> recAbstcond1;
	vector<bool> recAbstcond2;
	vector<Environment> recEnv1;
	vector<Environment> recEnv2;
};