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
	virtual void setDirect(Arithmetic* l, int r) = 0;
	virtual ~ImpBool() { }
};

// 今回は左辺変数右辺定数で設定するため,Band以外の右辺はintにする
class Bless : public ImpBool {
public:
	virtual ~Bless() { }
	virtual bool getDirect();
	virtual string getCode();
	virtual void resetDirect();
	virtual Arithmetic* getAvar();
	virtual void setDirect(Arithmetic* l, int r);
	Bless(Arithmetic* l, int r);
private:
	Arithmetic* left;
	int right;
	bool direct; 
};

class Bequal : public ImpBool {
public:
	virtual ~Bequal() { };
	virtual bool getDirect();
	virtual string getCode();
	virtual Arithmetic* getAvar();
	virtual void resetDirect();
	virtual void setDirect(Arithmetic* l, int r);
	Bequal(Arithmetic* l, int r);
private:
	Arithmetic* left;
	int right;
	bool direct; 
};

class Bnoteq : public ImpBool {
public: 
	virtual ~Bnoteq() { }
	virtual bool getDirect();
	virtual string getCode();
	virtual Arithmetic* getAvar();
	virtual void resetDirect();
	virtual void setDirect(Arithmetic* l, int r);
	Bnoteq(Arithmetic* l, int r);
private: 
	Arithmetic* left;
	int right;
	bool direct; 
};

class Band : public ImpBool {
public: 
	virtual ~Band() { }
	virtual bool getDirect();
	virtual string getCode();
	virtual Arithmetic* getAvar();
	virtual void resetDirect();
	virtual void setDirect(Arithmetic* l, int r);
	Band(ImpBool* l, ImpBool* r);
private:
	ImpBool* left;
	ImpBool* right;
	bool direct;
};

class Bor : public ImpBool {
public: 
	virtual ~Bor() { }
	virtual bool getDirect();
	virtual string getCode();
	virtual Arithmetic* getAvar();
	virtual void resetDirect();
	virtual void setDirect(Arithmetic* l, int r);
	Bor(ImpBool* l, ImpBool* r);
private:
	ImpBool* left;
	ImpBool* right;
	bool direct;
};
