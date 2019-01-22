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
// stand for <l, σ, I, O, D, R, S> in SPR paper
	int currentLabel;
	Environment currentEnv;
	NegT negTestCase;
	PosT posTestCase;
	vector<bool> futureAbstcond;
	vector<bool> recAbstcond;
	vector<Environment> recEnv;
};