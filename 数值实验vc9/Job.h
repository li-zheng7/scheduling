#pragma once
#include<vector>
using namespace std;

class Job
{
public:
	int ST;                  //ʵ�ʿ�ʼʱ��
	int FT;                  //ʵ�����ʱ��
	int v;                   //����Ļ���
	int d;                   //due date;
	int successorNo;         //�����ĸ���
    vector<int> successor;   //��������
	int predecessorNo;       //��ǰ��ĸ���
	vector<int> predecessor; //��ǰ�����

	Job(void);
	~Job(void);
};
