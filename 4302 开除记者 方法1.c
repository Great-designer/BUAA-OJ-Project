#include<stdio.h>

int n;

int fire(int a,int b,int N)//表示方阵边长为N，记者位于第i行，第j列的情况
{
	int half=N/2;
	if(N==1)return 1;
	if(a<=half && b<=half)return 0;
	if(a<=half && b>half)return fire(a,b-half,half);
	if(a>half && b<=half)return fire(a-half,b,half);
	return fire(a-half,b-half,half);
}

int main(void)
{
	while(scanf("%d",&n)!=EOF)
	{
		int all=1<<n;
		for(int i=1; i<=all; i++)
		{
			for(int j=1; j<=all; j++)
				printf("%d ",fire(i,j,all));
			putchar('\n');
		}
		putchar('\n');
	}
	return 0;
}