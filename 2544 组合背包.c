#include<stdio.h>
#include<string.h>
 
int c[550];/*第i件物品的占用空间是c[i]，价值是w[i]。*/ 
int w[550];
int m[550],f[2][30005],q[500005];
 
int main()
{
	int n,v;
	while(~scanf("%d%d",&n,&v))/*有N种物品和一个容量为V的背包*/
	{
		int i; 
		for(i=1;i<=n;i++)/*第i种物品每件费用是c[i]，价值是w[i]，最多有m[i]件可用*/
		{
		    scanf("%d%d%d",&c[i],&w[i],&m[i]);
		}
		memset(f,0,sizeof(f));
		memset(q,0,sizeof(q));
		for(i=1;i<=n;i++)/*数学归纳法：放c[i]。f[now][v]表示前i种物品恰放入一个容量为v的背包的最大价值*/
		{
			int now=i%2,last;/*c[i-1]数据在last里*/
			last=now^1;
			int j;
			if(m[i]==1)
			{
				for(j=v;j>=c[i];j--)/*每次从大往小调用c[i-1]数据并更新*/
				{
					f[now][j]=(f[last][j]>(f[last][j-c[i]]+w[i])?f[last][j]:(f[last][j-c[i]]+w[i]));/*前i件物品恰放入一个容量为j的背包可以获得的最大价值*/
				}
				for(j=0;j<c[i];j++)/*补丁*/
				{
					f[now][j]=f[last][j];
				}
			}
		    else if(m[i]==233)
		    {
		    	for(j=0;j<c[i];j++)/*补丁*/
				{
					f[now][j]=f[last][j];
				}
				for(j=c[i];j<=v;j++)/*每次从小往大调用c[i]数据并更新，需要一个可能已选入第i种物品的子结果f[j-c[i]]*/
				{
					f[now][j]=(f[last][j]>(f[now][j-c[i]]+w[i])?f[last][j]:(f[now][j-c[i]]+w[i]));/*前i件物品恰放入一个容量为j的背包可以获得的最大价值*/
				}
			}
		    else
		    {
			    for(j=0;j<c[i];j++)/*j的意义变为余数，k*c[i]+j是总数，每次从小往大调用c[i-1]数据并更新*/
				{
					//f[now][k*c[i]+j]
					//=max{f[last][j]+k*w[i]|0<=k<=m[i]}
					//=max(f[last][k*c[i]+j],f[last][j]+k*w[i])
					//=max(f[last][k*c[i]+j],f[last][q[Front]*c[i]+j]+(k-q[Front])*w[i])
			        int Rear=1,Front=1;
			        q[1]=0;
			        int k;
			        for(k=0;k*c[i]+j<=v;k++)/*取到了最大的f[last][j]+k*w[i]时，再往下取k就没有意义了*/
					{
			            while(Front!=Rear&&k-q[Front]>m[i])/*维护一个单调队列，队列中存的是k，使队首为最大值，每次把超出m[i]队首删去*/
						{
							Front++;
						}
			            f[now][k*c[i]+j]=(f[last][k*c[i]+j]>(f[last][q[Front]*c[i]+j]+(k-q[Front])*w[i])?f[last][k*c[i]+j]:(f[last][q[Front]*c[i]+j]+(k-q[Front])*w[i]));
			            while(Front<=Rear&&f[last][q[Rear]*c[i]+j]+w[i]*(k-q[Rear])<=f[last][k*c[i]+j])/*把队尾小于枚举的f[last][j]+k*w[i]删去*/
						{
							Rear--;
						}
			            q[++Rear]=k;/*记录当前取了多少个该物品*/
			        }
			    }
			}
		}
		printf("%d\n",f[n%2][v]);
	}
	return 0;
}
