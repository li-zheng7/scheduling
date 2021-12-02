#include<fstream>
#include<map>
#include<math.h>
#include<algorithm>
using namespace std;
#include"Project.h"
#include"common.h"
#include"Globals.h"
#include "part.h"
Project::Project(int n,int m,double D,int lowProcess,int upProcess)
:n(n),
 m(m),
 D(D),
 lowProcess(lowProcess),
 upProcess(upProcess)
{
	job = new Job[n+2];
	job[0].ST=0; job[0].FT=0;

	p = new int *[n+2];
	for(int i=0;i<n+2;i++)
		p[i] = new int[m+1];

	sub_machine = new vector<int> [m+1];

	for(int k=1;k<=m;k++)
		M.push_back(k);

	INSERT_ELEMENTS(J,0,n);

	DataInput();
	//DataOutput();
}

Project::~Project(void)
{
	delete [] job;

	for(int i=0;i<n+2;i++)
		delete [] p[i];
	delete [] p;

	delete [] sub_machine;
}

/*double Project::Pr(int i ,int j)
{
	//return D*pow(1-D,j-i-1) / (1 - D*(1-pow(1-D,j-i-1)));
	return (i>j)?i:j;
}*/

void Project::DataInput()
{
	/*int SUMP=0;
	//加工时间
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			p[i][j] = rand() % (upProcess-lowProcess+1) + lowProcess;
			SUMP += p[i][j];
		}
	}
	          // random number lowProcess~upProcess

    double F=0.5;
	double RD=0.1;
	int upDue=(SUMP/(2*m))*(1-F+RD/2);
	int lowDue=(SUMP/(2*m))*(1-F-RD/2);
	for(int e=1;e<=n;e++)
		job[e].d = rand() % (upDue-lowDue+1) + lowDue; 
	          // random number lowDue~upDue
*///计算加工时间
	//优先序--紧前活动
	for(int j=2;j<=n;j++)
	{				
		job[j].predecessor.push_back(j-1);
		/*for(int i=j-1;i>=1;i--)
		{
			//double r=(double)rand()/RAND_MAX;   //[0,1]随机数
			//if(Pr(i,j)>r)
				job[j].predecessor.push_back(i);
		}*/
	}

	//计算净活动的紧后活动集合
	/*for(int a=1;a<=n;a++)
	{
		if(!job[a].predecessor.empty())
			for(unsigned int k=0;k<job[a].predecessor.size();k++)
			{
				int p=job[a].predecessor[k];
				job[p].successor.push_back(a);	
			}
	}
	
	//首亚元的特殊设置
	for(int b=1;b<=n;b++)
		if(job[b].predecessor.empty())
		{
			job[0].successor.push_back(b);
			job[b].predecessor.push_back(0);
		}

	//尾亚元的特殊设置
	for(int c=1;c<=n;c++)
		if(job[c].successor.empty())
		{
			job[n+1].predecessor.push_back(c);
			job[c].successor.push_back(n+1);
		}*/
}

void Project::DataOutput()
{
	vector<int>::iterator it;

	fDataOut<<"NbN="<<n<<";"<<endl
		    <<"NbM="<<m<<";"<<endl<<endl;

	fDataOut<<"Precedence=#["<<endl;
	for(int i=1;i<=n;i++)
	{
		fDataOut<<i<<":{";
		for(it=job[i].predecessor.begin();it!=job[i].predecessor.end();it++)
			fDataOut<<*it<<",";
		fDataOut<<"},"<<endl;
	}
	fDataOut<<"]#;"<<endl<<endl;

	fDataOut<<"p=["<<endl;
	for(int j=1;j<=n;j++)
	{
		fDataOut<<"[";
		for(int k=1;k<=m;k++)
			fDataOut<<p[j][k]<<" ";
		fDataOut<<"],"<<endl;
	}
	fDataOut<<"];"<<endl<<endl;

	fDataOut<<"d=[";
	for(int e=1;e<=n;e++)
		fDataOut<<job[e].d<<",";
	fDataOut<<"];"<<endl<<endl;

	fDataOut<<"PJ={";
	for(int r=1;r<=n;r++)
	{
		if(job[r].predecessor.front()!=0)
			fDataOut<<r<<",";
	}
	fDataOut<<"};"<<endl;
}
//*//
double Project::compute_tt(vector<int> *sub_machine)
{
	
	vector<int> inter,outer;
	vector<int>::iterator it;
	
	int s_out=0;int s_in=0;
	for(int w=0;w<maxpartcell;w++)
	{
			
		int mech=0,out=0,in=0;
		
		for(it=pa.Part[w].begin();it!=pa.Part[w].end();it++)
		{
			
			for(int v=1;v<=m;v++)
			{
				if(eleInclude(sub_machine[v], *it))	
				{
					if(mech==v)
					{
						in++;
					}
					else{
						out++;
						mech=v;
					}
				}
		
			}
		}
		if(in>0)
		   s_in+=in;
		if(out>0)
			s_out+=out-1;
			
	}
	
			double tt=outera*s_out+intera*s_in;
			return tt;
		
}



//*/
/*/
int Project::compute_tt(vector<int> *sub_machine)
{
	int *t=new int[n+1];//processing time
	int *assign=new int[n+1];//分配的机器
	vector<int>::iterator it;
	for(int v=1;v<=m;v++)
	{
		for(it=sub_machine[v].begin();it!=sub_machine[v].end();it++)
		{
			t[*it]=p[*it][v];
			assign[*it]=v;
		}
	}

	int tt = setTimeET(t,assign);

	delete []t;
	delete []assign;

	return tt;
}

int Project::EarlyTime(int i,int *t,int *machine_idle,int *assign)
{
	if(i==0)
		return 0;

	else if(job[i].FT != -1)
		return job[i].FT;

	else
	{	
	    vector<int> timeSet;
		for(unsigned int k=0;k<job[i].predecessor.size();k++)
		{
	    	int pj = job[i].predecessor[k];
	    	timeSet.push_back(EarlyTime(pj,t,machine_idle,assign));
    	}

		vector<int>::iterator it;
    	it = max_element(timeSet.begin(),timeSet.end());
    	job[i].ST=Max(*it,machine_idle[assign[i]]);
    	job[i].FT = job[i].ST + t[i];	
		machine_idle[assign[i]] = job[i].FT;
    	return job[i].FT;
	}
}

int Project::setTimeET(int *t,int *assign)
{
	int * machine_idle = new int[m+1];
	for(int a=1;a<=m;a++)
		machine_idle[a]=0;

	for(int i=0;i<=n;i++)
	{
		job[i].ST=-1;
		job[i].FT=-1;
	}

	vector<int>::iterator it;
	vector<int> U;
	INSERT_ELEMENTS(U,1,n);
	while(!U.empty())
	{
		int r = rand() % U.size();
		EarlyTime(U[r],t,machine_idle,assign);
		U=setSubtract(U,U[r]);
	}

	int tt=0;
	for(int k=1;k<=n;k++)
		tt += Max((job[k].FT-job[k].d),0);

	delete []machine_idle;
	return tt;
}
//*/
vector<Chromosome*> Project::crossover(Population *pop)
{
	Chromosome * new_chromosome;
	vector<Chromosome*> vec_new_chrom;
	vector<Chromosome*> vec_chrom = pop->vec_chrom;
	vector<Chromosome*>::iterator iti,itj,tem;
	tem=vec_chrom.end();
	tem--;
	for(iti=vec_chrom.begin();iti!=tem;iti++)
	{
		for(itj=++iti,iti--;itj!=vec_chrom.end();itj++)
		{
			new_chromosome = chrom_cross(*iti,*itj);
			if(new_chromosome->fitness <= pop->ave_fitness)
				vec_new_chrom.push_back(new_chromosome);
			else
				delete new_chromosome;
		}
	}

	return vec_new_chrom;
}

Chromosome * Project::chrom_cross(Chromosome *c1,Chromosome *c2)
{
	Chromosome *chr1,*chr2;
	if(c1->fitness <= c2->fitness)
	{
		chr1 = c1;
		chr2 = c2;
	}
	else
	{
		chr1 = c2;
		chr2 = c1;
	}

	Chromosome * new_chromosome = new Chromosome(m);
	vector<int> selected1,selected2;
	for(int k=1;k<=n+m-1;k++)
	{
		selected1.push_back(0);
		selected2.push_back(0);
	}

	for(int e=1;e<=n;e++)
	{
		double r=(double)rand()/RAND_MAX;   //[0,1]随机数
		if(r<pcoin)
		{
			int p = FindPosition(chr1->chrom,e);
			selected1[p] = e;
		}
		else
		{
			int p = FindPosition(chr2->chrom,e);
			selected2[p] = e;
		}
	}

	for(int w=1;w<=m-1;w++)
	{
		double r=(double)rand()/RAND_MAX;   //[0,1]随机数
		if(r<pcoin)
		{
			int p = FindPosition(chr1->chrom,-w);
			selected1[p] = -w;
		}
		else
		{
			int p = FindPosition(chr2->chrom,-w);
			selected2[p] = -w;
		}
	}

	selected2 = setSubtract(selected2,0);
	vector<int>::iterator it1,it2;
	for(it2=selected2.begin();it2!=selected2.end();it2++)
	{
		int p=0;
		for(it1=selected1.begin();it1!=selected1.end();it1++,p++)
		{
			if(*it1==0)
			{
				selected1[p] = *it2;
				break;
			}
		}
	}

	new_chromosome->chrom = selected1;
	new_chromosome->dispatch();

	new_chromosome->fitness = compute_tt(new_chromosome->sub_chrom);
	return new_chromosome;
}

vector<Chromosome*> Project::mutation(Population *pop)
{
	vector<Chromosome*> vec_new_chrom;
	vector<Chromosome*>::iterator it;
	for(it=pop->vec_chrom.begin();it!=pop->vec_chrom.end();it++)
	{
		if(pmutation>(double)rand()/RAND_MAX)
		{
			Chromosome * muta_chr = muta(*it);
			vec_new_chrom.push_back(muta_chr);
		}
	}

	return vec_new_chrom;
}

Chromosome * Project::muta(Chromosome *chr)
{
	Chromosome *new_chr = new Chromosome(m);
	for(int k=1;k<=m;k++)
		new_chr->sub_chrom[k] = chr->sub_chrom[k];

	int v1 = rand() % m + 1;
	while(new_chr->sub_chrom[v1].empty())
		v1 = rand() % m + 1;

	int v2 = rand() % m + 1;
	while(v1==v2)
		v2 = rand() % m + 1;

	if(!new_chr->sub_chrom[v2].empty())
	{
		int g1 = rand() % new_chr->sub_chrom[v1].size();//sub_chrom[v1]的随机位g1
		int g2 = rand() % new_chr->sub_chrom[v2].size();//sub_chrom[v2]的随机位g2

		int t=new_chr->sub_chrom[v1][g1];
		new_chr->sub_chrom[v1][g1] = new_chr->sub_chrom[v2][g2];
		new_chr->sub_chrom[v2][g2] = t;
	}
	else
	{
		int g1 = rand() % new_chr->sub_chrom[v1].size();//sub_chrom[v1]的随机位g1
		int t = new_chr->sub_chrom[v1][g1];
		new_chr->sub_chrom[v1] = setSubtract(new_chr->sub_chrom[v1],t);
		new_chr->sub_chrom[v2].push_back(t);
	}	

	new_chr->merge();

	new_chr->fitness = compute_tt(new_chr->sub_chrom);

	return new_chr;
}


Population * Project::selection(Population *pop)
{
	
	Population *new_pop = new Population;
	vector<Chromosome*>::iterator iter;
	for(iter=pop->vec_chrom.begin();iter!=pop->vec_chrom.end();)
	{
		
		if((*iter)->pan())
			iter=pop->vec_chrom.erase(iter);
		else
			iter++;
	}

	int size = pop->vec_chrom.size();
	vector<Chromosome*>::iterator it;
	vector<int> index,selected_index,unselected_index;
	vector<int>::iterator itI;
	INSERT_ELEMENTS(index,0,size-1);

	for(int i=1;i<=popsize;i++,size--)
	{
		int r1 = rand() % size;
		int r2 = rand() % size;
		while(r2==r1)
			r2 = rand() % size;

		int p1=index[r1];
		int p2=index[r2];

		int small;
		int large; //适应值小，大的位置标号
		if(pop->vec_chrom[p1]->fitness < pop->vec_chrom[p2]->fitness)
		{
			small=p1;
			large=p2;
		}
		else
		{
			small=p2;
			large=p1;
		}

		double r=(double)rand()/RAND_MAX;   //[0,1]随机数
		if(r < pselect)
		{		
			selected_index.push_back(small);
			index = setSubtract(index,small);	
			new_pop->vec_chrom.push_back(pop->vec_chrom[small]);
		}
		else
		{
			selected_index.push_back(large);
			index = setSubtract(index,large);
			new_pop->vec_chrom.push_back(pop->vec_chrom[large]);
		}
	}

	unselected_index = setDifference(index,selected_index);
	for(itI=unselected_index.begin();itI!=unselected_index.end();itI++)
		delete pop->vec_chrom[*itI];

	new_pop->compute_sum_ave_min_fitness();

	return new_pop;
}


void Project::Initialpop(Population *pop)
{
	pop->generation = 1;

	for(int k=1;k<=popsize;k++)
	{
		Chromosome * chr = new Chromosome(n,m);
		chr->fitness = compute_tt(chr->sub_chrom);
		pop->vec_chrom.push_back(chr);
	}

	pop->compute_sum_ave_min_fitness();
}


void Project::Generic1()
{
	clock_t start,finish;
    double totaltime;
    start=clock();

	Population *pop = new Population;
	Initialpop(pop);
	pop->output();
	Generic_tt1 = pop->min_fitness;

	vector<Chromosome*>::iterator it;
	for(int gen=2;gen<=MaxGen;gen++)
	{
		vector<Chromosome*> cross_vec_chrom = crossover(pop);//交叉
		vector<Chromosome*> muta_vec_chrom = mutation(pop);//变异
		vector<Chromosome*>::iterator it;
		for(it=cross_vec_chrom.begin();it!=cross_vec_chrom.end();it++)
			pop->vec_chrom.push_back(*it);
		for(it=muta_vec_chrom.begin();it!=muta_vec_chrom.end();it++)
			pop->vec_chrom.push_back(*it);

		if(pop->vec_chrom.size()>popsize)
			pop = selection(pop);
		pop->generation=gen;
		pop->output();
		if(pop->min_fitness < Generic_tt1)
			Generic_tt1 = pop->min_fitness;

		double diff=0;
		for(int k=0;k<popsize;k++)
			diff += pow(pop->vec_chrom[k]->fitness - pop->ave_fitness, 2);
		double deviation = sqrt(diff/popsize);
		if(deviation<=epinong)
			break;
	}
	
	delete pop;

	finish=clock();	
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
	GenericTime1 = totaltime;
}

