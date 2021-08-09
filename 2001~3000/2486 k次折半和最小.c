#include<stdio.h>

int frequency;

void adjust(int k[],int i,int n)/*调整子算法*/
{
	int j,temp;
	temp=k[i];
	j=2*i+1;
	while(j<n)
	{
		if(j<n-1&&k[j]<k[j+1])
		{
			j++;
		}
		frequency++;
		if(temp>=k[j])/*比较次数是指根元素调整过程中根元素与子树根结点的比较次数*/
		{
			break;
		}
		k[(j-1)/2]=k[j];
		j=2*j+1;
	}
	k[(j-1)/2]=temp;
}

int num[100005];

int main()
{
	int n,k;
	while(~scanf("%d %d",&n,&k))
	{
		int i;
		long long sum=0;
		int temp;
		for(i=0; i<n; i++)
		{
			scanf("%d",&num[i]);
			sum+=num[i];
		}
		for(i=n/2-1; i>=0; i--)
		{
			adjust(num,i,n);
		}
		for(i=0; i<k; i++)
		{
			temp=num[0];
			num[0]/=2;
			sum-=(temp-num[0]);
			adjust(num,0,n);
		}
		printf("%lld\n",sum);
	}
}
