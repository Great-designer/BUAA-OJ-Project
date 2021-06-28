#include<stdio.h>
#include<algorithm>

using namespace std;

int dp[25];
int fibo[10] = { 1,1,2,3,5,8,13,21 };

//感觉这道题还是斐波那契的变种
//在n=1,2,3的时候ans=0
//n=4的时候拿走4
//n=5的时候拿走4，1,2,3,5
//看到这里我觉得就基本没问题了...

void buildDP()
{
	dp[0] = dp[1] = dp[2] = dp[3] = 0;
	for (int i = 4; i < 25; ++i)
	{
		int* pos = lower_bound(fibo, fibo + 8, i);
		int offset = pos - fibo;
		if (fibo[offset] == i)dp[i] = i - offset;
		else dp[i] = i - offset + 1;
	}
}

int main()
{
	buildDP();
	int n;
	while (scanf("%d", &n) != EOF)
	{
		printf("%d\n", dp[n]);
	}
}