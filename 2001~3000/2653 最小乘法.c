#include<stdio.h>
#include<string.h>

int n[20];

long long compute(int j,int z)
{
	long long a=n[j];
	int i;
	for(i=j+1; i<=z; i++)
	{
		a=a*10+n[i];
	}
	return a;
}

long long f[20][20];
char s[20];

int main()
{
	int c;
	while(scanf("%d",&c)!=EOF)
	{
		scanf("%s",s);
		memset(f,0,sizeof(f));
		int len=strlen(s);
		int i;
		for(i=0; i<len; i++)
		{
			n[i]=s[i]-'0';
		}
		f[0][0]=n[0];
		for(i=1; i<len; i++)
		{
			f[i][0]=f[i-1][0]*10+n[i];
		}
		int k;
		for(k=1; k<=c; k++) // 枚举乘号的个数
		{
			for(i=k; i<len; i++)
			{
				long long a=-1;
				int j;
				for(j=k-1; j<i; j++)
				{
					long long b=f[j][k-1]*compute(j+1,i);
					if(a<b)
					{
						a=b;
					}
				}
				f[i][k]=a;
			}
		}
		printf("%lld\n",f[len-1][c]);
	}
	return 0;
}
