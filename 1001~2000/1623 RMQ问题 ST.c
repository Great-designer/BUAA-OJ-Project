#include<stdio.h>
#include<math.h>

int stmax[200005][20];

void init(int n)
{
	int j;
	for(j=1; j<=21; j++)
	{
		int i;
		for(i=1; i+(1<<(j-1))<=n; i++)
		{
			stmax[i][j]=stmax[i][j-1]>stmax[i+(1<<(j-1))][j-1]?stmax[i][j-1]:stmax[i+(1<<(j-1))][j-1];
		}
	}
}

int ST(int l,int r)
{
	int mm=log(1.0*(r-l))/log(2.0);//以2为底的对数，2的log2(r-l)次方等于(r-l);
	return ((stmax[l][mm]>stmax[r-(1<<mm)+1][mm])?stmax[l][mm]:stmax[r-(1<<mm)+1][mm]);//区间最大
}

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=1; i<=n; i++)
	{
		scanf("%d",&stmax[i][0]);
	}
	init(n);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int x1,y1;
		scanf("%d%d",&x1,&y1);
		printf("%d\n",ST(x1,y1));
	}
}
