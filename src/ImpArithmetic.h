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
	void setValue(int val, string vname); 
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
	void setValue(int val);
private: 
	int value;
};