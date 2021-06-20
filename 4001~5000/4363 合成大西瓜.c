#include<stdio.h>

int main()
{
	int sum[1020]= {0};
	int a,i;
	while(scanf("%d",&a)!=EOF)
	{
		if(sum[a]==0)
			sum[a]=1;
		else
		{
			sum[a]=0;
			for(i=a+1; i<=1019; i++) //进位
			{
				if(sum[i]==1)
					sum[i]=0;
				else
				{
					sum[i]=1;
					break;
				}
			}
		}
		for(i=1019;; i--)
			if(sum[i]==1)
			{
				printf("%d\n",i);//输出最大的水果
				break;
			}
	}
	for(i=1019; i>=0; i--)
		if(sum[i]==1)
			printf("%d ",i);//输出全部水果
	return 0;
}