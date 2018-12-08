#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class ImpFunc
{
public:
	virtual void exec();

	virtual ~ImpFunc() { };

}

class Skip : public ImpFunc {

public:
	virtual void exec() {
		cout << "passed";
	}

	virtual ~Skip() { }
}