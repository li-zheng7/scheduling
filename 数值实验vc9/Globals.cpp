#include"Globals.h"
#include<vector>
using namespace std;

ofstream fout;
ofstream fDataOut;
const int popsize=10;//��Ⱥ��С
const int MaxGen=100; //������
const double pcrossover=0.9;//������
const double pmutation=0.7;//������
const double pcoin=0.7; //����Ӳ��Ϊ����ĸ���
const double pselect=0.7;//ѡ�����Ӹ���ֵk
const double epinong=0.01;
const int n=10;
const double intera=0.3;
const double outera=0.7;

const int maxpartcell=5;
