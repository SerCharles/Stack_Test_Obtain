#include<iostream>
#include<fstream>
#include"stack_get.h"
#pragma comment(linker, "/STACK:1048576,1048576")
using namespace std;
stack_get* g; //定义指针
ifstream in("data_in.txt");
ofstream out("data_out.txt");
void stack_get::get_result(int i) //适合文件流输出的代码，除输出方式外和控制台版本完全一样
{
	char temp = 'a';
	present = &temp;
	double answer = (double(max) - double(init - present)) / 1024 / 1024;
	out << "There is still " << answer << " MB of stack memory left\n";
}
void stack_test(int num) //测试代码
{
	static int total=0;
	static int outplace_num=0;
	static int outplace[30];
	if (num == 0) //文件读入总递归次数，总输出次数，和输出的位置
	{
		in >> total;
		in >> outplace_num;
		for (int i = 1; i <= outplace_num; i++)
		{
			int p;
			in >> p;
			outplace[i] = p;
		}		
	}
	int i;
	bool whether = 0;
	for (i = 1; i <= outplace_num; i++)
	{
		if (num == outplace[i])
		{
			whether = 1;
			break;
		}
	}
	if (whether == 1)
	{
		out << "The " << num << "th data" << endl;
		g->get_result(1);
	}
	num++; //递归
    if (num <= total) stack_test(num); //判断是否退栈
	num--; //退栈
	whether = 0;
	for (i = 1; i <= outplace_num; i++)//判断是否输出
	{
		if (num == outplace[i])
		{
			whether = 1;
			break;
		}
	}
	if (whether == 1)//输出
	{
		out << "The " << num << "th data" << endl;
		g->get_result(1);
	}
}
int main()
{
	g = g->initialize(); //初始化实例对象
	g->choose(); //选择模式
	stack_test(0);
	stack_test(1);
	return 0;
}