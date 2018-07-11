#include<iostream>
#include<sys/resource.h>//getrlimit需要的头文件
#include<iomanip>
#include<fstream>
using namespace std;
ofstream out("data_out.txt");
struct rlimit lim_get;
void test(int num)
{
//手动爆栈来获取已使用栈内存，和之前的代码方法相似
static char* start_flag;
static char* this_flag;
if(num==0)
{
char start='a';
start_flag=&start; //获取首地址
this_flag=start_flag;
}
else
{
char c='a';
this_flag=&c;
out<<"The "<<num<<"th data"<<endl;
double sum=double(start_flag-this_flag)/1024/1024;
out<<setprecision(2)<<sum<<"MB of stack has been used"<<endl;
out<<"---------------------------------------------------"<<endl;
}
num++;
test(num);
}
int main()
{
getrlimit(RLIMIT_STACK,&lim_get); 
double limit=double(lim_get.rlim_cur)/1024/1024;
out<<"The stack limit is "<<setprecision(2)<<limit<<"MB"<<endl; 
//以上三句代码用来自动获取栈内存上限
test(0);
return 0;
}
