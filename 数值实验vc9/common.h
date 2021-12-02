#ifndef COMMON_
#define COMMON_

#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<math.h>
#include<ctime>
#include<cstdlib> 
#include<time.h> 
#include<iomanip>
#include<algorithm>
#include<string>
#include<numeric> 
using namespace std;

template <typename DataType>
ostream & operator<<(ostream & out, vector<DataType> Y)
{
	vector<DataType>::iterator it;
	for(it=Y.begin();it!=Y.end();it++)
		out<<*it<<" ";
	return out;
}

//集合E和F的差集X
vector<int> setDifference(vector<int> E, vector<int> F);

vector<int> setSubtract(vector<int> E,int i);

//集合E和F的交集X
vector<int> setIntersection(vector<int> E, vector<int> F);

//集合E和F的并集X
vector<int> setUnion(vector<int> E, vector<int> F);
//集合E和i的并集X
vector<int> setAdd(vector<int> E, int i);
//非重复元素集合E是否包含非重复元素集合F
bool include(vector<int> E, vector<int> F);
//非重复元素集合E是否包含元素i
bool eleInclude(vector<int> E, int i);
//集合F放在集合E后面
vector<int> setPushBack(vector<int>E, vector<int> F);
int Max(int a, int b);

int Min(int a, int b);

//在V中插入s~e的整数
void INSERT_ELEMENTS(vector<int> &V,int s,int e);

int FindPosition(vector<int> vec,int val);

#endif

