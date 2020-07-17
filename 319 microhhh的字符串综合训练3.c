#include<stdio.h>
#include<string.h>

char a[40010];
int next[40010];

int ans[40010];

void getNext(int next[],char str[])
{
	int t=next[0]=-1;
	int len=strlen(str);
	int j=0;
	while(j<len-1)
	{
		if(t<0||str[j]==str[t])
		{
			next[++j]=++t;
		} 
		else
		{
			t=next[t];
		} 
	}
}

int main()
{
	while(~scanf("%s",a))
	{
		memset(ans,0,sizeof(ans));
		memset(next,0,sizeof(next));
		getNext(next,a);
		int t=next[strlen(a)-1];
		int cnt=0;
		while(t!=-1)
		{
			if(a[t]==a[strlen(a)-1])
			{
				ans[cnt++]=t+1;
			} 
			t=next[t];
		}
		int i; 
		for(i=cnt-1;i>=0;--i)
		{
			printf("%d ",ans[i]);
		}
		printf("%d\n",strlen(a));
	}
}
