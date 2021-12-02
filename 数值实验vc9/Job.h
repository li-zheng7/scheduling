#pragma once
#include<vector>
using namespace std;

class Job
{
public:
	int ST;                  //实际开始时间
	int FT;                  //实际完成时间
	int v;                   //分配的机器
	int d;                   //due date;
	int successorNo;         //紧后活动的个数
    vector<int> successor;   //紧后活动集合
	int predecessorNo;       //紧前活动的个数
	vector<int> predecessor; //紧前活动集合

	Job(void);
	~Job(void);
};
