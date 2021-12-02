#ifndef GLOBALS_
#define GLOBALS_

#include<fstream>
using namespace std;

extern ofstream fout;
extern ofstream fDataOut;
extern const int popsize;//种群大小
extern const int MaxGen; //最大代数
extern const double pcrossover;//交叉率
extern const double pmutation;//变异率
extern const double pcoin; //抛掷硬币为正面的概率
extern const double pselect;//选择算子概率值k
extern const double epinong;
extern const int n ; //工件数
extern const double intera;
extern const double outera;
extern const int maxpartcell;
#endif