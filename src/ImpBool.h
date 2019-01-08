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

class Bless : public ImpBool {
public:
	virtual bool getDirect();
	virtual string getCode();
	virtual ~Bless() { }
	Bless(Arithmetic* l, int r);
	void setDirect(Arithmetic* l, int r);
	// Bless(Arithmetic* l, Arithmetic* r);
	// void setDirect(Arithmetic* l, Arithmetic* r);
private:
	Arithmetic* left;
	int right;
	// Arithmetic* right;
	bool direct; 
};


