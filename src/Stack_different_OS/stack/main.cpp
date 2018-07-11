#include<iostream>
#include<fstream>
using namespace std;
char* start = NULL;
char* endline = NULL;
char* last_end = NULL;
double sum = 0;
double dsum = 0;
ofstream out("data_out.txt");
void swing1(int i,bool mode);
void swing2(int i,bool mode);
void swing3(int i,bool mode);
int main(int argv,char* argc[])
{
	int n;
	cout << "Please input an integer of 0,1,2 or 3 as the mode" << endl;
	cin >> n;
	if (n == 1)
	{
		while (1)
		{
			swing1(0,1);
		}
	}
	if (n == 2)
	{
		while (1)
		{
			swing2(0,1);
		}
	}
	if (n == 3)
	{
		while (1)
		{
			swing3(0,1);
		}
	}
	if (n == 0)
	{
		swing1(0,0);
	}
	return 0;
}
void swing1(int i,bool mode)
{
        char ii='a';
	if (i == 0)
	{
		start = &ii;
		last_end = &ii;
	}
	else
	{
		if (i > 1)last_end = endline;
		endline = &ii;
		dsum = double(last_end - endline) ;
		sum = double(start - endline)  / 1024 / 1024;
		out << "The " << i << " th set" << endl;
		out << "The memory for this set is " << dsum << " B" << endl;
		out << "Having used stack for " << sum << " MB" << endl;
		out << "------------------------------------------------" << endl;
	}
	i++;
	if (mode == 1) swing1(i,1);
	else swing2(i,0);
}
void swing2(int i,bool mode)
{
	int map[1000];
        char ii='a';
	if (i == 0)
	{
		start = &ii;
		last_end = &ii;
	}
	else
	{
		if (i > 1)last_end = endline;
		endline = &ii;
		dsum = double(last_end - endline);
		sum = double(start - endline) / 1024 / 1024;
		out << "The " << i << " th set" << endl;
		out << "The memory for this set is " << dsum << " B" << endl;
		out << "Having used stack for " << sum << " MB" << endl;
		out << "------------------------------------------------" << endl;
	}
	i++;
	if (mode == 1) swing2(i, 1);
	else swing3(i,0);
}
void swing3(int i,bool mode)
{
	char map[1000];
        char ii='a';
	if (i == 0)
	{
		start = &ii;
		last_end = &ii;
	}
	else
	{
		if (i > 1)last_end = endline;
		endline = &ii;
		dsum = double(last_end - endline) ;
		sum = double(start - endline) / 1024 / 1024;
		out << "The " << i << " th set" << endl;
		out << "The memory for this set is " << dsum << " B" << endl;
		out << "Having used stack for " << sum << " MB" << endl;
		out << "------------------------------------------------" << endl;
	}
	i++;
	if (mode == 1) swing3(i, 1);
	else swing1(i,0);
}
