#pragma once
#include<vector>
using namespace std;
#include"Job.h"
#include "Population.h"
#include "Chromosome.h"
#include "part.h"
class Project
{
public:
	int n; //工件数
	int m; //机器数（或员工数）
	double D; //优先图密度
	int lowProcess,upProcess; //加工时间下限,上限
	
	double heuristic_tt; // heuristic的 total tardiness
	double Generic_tt1; //genetic algorithm1 的 total tardiness
	double heuristicTime,GenericTime1;

	Job * job;
	part pa;
	int ** p; //加工时间
	vector<int> M; //机器集合
	vector<int> J; //包括首亚元的工件集合
	vector<int> *sub_machine; //各机器上的工件集合

public:
	Project(int n,int m,double D,int lowProcess,int upProcess);
	~Project(void);
	void DataInput();
	void DataOutput();
	double Pr(int i ,int j);

	double compute_tt(vector<int> *sub_machine);//RFRA算法，已知sub_chrom计算total tardiness
	int EarlyTime(int i,int *t,int *machine_idle,int *assign);
	    //设置最早开始和结束时间,递归函数,返回完成时间
	    //t为加工时间，machine_idle为机器开始闲置时间，assign为工件分配的机器
    int setTimeET(int *t,int *assign);
	    //设置最早开始和结束时间,
	    //返回total tardiness,t为加工时间，assign为工件分配的机器

	void Initialpop(Population *pop);

	vector<Chromosome*> crossover(Population *pop);
	Chromosome * chrom_cross(Chromosome *c1,Chromosome *c2);//两个Chromosome的均布交叉

	vector<Chromosome*> mutation(Population *pop);
	Chromosome * muta(Chromosome *chr);//单个Chromosome的mutation

	Population * selection(Population *pop);//联赛选择

	void Generic1();

};
