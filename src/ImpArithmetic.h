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
	Avar plus(Avar left, Avar right);


private: 
	Avar left;
	Avar right;
	Avar value;
}

class Amult : public ImpArithmetic {
public: 
	virtual Avar getValue();
	virtual ~Amult() { }
	Avar mult(Avar left, Avar right);

private: 
	Avar left;
	Avar right;
	Avar value;
}