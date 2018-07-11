#include<iostream>
#include<fstream>
#include <windows.h>
#include"stack_get.h"
#include"cp_integer.h"

stack_get::stack_get() //设置栈首地址
{
	char first='a'; 
	init = &first; //栈首地址
	max = 1024 * 1024;
}
stack_get* stack_get::stack_app = NULL; //单体模式的定义

stack_get::~stack_get()
{
	if (stack_app != NULL) delete(stack_app);
}
void stack_get::get_result() //获取结果
{
	char temp='a';
	present = &temp; //当前栈地址
	double answer = (double(max) - double(init - present)) / 1024 / 1024;  //当前剩余栈内存
	std::cout << "There is still " << answer << " MB of stack memory left" << std::endl;
}
stack_get* stack_get::initialize() //获取实例对象的方法
{
	if (stack_app == NULL) stack_app = new stack_get();
	return stack_app;
}
void stack_get::limit_set() //初始化1：用teb获取栈大小
{
	NT_TIB *tib = (NT_TIB*)NtCurrentTeb(); 
	DWORD stackBase = (DWORD)tib->StackBase; //获取栈首地址
	DWORD stackLimit = (DWORD)tib->StackLimit; //获取栈下限地址
	max = stackBase - stackLimit; //计算得到栈内存上限，单位为Byte
}
void stack_get::limit_set(int a) //初始化2：设置栈大小为默认1M，但是不修改栈实际大小
{
	max = 1024 * 1024;
}
void stack_get::limit_set(char c) //初始化3：用户手动输入栈大小，但是不修改实际栈大小
{
	std::cout << "Please input an integer of the unit of stack limit" << std::endl;
	std::cout << "1 means MB,2 means KB,3 means Byte" << std::endl;
	cp_integer m,n; //引用了代码构件库里的cp_integer文件，能正确读入int类型整数并且能抛出完整异常
	int k;
	m.input(1, 3);
	std::cout << "Now input an integer as the number of stack limit" << std::endl;
	k = m.get();
	if (k == 1) //MB模式
	{
		std::cout << "It should >=1 and <=64" << std::endl; 
		n.input(1, 64);
	}
	if (k == 2) //KB模式
	{
		std::cout << "It should >=64 and <=65536" << std::endl;
		n.input(64, 65536);
	}
	if (k == 3) //byte模式
	{
		std::cout << "It should >=65536 and <=67108864" << std::endl;
		n.input(65536, 67108864);
	}
	int p = n.get();
	if (k == 1) max = p * 1024 * 1024;
	if (k == 2) max = p * 1024;
	if (k == 3) max = p;
}
void stack_get::choose() //主控模块
{
	std::cout << "Mode 1: After you set the limit, select it to get the stack limit" << std::endl;
	std::cout << "Mode 2: Use the default stack limit of 1MB" << std::endl;
	std::cout << "Mode 3: Manually set the stack limit" << std::endl;
	std::cout << "Now input an integer from 1 to 3 as the mode" << std::endl;
	cp_integer m;
	int k;
	m.input(1, 3);
	k = m.get();
	if (k == 1) limit_set();
	if (k == 2) limit_set(1);
	if (k == 3) limit_set('c');
}