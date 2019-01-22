#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Function.h>

using namespace std;

class Arithmetic {
public: 
	virtual int getValue() = 0;
	virtual string getCode() = 0;
	virtual void setResult(int res) = 0;
	virtual void recalc() = 0;
	virtual bool isVarOrConst() = 0;
	virtual Arithmetic* getLeft() = 0;
	virtual Arithmetic* getRight() = 0;
	virtual ~Arithmetic() { }
};

class Avar : public Arithmetic {
public: 
	virtual int getValue();
	virtual string getCode();
	virtual void setResult(int res);
	virtual ~Avar() { }
	virtual bool isVarOrConst();
	// error output shouldn't write here
	virtual Arithmetic* getLeft() { Function::pntError(); return NULL; };
	virtual Arithmetic* getRight() { Function::pntError(); return NULL; };
	virtual void recalc() { Function::pntError(); };
	Avar() {};
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
	virtual void setResult(int res);
	virtual ~Aplus() { }
	virtual bool isVarOrConst();
	virtual Arithmetic* getLeft();
	virtual Arithmetic* getRight();
	virtual void recalc();
	Aplus(Arithmetic* l, Arithmetic* r); 
private: 
	Arithmetic* left;
	Arithmetic* right;
	int value;
};

class Aconst : public Arithmetic {
public: 
	virtual int getValue();
	virtual string getCode();
	virtual void setResult(int res);
	virtual bool isVarOrConst();
	virtual ~Aconst() { }
	virtual Arithmetic* getLeft() { Function::pntError(); return NULL; };
	virtual Arithmetic* getRight() { Function::pntError(); return NULL; };
	virtual void recalc() { Function::pntError();};
	Aconst(int val);
private: 
	int value;
};