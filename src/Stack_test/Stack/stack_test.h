#ifndef STACK_TEST_H
#define STACK_TEST_H
class stack_test
{
public:
	int mode, num;//mode1:执行1到爆栈，2:执行2到爆栈,3：执行3到爆栈
	              //-1：执行1到20退栈，-2执行-2到20退栈，-3：执行-3到20退栈
	double sum; //总共内存大小
	int dsum; //一个函数的内存大小
	char* start,*endline,*last_end; //分别为栈首地址，目前调用的函数的栈尾地址，上一次调用函数的栈尾地址
	stack_test(int i):mode(i),num(0),start(NULL),endline(NULL),last_end(NULL),dsum(0),sum(0){}
	~stack_test(){}
	void control();
	void swing1();
	void swing2();
	void swing3();
	void moveon();
};
#endif
