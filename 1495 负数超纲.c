#include<stdio.h>
#include<stdlib.h>

int n,m,u=0,b[1005];
char s[5];

int main()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&m);
		int j,k=1,a;
		scanf("%d",&a);
		for(j=1;j<=(m-1)/2;j++)
		{
			scanf("%s",s);
			int x;
			scanf("%d",&x);
			if (s[0]=='+')
				a=a+x;
			else
				a=a-x;
			if (a<0)
				k=0;
		}
		if (k==0)
		{
			u++;
			b[u]=i;
		}
	}
	printf("%d\n",u);
	if (u!=0)
	{
		for(i=1;i<=u;i++)
		{
			printf("%d\n",b[i]);
		}
	}
}
