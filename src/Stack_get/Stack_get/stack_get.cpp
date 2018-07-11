#include<iostream>
#include<fstream>
#include <windows.h>
#include"stack_get.h"
#include"cp_integer.h"

stack_get::stack_get() //����ջ�׵�ַ
{
	char first='a'; 
	init = &first; //ջ�׵�ַ
	max = 1024 * 1024;
}
stack_get* stack_get::stack_app = NULL; //����ģʽ�Ķ���

stack_get::~stack_get()
{
	if (stack_app != NULL) delete(stack_app);
}
void stack_get::get_result() //��ȡ���
{
	char temp='a';
	present = &temp; //��ǰջ��ַ
	double answer = (double(max) - double(init - present)) / 1024 / 1024;  //��ǰʣ��ջ�ڴ�
	std::cout << "There is still " << answer << " MB of stack memory left" << std::endl;
}
stack_get* stack_get::initialize() //��ȡʵ������ķ���
{
	if (stack_app == NULL) stack_app = new stack_get();
	return stack_app;
}
void stack_get::limit_set() //��ʼ��1����teb��ȡջ��С
{
	NT_TIB *tib = (NT_TIB*)NtCurrentTeb(); 
	DWORD stackBase = (DWORD)tib->StackBase; //��ȡջ�׵�ַ
	DWORD stackLimit = (DWORD)tib->StackLimit; //��ȡջ���޵�ַ
	max = stackBase - stackLimit; //����õ�ջ�ڴ����ޣ���λΪByte
}
void stack_get::limit_set(int a) //��ʼ��2������ջ��СΪĬ��1M�����ǲ��޸�ջʵ�ʴ�С
{
	max = 1024 * 1024;
}
void stack_get::limit_set(char c) //��ʼ��3���û��ֶ�����ջ��С�����ǲ��޸�ʵ��ջ��С
{
	std::cout << "Please input an integer of the unit of stack limit" << std::endl;
	std::cout << "1 means MB,2 means KB,3 means Byte" << std::endl;
	cp_integer m,n; //�����˴��빹�������cp_integer�ļ�������ȷ����int���������������׳������쳣
	int k;
	m.input(1, 3);
	std::cout << "Now input an integer as the number of stack limit" << std::endl;
	k = m.get();
	if (k == 1) //MBģʽ
	{
		std::cout << "It should >=1 and <=64" << std::endl; 
		n.input(1, 64);
	}
	if (k == 2) //KBģʽ
	{
		std::cout << "It should >=64 and <=65536" << std::endl;
		n.input(64, 65536);
	}
	if (k == 3) //byteģʽ
	{
		std::cout << "It should >=65536 and <=67108864" << std::endl;
		n.input(65536, 67108864);
	}
	int p = n.get();
	if (k == 1) max = p * 1024 * 1024;
	if (k == 2) max = p * 1024;
	if (k == 3) max = p;
}
void stack_get::choose() //����ģ��
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