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

//����E��F�ĲX
vector<int> setDifference(vector<int> E, vector<int> F);

vector<int> setSubtract(vector<int> E,int i);

//����E��F�Ľ���X
vector<int> setIntersection(vector<int> E, vector<int> F);

//����E��F�Ĳ���X
vector<int> setUnion(vector<int> E, vector<int> F);
//����E��i�Ĳ���X
vector<int> setAdd(vector<int> E, int i);
//���ظ�Ԫ�ؼ���E�Ƿ�������ظ�Ԫ�ؼ���F
bool include(vector<int> E, vector<int> F);
//���ظ�Ԫ�ؼ���E�Ƿ����Ԫ��i
bool eleInclude(vector<int> E, int i);
//����F���ڼ���E����
vector<int> setPushBack(vector<int>E, vector<int> F);
int Max(int a, int b);

int Min(int a, int b);

//��V�в���s~e������
void INSERT_ELEMENTS(vector<int> &V,int s,int e);

int FindPosition(vector<int> vec,int val);

#endif

