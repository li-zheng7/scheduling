#pragma once
#include<vector>
using namespace std;

class Chromosome
{
public:
	int n; //������
	int m; //����������Ա������
	vector<int> chrom;
	float fitness;//������Ӧ�ȡ�Ϊ���������������Ŀ�꺯��ֵ
	vector<int> * sub_chrom;

	Chromosome(int m);
	Chromosome(int n,int m);
	~Chromosome(void);

	void merge(); //sub_chrom���� flag=-1 �ϲ�Ϊ chrom
	void dispatch();//chrom�ϵĻ������䵽sub_chrom
	bool pan();
	
};
