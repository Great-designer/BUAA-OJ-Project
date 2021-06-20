#include<stdio.h>

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

int main()
{
	int N;
	int num[1010];
	int cnt[3] = {0};
	int i;
	int cnt12=0,cnt13=0;
	int cnt21=0,cnt23=0;
	int cnt31=0,cnt32=0;
	int ans=0;
	scanf("%d",&N);
	for (i = 0; i < N; i++)
	{
		scanf("%d",&num[i]);
		cnt[num[i]-1]++;
	}
	for (i = 0; i < cnt[0]; i++)
	{
		if (num[i] == 2)
			cnt12++;
		else if (num[i] == 3)
			cnt13++;
	}
	for (int i = cnt[0]; i < cnt[0]+cnt[1]; i++)
	{
		if (num[i] == 1)
			cnt21++;
		else if (num[i] == 3)
			cnt23++;
	}
	for (int i = cnt[0]+cnt[1]; i < cnt[0]+cnt[1]+cnt[2]; i++)
	{
		if (num[i] == 1)
			cnt31++;
		else if (num[i] == 2)
			cnt32++;
	}
	ans += min(cnt12, cnt21);
	cnt12 -= min(cnt12, cnt21);
	cnt21 -= min(cnt12, cnt21);
	ans += min(cnt13, cnt31);
	cnt13 -= min(cnt13, cnt31);
	cnt31 -= min(cnt13, cnt31);
	ans += min(cnt23, cnt32);
	cnt23 -= min(cnt23, cnt32);
	cnt32 -= min(cnt23, cnt32);
	ans += ((cnt12 + cnt13)*2);
	printf("%d",ans);
	return 0;
}