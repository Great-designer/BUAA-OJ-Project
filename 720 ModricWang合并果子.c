#include<stdio.h>

unsigned long long q1[100010],q2[100010];
int front1,front2,rear1,rear2;
int bucket[100010];

void write(unsigned long long st)
{
	if(st>9)
	{
		write(st/10);
	}
	putchar(st % 10 + 48);
}

unsigned long long read()
{
	unsigned long long k = 0;
	char c = getchar();
	while (c < '0' || c>'9')
	{
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k;
}

int main()
{
	unsigned long long n = read();
	int i;
	for(i=1;i<=n;++i)
	{
		unsigned long long a = read();
		bucket[a]++;
	}
	for(i=1;i<100010;++i)
	{
		while(bucket[i])
		{
			bucket[i]--;
			q1[rear1]=i;
			rear1++;
		}
	}
	unsigned long long ans = 0;
	for(i=1;i<n;++i)
	{
		unsigned long long x, y;
		if(front2==rear2||(q1[front1]<q2[front2]&&front1!=rear1))
		{
			x=q1[front1];
			front1++;
		}
		else
		{
			x=q2[front2];
			front2++;
		}
		if(front2==rear2||(q1[front1]<q2[front2]&&front1!=rear1))
		{
			y=q1[front1];
			front1++;
		}
		else
		{
			y=q2[front2];
			front2++;
		}
		ans+=(x+y);
		q2[rear2]=x+y;
		rear2++;
	}
	write(ans);
	putchar('\n');
}
