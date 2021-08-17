#include<stdio.h>

void hanoi(int n, char A, char B, char C)
{
	//A is start C is end
	if (n > 0)
	{
		hanoi(n - 1, A, C, B);
		printf("%c -> %c\n",A,C);//move n,A,C
		hanoi(n - 1, B, A, C);
	}
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		hanoi(n, 'A', 'B', 'C');
		printf("\n");
	}
}
