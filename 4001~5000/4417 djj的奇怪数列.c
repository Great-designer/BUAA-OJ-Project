#include<stdio.h>

long long queue[1000005]= {1,2,3,4,5};
int n;
int head,tail=5;

int main(void)
{
	scanf("%d",&n);
	while(1)
	{
		if(queue[head]%n==0)
		{
			printf("%lld\n",queue[head]);
			break;
		}
		long long temp=queue[head];
		switch (temp%10)
		{
			case 1:
				queue[tail++]=temp*10+3;
				queue[tail++]=temp*10+5;
				break;
			case 2:
				queue[tail++]=temp*10+3;
				queue[tail++]=temp*10+4;
				break;
			case 3:
				queue[tail++]=temp*10+1;
				queue[tail++]=temp*10+4;
				break;
			case 4:
				queue[tail++]=temp*10+5;
				break;
			case 5:
				queue[tail++]=temp*10+1;
				queue[tail++]=temp*10+2;
				queue[tail++]=temp*10+3;
				queue[tail++]=temp*10+4;
				queue[tail++]=temp*10+5;
				break;
			default:
				break;
		}
		head++;
	}
}