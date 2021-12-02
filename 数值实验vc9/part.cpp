#include "part.h"
#include"Globals.h"
#include"common.h"
#include "Chromosome.h"
#include<vector>
#include <iomanip>
using namespace std;
part::part(void)
{
	Part=new vector<int> [maxpartcell+1];
	for(int i=0;i<maxpartcell;i++)
	{
		vector<int> coin;
		vector<int> temp1,temp2;

		for(int k=1;k<n+1;k++)
		{
			temp1.push_back(k);
			if(((double)rand()/RAND_MAX)>0.6)
				coin.push_back(1);
			else
				coin.push_back(0);
		}
	
		for(int j=0;j<n;j++)
	
		{
			if(coin[j]==1)
				temp2.push_back(temp1[j]);
			
		}
		Part[i]=temp2;
		
	}
	
}

part::~part(void)
{
	delete[]Part;

}

void part::out()
{
	
	vector<int>::iterator it;
	for(int i=0;i<maxpartcell;i++)
	{
		cout<<setw(3)<<"P"<<i+1;
			for(it=Part[i].begin();it!=Part[i].end();it++)
				cout<<setw(3)<<*it;			
	
		cout<<endl;//-i denotes *
	}
}