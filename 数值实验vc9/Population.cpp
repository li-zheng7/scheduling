#include<algorithm>
#include<iostream>
#include "Population.h"
#include"Globals.h"

#include <iomanip>
Population::Population()
{	
}

Population::~Population()
{
	vector<Chromosome*>::iterator it;
	for(it=vec_chrom.begin();it!=vec_chrom.end();it++)
		delete *it;
}

void Population::compute_sum_ave_min_fitness()
{
	sum_fitness=0;
	vector<double> fit;
	vector<Chromosome*>::iterator it;
	for(it=vec_chrom.begin();it!=vec_chrom.end();it++)
	{
		sum_fitness += (*it)->fitness;
		fit.push_back((*it)->fitness);
	}
	ave_fitness = (double)sum_fitness / (double)popsize;
	min_fitness = * min_element(fit.begin(),fit.end());
	max_fitness = * max_element(fit.begin(),fit.end());
}

void Population::output()
{
	/*
	fout<<"generation="<<generation<<","
		<<"ave_fitness="<<ave_fitness<<","
		<<"min_fitness="<<min_fitness<<endl;
	*/
	cout<<"generation="<<generation<<","
		<<"ave_fitness="<<ave_fitness<<","
		<<"min_fitness="<<min_fitness<<endl;
	   
	vector<Chromosome*>::iterator it;
	 
	vector<int>::iterator iter;

	
	for(it=vec_chrom.begin();it!=vec_chrom.end();it++)
	{
		for(iter=(*it)->chrom.begin();iter!=(*it)->chrom.end();iter++)
	
		{
			cout<<setw(3)<<*iter;
		}
	
		cout<<setw(5)<<(*it)->fitness<<endl;
	}
	cout<<endl;

}