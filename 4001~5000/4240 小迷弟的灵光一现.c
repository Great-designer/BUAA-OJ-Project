#include<stdio.h>

int arr[2000010] = {0};

int main()
{
	int n,i,ans = 0,ans1;
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		scanf("%d",arr + i);
		ans ^= arr[i];
	}
	if(n & 1) //奇数直接出答案
	{
		printf("%d\n",ans);
	}
	else
	{
		ans1 = ans;
		int pos = 1,k;
		for(k = 0; k < 32; k++) //找一位都是1的
		{
			if(ans1 & (1 << k))
			{
				pos = (1 << k);
				break;
			}
		}
		for(i = 0; i < n; i++)
		{
			if(arr[i] & pos) //如果那位上是1就异或ans1
			{
				ans ^= arr[i];
			}
			else //否则异或ans 此为 对原来所有数进行分类
			{
				ans1 ^= arr[i];
			}
		}
		if(ans < ans1) //先输出大的
		{
			printf("%d %d\n",ans,ans1);
		}
		else
		{
			printf("%d %d\n",ans1,ans);
		}
	}
	return 0;
}