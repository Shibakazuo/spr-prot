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
	vector<int>	expectedOutput;
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

private:
// stand for <l, σ1, σ2, I, O, D1, D2, R1, R2, S1, S2> in SPR paper
	int currentLabel;
	Environment env1;
	Environment env2;
	NegT negTestCase;
	PosT posTestCase;
	vector<bool> futureAbstcond;
	vector<bool> recAbstcond;
	vector<Environment> recEnv;
};