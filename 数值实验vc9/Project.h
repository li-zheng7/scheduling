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
	int n; //������
	int m; //����������Ա������
	double D; //����ͼ�ܶ�
	int lowProcess,upProcess; //�ӹ�ʱ������,����
	
	double heuristic_tt; // heuristic�� total tardiness
	double Generic_tt1; //genetic algorithm1 �� total tardiness
	double heuristicTime,GenericTime1;

	Job * job;
	part pa;
	int ** p; //�ӹ�ʱ��
	vector<int> M; //��������
	vector<int> J; //��������Ԫ�Ĺ�������
	vector<int> *sub_machine; //�������ϵĹ�������

public:
	Project(int n,int m,double D,int lowProcess,int upProcess);
	~Project(void);
	void DataInput();
	void DataOutput();
	double Pr(int i ,int j);

	double compute_tt(vector<int> *sub_machine);//RFRA�㷨����֪sub_chrom����total tardiness
	int EarlyTime(int i,int *t,int *machine_idle,int *assign);
	    //�������翪ʼ�ͽ���ʱ��,�ݹ麯��,�������ʱ��
	    //tΪ�ӹ�ʱ�䣬machine_idleΪ������ʼ����ʱ�䣬assignΪ��������Ļ���
    int setTimeET(int *t,int *assign);
	    //�������翪ʼ�ͽ���ʱ��,
	    //����total tardiness,tΪ�ӹ�ʱ�䣬assignΪ��������Ļ���

	void Initialpop(Population *pop);

	vector<Chromosome*> crossover(Population *pop);
	Chromosome * chrom_cross(Chromosome *c1,Chromosome *c2);//����Chromosome�ľ�������

	vector<Chromosome*> mutation(Population *pop);
	Chromosome * muta(Chromosome *chr);//����Chromosome��mutation

	Population * selection(Population *pop);//����ѡ��

	void Generic1();

};
