#ifndef STACK_TEST_H
#define STACK_TEST_H
class stack_test
{
public:
	int mode, num;//mode1:ִ��1����ջ��2:ִ��2����ջ,3��ִ��3����ջ
	              //-1��ִ��1��20��ջ��-2ִ��-2��20��ջ��-3��ִ��-3��20��ջ
	double sum; //�ܹ��ڴ��С
	int dsum; //һ���������ڴ��С
	char* start,*endline,*last_end; //�ֱ�Ϊջ�׵�ַ��Ŀǰ���õĺ�����ջβ��ַ����һ�ε��ú�����ջβ��ַ
	stack_test(int i):mode(i),num(0),start(NULL),endline(NULL),last_end(NULL),dsum(0),sum(0){}
	~stack_test(){}
	void control();
	void swing1();
	void swing2();
	void swing3();
	void moveon();
};
#endif
