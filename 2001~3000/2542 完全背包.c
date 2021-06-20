#include<stdio.h>
#include<string.h>

int c[550];/*第i件物品的占用空间是c[i]，价值是w[i]。*/ 
int w[550];
int f[30300];

int main()
{
	int n,v;/*有N件物品和一个容量为V的背包。每种物品可选无限件，求解将哪些物品装入背包可使价值总和最大。*/ 
	while(~scanf("%d%d",&n,&v))
	{
		int i;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&c[i],&w[i]);
		}
		memset(f,0,sizeof(f)); 
		for(i=1;i<=n;i++)/*数学归纳法：取多少件c[i]*/
		{
			int j;
			for(j=c[i];j<=v;j++)/*每次从小往大调用c[i]数据并更新，需要一个可能已选入第i种物品的子结果f[j-c[i]]*/
			{
				f[j]=(f[j]>(f[j-c[i]]+w[i])?f[j]:(f[j-c[i]]+w[i]));/*前i件物品恰放入一个容量为j的背包可以获得的最大价值*/
			}
		}
		printf("%d\n",f[v]);
	}
}
