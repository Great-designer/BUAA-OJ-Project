#include<stdio.h>

#include<algorithm>
#include<queue>

using namespace std;

int a[4010*4010];
int b[4010];
int temp[4010];
int n,k;

void mergesort(int lo,int hi,int *N)
{
	if(hi>lo+1)
	{
		int mi=(hi+lo)>>1;
		mergesort(lo,mi,N);
		mergesort(mi,hi,N);
		int tempmark=lo;
		int lomark=lo;
		int himark=mi;
		while(lomark<mi||himark<hi)
		{
			if((N[lomark]<=N[himark]||himark>=hi)&&lomark<mi)
			{
				temp[tempmark++]=N[lomark++];
			}
			else
			{
				temp[tempmark++]=N[himark++];
			}
		}
		int i; 
		for(i=lo;i<hi;i++)
		{
			N[i]=temp[i];
		}
	}
	return;
}

struct Sum
{
	int sum,bmark;
	Sum(int s=0,int b=0)
	{
		sum=s;
		bmark=b;
	}
	bool operator < (const Sum &b) const
	{
		return sum>b.sum;
	}
};

void mergequeue(int *A,int *B,int *C,int limit)
{
	priority_queue<struct Sum> queue;
	int counter=0;
	int i;
	for(i=0;i<n;++i)
	{
		queue.push(Sum(A[i]+B[0],0));
	}
	for(i=0;i<limit;++i)
	{
		Sum smallest=queue.top();
		queue.pop();
		C[i]=smallest.sum;
		int b=smallest.bmark;
		if(b+1<n)
		{
			queue.push(Sum(smallest.sum-B[b]+B[b+1],b+1));
		}
	}
}

int main()
{
	while(~scanf("%d%d",&n,&k))
	{
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		mergesort(0,n,a);
		for(i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
		}
		mergesort(0,n,b);
		mergequeue(a,b,a,k);
		printf("%d\n",a[k-1]);
	}
}
