#pragma once
#include<vector>
using namespace std;
#include "Chromosome.h"


	
class Population
{
public:
	int generation;//当前世代数
	vector<Chromosome*> vec_chrom;//染色体集合
	double ave_fitness;
	float sum_fitness,min_fitness,max_fitness;

	Population();
	~Population();

	void compute_sum_ave_min_fitness();
	void output();
};
