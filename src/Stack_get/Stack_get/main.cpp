#include<iostream>
#include<fstream>
#include"stack_get.h"
#pragma comment(linker, "/STACK:1048576,1048576")
using namespace std;
stack_get* g; //����ָ��
ifstream in("data_in.txt");
ofstream out("data_out.txt");
void stack_get::get_result(int i) //�ʺ��ļ�������Ĵ��룬�������ʽ��Ϳ���̨�汾��ȫһ��
{
	char temp = 'a';
	present = &temp;
	double answer = (double(max) - double(init - present)) / 1024 / 1024;
	out << "There is still " << answer << " MB of stack memory left\n";
}
void stack_test(int num) //���Դ���
{
	static int total=0;
	static int outplace_num=0;
	static int outplace[30];
	if (num == 0) //�ļ������ܵݹ������������������������λ��
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
	num++; //�ݹ�
    if (num <= total) stack_test(num); //�ж��Ƿ���ջ
	num--; //��ջ
	whether = 0;
	for (i = 1; i <= outplace_num; i++)//�ж��Ƿ����
	{
		if (num == outplace[i])
		{
			whether = 1;
			break;
		}
	}
	if (whether == 1)//���
	{
		out << "The " << num << "th data" << endl;
		g->get_result(1);
	}
}
int main()
{
	g = g->initialize(); //��ʼ��ʵ������
	g->choose(); //ѡ��ģʽ
	stack_test(0);
	stack_test(1);
	return 0;
}