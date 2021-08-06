#include<stdio.h>
#include<math.h>

#include<bitset>
#include<algorithm>

using namespace std;

int p[350005/10],tot,res[350005];
bitset<350005> vis;
long long n;

void pre(int n)
{
	int i;
	for(i=2; i<=n; i++)
	{
		res[i]=res[i-1];
		if (!vis[i])
		{
			p[++tot]=i;
			res[i]++;
		}
		int j;
		for (j=1; j<=tot && (long long)i*p[j]<=n; j++)
		{
			vis[i*p[j]]=1;
			if (i%p[j]==0)
			{
				break;
			}
		}
	}
}

int sn,pos,cnt,last[350005<<1];
long long g[350005<<1],value[350005<<1];

long long cal(long long n) //洲阁筛
{
	cnt=0;
	sn=(long long)sqrt((long double)n);//考虑<=n的数由<=sqrtn的质数筛出的情况
	pos=upper_bound(p+1,p+1+tot,sn)-p-1;//pos第一个小于等于sn的质数位置
	long long i;
	for (i=n; i>=1; i=n/(n/i+1))
	{
		value[++cnt]=n/i;//记录所有[n/i]的值，只有这样的数才会出现在转移中 //离散
	}
	//g[i][j]表示1~j中与前i个质数互质的数的个数 //筛不掉的
	//g[i][j]=g[i-1][j]-g[i-1][j/p[i]]
	//当p[i+1]>j时，g[i][j]=1 //只有1
	//p[i]>j/p[i]时，g[i][j]=g[i-1][j]-1，可以O(1)计算
	long long k;
	for(i=1; i<=cnt; i++)
	{
		g[i]=value[i];
		last[i]=0;//注意初始化last[i]=0
	}
	for(i=1; i<=pos; i++)
	{
		int j;
		for(j=cnt; j>=1; j--)
		{
			k=value[j]/p[i];
			if (k<p[i])
			{
				break;//忽略那些-1的转移
			}
			k=k<sn?k:cnt-n/k+1;//找到在value中的对应下标
			g[j]-=g[k]-(i-last[k]-1);//将g[k]的-1的转移补回去
			last[j]=i;
		}
	}
	return res[sn]+g[cnt]-1;//-1是减去1的贡献
}

int main()
{
	pre(350000);
	scanf("%lld",&n);
	printf("%lld\n",cal(n));
	return 0;
}
