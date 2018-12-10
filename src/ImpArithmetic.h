#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class ImpArithmetic {
public: 
	virtual int getValue() = 0;
	virtual ~ImpArithmetic() { }
}

class Avar : public ImpArithmetic {
public: 
	virtual int getValue();
	virtual ~Avalue() {}

private: 
	int value;
}

class APlus : public ImpArithmetic {
public: 
	virtual Avar getValue();
	virtual ~APlus() { }
	Aplus(Avar left, Avar right);


private: 
	Avar left;
	Avar right;
	Avar value;
}

class Amult : public ImpArithmetic {
public: 
	virtual Avar getValue();
	virtual ~Amult() { }
	Amult(Avar left, Avar right);

private: 
	Avar left;
	Avar right;
	Avar value;
}