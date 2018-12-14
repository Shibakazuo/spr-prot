#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Node {
public: 
	Node();
	Node(const Node& node);
	virtual ~Node() { }
	Node* getNext();
	int getValue();
	void setNext(Node* nextNode);
	void setValue(int val);

private:
	Node* next;
	int value;
};

// class FunctionNode : public Node {
// public:
	
// }



