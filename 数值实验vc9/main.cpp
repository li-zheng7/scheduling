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

	
	int m = 5; //����������Ա������
	double D = 0.6; //�������ܶ�
	int lowProcess = 1; //�ӹ�ʱ������
	int upProcess = 10;  //�ӹ�ʱ������
	
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
