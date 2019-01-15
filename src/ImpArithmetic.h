#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Arithmetic {
public: 
	virtual int getValue() = 0;
	virtual string getCode() = 0;
	virtual void setResult(int res) = 0;
	virtual void setValue(Arithmetic* l, Arithmetic* r) = 0; 
	virtual bool isVarOrConst() = 0;
	virtual ~Arithmetic() { }
};

class Avar : public Arithmetic {
public: 
	virtual int getValue();
	virtual string getCode();
	virtual void setResult(int res);
	virtual ~Avar() { }
	// should be error
	virtual void setValue(Arithmetic* l, Arithmetic* r) { };
	virtual bool isVarOrConst();
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
	virtual void setValue(Arithmetic* l, Arithmetic* r);
	Aplus(Arithmetic* l, Arithmetic* r); 
private: 
	Arithmetic* left;
	Arithmetic* right;
	int value;
};

class Amult : public Arithmetic {
public: 
	virtual int getValue();
	virtual string getCode();
	virtual void setResult(int res);
	virtual ~Amult() { }
	virtual bool isVarOrConst();
	virtual void setValue(Arithmetic* l, Arithmetic* r);
	Amult(Arithmetic* l, Arithmetic* r);
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
	// should be error
	virtual void setValue(Arithmetic* l, Arithmetic* r) { };
	virtual ~Aconst() { }
	Aconst(int val);
private: 
	int value;
};