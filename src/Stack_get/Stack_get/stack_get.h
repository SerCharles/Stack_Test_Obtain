#ifndef STACK_GET_H
#define STACK_GET_H
class stack_get
{
private:
	stack_get(); //���õ���ģʽ
	
	~stack_get();
	char* init, *present;
	int max;
	static stack_get* stack_app;
public:
	void limit_set();//�޸�ջ��С���Զ���ȡջ����
	void limit_set(int a);//Ĭ��ջ����1M
	void limit_set(char c);//�û��ֶ�����ջ����
	void choose();
	void get_result();
	void get_result(int i);
	static stack_get* initialize();
};
#endif
