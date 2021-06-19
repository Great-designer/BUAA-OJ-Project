#include<stdio.h>   

long long dfsbook[100005];   
int animals[100005][26];   
int size[100005];

long long dfs(int d,int t)
{   
	if(size[d]==0)
	{   
		if(t)   
		{ 
			return dfsbook[d]=1;   //到终点 return 1，直接反映为上 tot+=1 
		}
		else
		{ 
			return 0;   
		}
	}   
	long long tot=0;   
	int i; 
	for(i=0;i<size[d];i++)
	{   
		int k=animals[d][i];   
		tot+=(dfsbook[k]?dfsbook[k]:dfs(k,t+1));   
	}   
	return dfsbook[d]=tot;   
}   

char consumer[100005];   

int main()   
{   
	int n,m;  
	scanf("%d%d",&n,&m);   
	int i;
	for(i=0;i<m;i++)
	{              //建图，个人认为没有 bug    
		int temp1,temp2;   
		scanf("%d%d",&temp1,&temp2);   
		consumer[temp2]=1;   
		animals[temp1][size[temp1]]=temp2;   
		size[temp1]++;
	}
	long long bodycount=0;  
	for(i=1;i<=n;i++)   
	{
		if(!consumer[i])   
		{
			bodycount+=dfs(i,0);  
		}
	}
	printf("%lld",bodycount);   
	return 0;   
}

