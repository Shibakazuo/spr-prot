#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ImpArithmetic.h"

using namespace std;

class ImpBool {
public: 
	virtual bool getDirect() = 0;
	virtual string getCode() = 0;
	virtual ~ImpBool() { }
};

class Bcomp : ImpBool {
public:
	virtual bool getDirect();
	virtual string getCode();
	virtual ~Bcomp() { }
	void setDirect(Arithmetic* l, Arithmetic* r);
private:
	Arithmetic* left;
	Arithmetic* right;
	bool direct; 
};


