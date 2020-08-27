#include<stdio.h>
#include<string.h>

int prime[3000001];
char vis[3000001];
int Prime()
{	
	int cnt=0;	
	memset(vis,0,sizeof(vis));
	int i;	
	for(i=2;i<3000001;i++)	
	{		
		if(!vis[i])		
		prime[cnt++]=i;		
		int j;
		for(j=0;j<cnt&&i*prime[j]<3000001;j++)		
		{			
			vis[i*prime[j]]=1;			
			if(i%prime[j]==0)
			{
				break;
			}	
		}	
	}	
	return cnt;
}

int main()
{
	Prime();
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		if(n==1)
		{
			printf("NO\n");
		}
		else if(vis[n]==0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}
