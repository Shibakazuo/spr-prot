#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ImpBool.h"

using namespace std;

//Bless 
Bless::Bless(Arithmetic* l, int r) {
	right = r;
	left = l;
	direct = left->getValue() < right ? true : false;
}

void Bless::setDirect(Arithmetic* l, int r) {
	right = r;
	left = l;
	direct = left->getValue() < right ? true : false;
}

bool Bless::getDirect() {
	return direct;
}

string Bless::getCode() {
	return left->getCode() + " < " + to_string(right);
}

void Bless::resetDirect() {
	direct = left->getValue() < right ? true : false;
}

Arithmetic* Bless::getAvar() {
	return left;
}


// Bequal
Bequal::Bequal(Arithmetic* l, int r) {
	right = r;
	left = l;
	direct = left->getValue() == right ? true : false;
}

void Bequal::setDirect(Arithmetic* l, int r) {
	right = r;
	left = l;
	direct = left->getValue() == right ? true : false;
}

bool Bequal::getDirect() {
	return direct;
}

string Bequal::getCode() {
	return left->getCode() + " == " + to_string(right);
}

void Bequal::resetDirect() {
	direct = left->getValue() == right ? true : false;
}

Arithmetic* Bequal::getAvar() {
	return left;
}


// Bnoteq
Bnoteq::Bnoteq(Arithmetic* l, int r) {
	right = r;
	left = l;
	direct = left->getValue() != right ? true : false;
}

void Bnoteq::setDirect(Arithmetic* l, int r) {
	right = r;
	left = l;
	direct = left->getValue() != right ? true : false;
}

bool Bnoteq::getDirect() {
	return direct;
}

string Bnoteq::getCode() {
	return left->getCode() + " != " + to_string(right);
}

void Bnoteq::resetDirect() {
	direct = left->getValue() != right ? true : false;
}

Arithmetic* Bnoteq::getAvar() {
	return left;
}


// Band
Band::Band(ImpBool* l, ImpBool* r) {
	right = r;
	left = l;
	direct = right->getDirect() && left->getDirect();
}

void Band::setDirect(Arithmetic* l, int r) {
	cout << "error: cannot set Avar on Band" << endl;
	exit(1);
}

bool Band::getDirect() {
	return direct;
}

string Band::getCode() {
	return left->getCode() + "&&" + right->getCode();
}

Arithmetic* Band::getAvar() {
	cout << "error: cannot get Avar from Band" << endl;
	exit(1);
}

void Band::resetDirect() {
	direct = right->getDirect() && left->getDirect();
}

// Bor
Bor::Bor(ImpBool* l, ImpBool* r) {
	right = r;
	left = l;
	direct = right->getDirect() || left->getDirect();
}

void Bor::setDirect(Arithmetic* l, int r) {
	cout << "error: cannot set Avar on Bor" << endl;
	exit(1);
}

bool Bor::getDirect() {
	return direct;
}

string Bor::getCode() {
	return left->getCode() + "||" + right->getCode();
}

Arithmetic* Bor::getAvar() {
	cout << "error: cannot get Avar from Bor" << endl;
	exit(1);
}

void Bor::resetDirect() {
	direct = right->getDirect() || left->getDirect();
}









