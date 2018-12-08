#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"

using namespace std;


int main()
{
    Node *end;
    Node* head = new Node();

    head->setValue(1);
    Node *newNode = new Node();
    head->setNext(newNode);

    cout << head->getValue() << endl; 
    return 0;
}