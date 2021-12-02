#include"Globals.h"
#include<vector>
using namespace std;

ofstream fout;
ofstream fDataOut;
const int popsize=10;//种群大小
const int MaxGen=100; //最大代数
const double pcrossover=0.9;//交叉率
const double pmutation=0.7;//变异率
const double pcoin=0.7; //抛掷硬币为正面的概率
const double pselect=0.7;//选择算子概率值k
const double epinong=0.01;
const int n=10;
const double intera=0.3;
const double outera=0.7;

const int maxpartcell=5;
