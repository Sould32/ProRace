//============================================================================
// Name        : TestPTApp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {

	vector <int> v1;

	v1.push_back(1);
	v1.push_back(2);\
	v1.at(0);
	v1.erase(v1.begin()  + 0);

	list <int> l;
	l.push_back(5);
	l.push_back(6);
	l.push_back(7);

	l.front();

	l.remove(0);
	//cout << << endl;



	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
