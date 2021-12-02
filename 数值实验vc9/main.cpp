#include<iostream>
#include<string>
#include<ctime>
using namespace std;
#include"Globals.h"
#include"Project.h"
#include "part.h"
void main()
{
	srand(time(0));       //seed

	fout.open("output.txt",ios::app);

	
	int m = 5; //机器数（或员工数）
	double D = 0.6; //优先序密度
	int lowProcess = 1; //加工时间下限
	int upProcess = 10;  //加工时间上限
	
	fout<<"n="<<n<<", "
		<<"m="<<m<<", "
		<<"D="<<D<<", "
	    <<"lowProcess="<<lowProcess<<", "
		<<"upProcess="<<upProcess<<endl;
	
	
	
	cout<<"n="<<n<<", "
		<<"m="<<m<<", "
		<<"D="<<D<<", "
	    <<"lowProcess="<<lowProcess<<", "
		<<"upProcess="<<upProcess<<endl;

	Project pro(n,m,D,lowProcess,upProcess);
	
	pro.Generic1();
	pro.pa.out();
	fout<<"Generic_tt1="<<pro.Generic_tt1<<endl;
	cout<<"Generic_tt1="<<pro.Generic_tt1<<endl;

}
