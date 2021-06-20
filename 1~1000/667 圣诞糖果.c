#include<stdio.h> 

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x;
		scanf("%d",&x);
		if(!(x%6))
		{
			printf("Bob\n");
			continue;
		}
		printf("Alice\n");
	}
}
