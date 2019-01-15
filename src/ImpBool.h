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
	virtual Arithmetic* getAvar() = 0;
	virtual void resetDirect() = 0;
	virtual ~ImpBool() { }
};

class Bless : public ImpBool {
public:
	virtual bool getDirect();
	virtual string getCode();
	virtual void resetDirect();
	virtual Arithmetic* getAvar();
	virtual ~Bless() { }
	// 今回は左辺変数右辺定数で設定するためintにする
	Bless(Arithmetic* l, int r);
	void setDirect(Arithmetic* l, int r);
private:
	Arithmetic* left;
	int right;
	bool direct; 
};

class Bequal : public ImpBool {
public:
	virtual bool getDirect();
	virtual string getCode();
	virtual Arithmetic* getAvar();
	virtual void resetDirect();
	virtual ~Band() { };
private:
	Arithmetic* left;
	int right;
	bool direct; 
}

class Bnoteq : public ImpBool {
public: 
	virtual bool getDirect();
	virtual string getCode();
	virtual Arithmetic* getAvar();
	virtual void resetDirect();
	virtual ~Band() { }
private: 
	Arithmetic* left;
	int right;
	bool direct; 
}

class Band : public ImpBool {
public: 
	virtual bool getDirect();
	virtual string getCode();
	virtual Arithmetic* getAvar();
	virtual void resetDirect();
	virtual ~Band() { }
private:
	ImpBool* left;
	ImpBool* right;
	bool direct;
};
