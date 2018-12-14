#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class ImpArithmetic {
public: 
	virtual ~ImpArithmetic() { }
};

class Avar : public ImpArithmetic {
public: 
	int getValue();
	void setValue(int val); 
	virtual ~Avar() { }

private: 
	int value;
};

class Aplus : public ImpArithmetic {
public: 
	Avar getValue();
	virtual ~Aplus() { }
	Aplus(Avar l, Avar r);


private: 
	Avar left;
	Avar right;
	Avar value;
};

class Amult : public ImpArithmetic {
public: 
	Avar getValue();
	virtual ~Amult() { }
	Amult(Avar left, Avar right);

private: 
	Avar left;
	Avar right;
	Avar value;
};