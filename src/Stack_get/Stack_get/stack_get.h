#ifndef STACK_GET_H
#define STACK_GET_H
class stack_get
{
private:
	stack_get(); //采用单体模式
	
	~stack_get();
	char* init, *present;
	int max;
	static stack_get* stack_app;
public:
	void limit_set();//修改栈大小后自动获取栈上限
	void limit_set(int a);//默认栈上限1M
	void limit_set(char c);//用户手动输入栈上限
	void choose();
	void get_result();
	void get_result(int i);
	static stack_get* initialize();
};
#endif
