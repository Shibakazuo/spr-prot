#include <cstring>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main( ){
	int x, y, z, a, b;

	cin >> a >> b;
	x = a;
	y = b; 
	z = 0;

	if (x < 10) {
		z = z + x; 
	}
	z = z + y;

	while (z < 20) {
		z = z + y; 
	} 

	cout << "x = " << x << " y = " << y << " z = " << z << endl;

	return 0;

}
