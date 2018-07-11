#include<iostream>
#include<fstream>
#include"stack_test.h"
using namespace std;
#pragma comment(linker, "/STACK:1048576,1048576")
int main(int argv, char* argc[])
{
	int n;
	cout << "Please input an integer of 1,2,3,-1,-2,-3 as the mode" << endl;
	cin >> n;
	
	stack_test test(n);
	test.control();
	test.mode = 0 - n;
	test.control();
	return 0;
}