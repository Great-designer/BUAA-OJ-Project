#include<stdio.h>

int main()
{
	int n,m,cur,curm;
	scanf("%d%d",&n,&m);
	while(n--)
	{
		scanf("%d%d",&cur,&curm);
		if(cur == m)
		{
			printf("%.2f\n",0.521 * curm);
		}
	}
	return 0;
}