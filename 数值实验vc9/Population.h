#pragma once
#include<vector>
using namespace std;
#include "Chromosome.h"


	
class Population
{
public:
	int generation;//��ǰ������
	vector<Chromosome*> vec_chrom;//Ⱦɫ�弯��
	double ave_fitness;
	float sum_fitness,min_fitness,max_fitness;

	Population();
	~Population();

	void compute_sum_ave_min_fitness();
	void output();
};
