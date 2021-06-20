#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<vector>

using namespace std;

vector<int> tempTopoSort;
vector<int> finalTopoSort;

bool isDAG,isHamilton;
int minNotDAG,minHamilton;
int inDegreeBackup[30];
int inDegree[30];
bool edges[30][30];

int q[2020];
int front,rear;

int n,m;
int u,v;
char input[4];

void init()
{
	memset(edges,0,sizeof(edges));
	memset(inDegreeBackup,0,sizeof(inDegreeBackup));
	memset(inDegree,0,sizeof(inDegree));
	isDAG=1;
	isHamilton=0;
	tempTopoSort.clear();
	finalTopoSort.clear();
	minNotDAG=minHamilton=0;
}

int cnt;

void topoSort(int time)
{
	isHamilton=1;
	tempTopoSort.clear();
	front=rear=0;
	int i;
	for(i=0;i<n;++i)
	{
		inDegree[i]=inDegreeBackup[i];
	}
	cnt=0;
	for(i=0;i<n;++i)
	{
		if(inDegree[i]==0)
		{
			q[rear]=i;
			rear++;
			cnt++;
		}
	}
	if(cnt>1)
	{
		isHamilton=0;
	}
	while(front!=rear)
	{
		cnt=0;
		int top=q[front];
		front++;
		tempTopoSort.push_back(top);
		for(i=0;i<n;++i)
		{
			if(edges[top][i])
			{
				inDegree[i]--;
				if(inDegree[i]==0)
				{
					q[rear]=i;
					rear++;
					cnt++;
				}
			}
		}
		if(cnt>1)
		{
			isHamilton=0;
		}
	}
	if(tempTopoSort.size()<n&&isDAG&&!minHamilton)
	{
		isDAG=0;
		minNotDAG=time;
	}
	else if(isHamilton&&isDAG&&!minHamilton)
	{
		minHamilton=time;
		finalTopoSort.assign(tempTopoSort.begin(),tempTopoSort.end());
	}
}

void printRes()
{
	if(!isDAG)
	{
		printf("Inconsistent,after %d relations.\n",minNotDAG);
	}
	else if(isHamilton)
	{
		printf("Sorted,after %d relations:",minHamilton);
		vector<int>::iterator a;
		for(a=finalTopoSort.begin();a!=finalTopoSort.end();a++)
		{
			printf("%c",(*a+'A'));
		}
		puts(".");
	}
	else
	{
		puts("Not determined.");
	}
}

int main()
{
	while(scanf("%d%d",&n,&m)&&(n>=2)&&!(n==0&&m==0))
	{
		init();
		int i;
		for(i=1;i<=m;++i)
		{
			scanf("%s",input);
			u=input[0]-'A';
			v=input[2]-'A';
			if(!edges[u][v])
			{
				edges[u][v]=1;
				inDegreeBackup[v]++;
				topoSort(i);
			}
		}
		printRes();
	}
}
