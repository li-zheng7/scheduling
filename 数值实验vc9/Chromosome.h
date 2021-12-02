#pragma once
#include<vector>
using namespace std;

class Chromosome
{
public:
	int n; //工件数
	int m; //机器数（或员工数）
	vector<int> chrom;
	float fitness;//个体适应度。为简便起见，让其等于目标函数值
	vector<int> * sub_chrom;

	Chromosome(int m);
	Chromosome(int n,int m);
	~Chromosome(void);

	void merge(); //sub_chrom加上 flag=-1 合并为 chrom
	void dispatch();//chrom上的机器分配到sub_chrom
	bool pan();
	
};
