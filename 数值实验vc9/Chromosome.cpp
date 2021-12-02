#include "Chromosome.h"
#include"common.h"


Chromosome::Chromosome(int m)
:m(m)
{	
	sub_chrom = new vector<int> [m+1];
}


Chromosome::Chromosome(int n,int m)
:n(n),
 m(m)
{
	sub_chrom = new vector<int> [m+1];

	INSERT_ELEMENTS(chrom,1,n);
	for(int t=1;t<m;t++)
		chrom.push_back(-t); //用-t表示*
	do {
		random_shuffle(chrom.begin(),chrom.end()); //对一个chrom内元素进行重新排序（随机的）
	
		dispatch();
	}
	while(pan());
}

Chromosome::~Chromosome(void)
{
	delete [] sub_chrom;
}

void Chromosome::merge()
{
	vector<int>::iterator it;
	for(int i=1;i<=m;i++)
	{
		if(!sub_chrom[i].empty())
		{
			for(it=sub_chrom[i].begin();it!=sub_chrom[i].end();it++)
				chrom.push_back(*it);			
		}
		chrom.push_back(-i); //-i denotes *
	}
	chrom.pop_back();
}

void Chromosome::dispatch()
{
	vector<int>::iterator it;

	vector<int> temp;
	for(it=chrom.begin();;it++)
	{
		if(it==chrom.end())
		{
			sub_chrom[m] = temp;
			break;
		}
		else if(*it>0)
			temp.push_back(*it);
		else
		{
			sub_chrom[-(*it)] = temp;
			temp.clear();
		}
	}
}
bool Chromosome:: pan()
{
	for(int i=1;;i++)
	{
		if(sub_chrom[i].empty())
			return true;
		else if(i==m)
			return false;
		
	}
}
