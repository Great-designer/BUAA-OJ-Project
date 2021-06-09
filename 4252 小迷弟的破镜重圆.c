#include<stdio.h>

int a[50010],fir[50010],las[50010],mo[50010],n,m,sum;

int main()
{
	scanf("%d %d",&n,&m);
	int i;
	for(i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
		sum=(sum+a[i])%m;
		mo[i]=sum;
	}
	for(i=0; i<=n; i++) las[mo[i]]=i; //这里从前向后记录  对于相同的mo[i]，las数组记录的一定是最后出现的
	for(i=n; i>=0; i--) fir[mo[i]]=i; //这里从后向前记录  对于相同的mo[i]，fir数组记录的一定是最先出现的

	int ans=0;
	for(i=0; i<m; i++) //结果中只可能出现0到m-1
	{
		if(las[i]-fir[i]>ans)
		{
			ans=las[i]-fir[i];//保存最大答案
		}
	}
	printf("%d",ans);
	return 0;
}