#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Arithmetic {
public: 
	virtual int getValue() = 0;
	virtual string getCode() = 0;
	virtual ~Arithmetic() { }
};

class Avar : public Arithmetic {
public: 
	virtual int getValue();
	virtual string getCode();
	virtual ~Avar() { }
	Avar(string vname, int val);
	void setValue(string vname, int val); 
private: 
	int value;
	string varName;
};

// 単純な計算式のみを仮定するためフィールドの型はintのまま
class Aplus : public Arithmetic {
public: 
	virtual int getValue();
	virtual string getCode();
	virtual ~Aplus() { }
	Aplus(Arithmetic* l, Arithmetic* r); 
	void setValue(Arithmetic* l, Arithmetic* r);
private: 
	Arithmetic* left;
	Arithmetic* right;
	int value;
};

class Amult : public Arithmetic {
public: 
	virtual int getValue();
	virtual string getCode();
	virtual ~Amult() { }
	Amult(Arithmetic* l, Arithmetic* r);
	void setValue(Arithmetic* l, Arithmetic* r);
private: 
	Arithmetic* left;
	Arithmetic* right;
	int value;
};

class Aconst : public Arithmetic {
public: 
	virtual int getValue();
	virtual string getCode();
	virtual ~Aconst() { }
	Aconst(int val);
	void setValue(int val);
private: 
	int value;
};