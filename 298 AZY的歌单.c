#include<stdio.h>
#include<string.h>

char mark[105];
int n;
int tmp;

int main()
{
	while(~scanf("%d",&n))
	{
		memset(mark,0,sizeof(mark));
		int nn=n;
		while(n--)
		{
			scanf("%d",&tmp);
			mark[tmp]=1;
		}
		int i;
		for(i=0;i<=nn;++i)
		{
			if(!mark[i])
			{
				printf("%d\n",i);
				break;
			}
		}
	}
}
