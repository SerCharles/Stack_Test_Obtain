#include<iostream>
#include<fstream>
#include<iomanip>
#include<Windows.h>
#include"stack_test.h"
using namespace std;
ofstream out("data_out.txt");
void stack_test::control()
{
	if (mode == 1||mode==-1) swing1();
	if (mode == 2||mode==-2) swing2();
	if (mode == 3 || mode == -3) swing3();
}
void stack_test::swing1()
{
	char k='a';//定义一个1B的变量来获取当前内存地址
	if (num == 0) //第一次执行函数，初始化地址
	{
		start = &k;
		last_end = &k;
		out << "The start place is " << long long(start) << endl;
	}
	else
	{
		if (num > 1)last_end = endline; //
		endline = &k;
		dsum = last_end - endline ; //这个函数的栈内存大小
		sum = double(start - endline)/ 1024 / 1024;  //总共用的栈内存大小
		out << "The " << num << " th set" << endl;
		out << "Present place is " << long long(endline)<<endl;
		out << "The memory for this set is " << dsum  << " B" << endl;
		out << "Having used stack for " << sum << setprecision(2) << " MB" << endl;
		out << "------------------------------------------------" << endl;
	}
	num++;
	moveon(); 
	num--;
	endline = &k;
	sum = double(start - endline) / 1024 / 1024;
	out << "Withdraw to the " << num << " th set" << endl;
	out << "Present place is " << long long(endline) << endl;
	out << "Having used stack for " << sum << setprecision(2) << " MB" << endl;
	out << "------------------------------------------------" << endl;
}
void stack_test::swing2()
{
	int map[1000];
	char k='a';
	if (num == 0)
	{
		start = &k;
		last_end = &k;
		out << "The start place is " << long long(start) << endl;
	}
	else
	{
		if (num > 1)last_end = endline;
		endline = &k;
		dsum = last_end - endline ;
		sum = double(start - endline)  / 1024 / 1024;
		out << "The " << num << " th set" << endl;
		out << "Present place is " << long long(endline) << endl;
		out << "The memory for this set is " << dsum << " B" << endl;
		out << "Having used stack for " << sum << setprecision(2) << " MB" << endl;
		out << "------------------------------------------------" << endl;
	}
	num++;
	moveon();
	num--;
	endline = &k;
	sum = double(start - endline) / 1024 / 1024;
	out << "Withdraw to the " << num << " th set" << endl;
	out << "Present place is " << long long(endline) << endl;
	out << "Having used stack for " << sum << setprecision(2)<< " MB" << endl;
	out << "------------------------------------------------" << endl;
}
void stack_test::swing3()
{
	int map[300];
	char k='a';
	if (num == 0)
	{
		start = &k;
		last_end = &k;
		out << "The start place is " << long long(start) << endl;
	}
	else
	{
		if (num > 1)last_end = endline;
		endline = &k;
		dsum = last_end - endline;
		sum = double(start - endline)  / 1024 / 1024;
		out << "The " << num << " th set" << endl;
		out << "Present place is " << long long(endline) << endl;
		out << "The memory for this set is " << dsum << " B" << endl;
		out << "Having used stack for " << sum << setprecision(2) << " MB" << endl;
		out << "------------------------------------------------" << endl;
	}
	num++;
	moveon();
	num--;
	endline = &k;
	sum = double(start - endline) / 1024 / 1024;
	out << "Withdraw to the " << num << " th set" << endl;
	out << "Present place is " << long long(endline) << endl;
	out << "Having used stack for " << sum << setprecision(2) << " MB" << endl;
	out << "------------------------------------------------" << endl;
}
void stack_test::moveon()
{
	if (mode < 0 && num >= 20) return;
	if (mode == 1||mode==-1) swing1();
	if (mode == 2||mode==-2) swing2();
	if (mode == 3||mode==-3) swing3();
}