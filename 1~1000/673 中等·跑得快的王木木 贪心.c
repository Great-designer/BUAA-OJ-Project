#include<stdio.h>
#include<limits.h>

/***********************************************
很容易写错的贪心类问题

1.走17米的操作越靠前越好
因为可以先获得体力，然后传送可使用的就更多了

2.光走17米还是比传送要慢
1000个17，用时1000，产生1000体力
同样用时1000，等两次传一次，则3秒60米回1点体力
循环一定次数，剩余时间休息，得到的体力比刚才还要多

所以说就是在这两种操作中进行调整

安全时间的上限是10000，以此做搜索即可
也就是先只走17，后面休息
只是要看从哪里开始走得最远，时间最少
***********************************************/
int m, s, t;
int maxDis, minTime;
char ans;

char solve(int m, int s, int t, int i)
{
	int time = 0, dis = 0;
	while (time < t && dis < s)
	{
		if (m < 10)m += 5;//此时只能休息
		else
		{
			m -= 9;
			dis += 60;
		}
		++time;
	}
	if (dis >= s)
	{
		if (minTime > time + i)minTime = time + i;
		return 1;
	}
	else
	{
		if (maxDis < dis + i * 17)maxDis = dis + i * 17;
		return 0;
	}
}

int main()
{
	while (scanf("%d%d%d",&m,&s,&t)!=EOF)
	{
		ans = 0;
		minTime = INT_MAX;
		maxDis = INT_MIN;
		for (int i = 0; i <= 10000 && t >= i && s - 17 * i >= 0; ++i)
		{
			ans |= solve(m + i, s - 17 * i, t - i, i);
		}
		if (ans)
		{
			printf("Yes\n%d\n",minTime);
		}
		else
		{
			printf("No\n%d\n",maxDis);
		}
	}

}
