#include<stdio.h>

void hanoi(int n, char A, char B, char C)
{
	//A is start C is end
	if (n > 0)
	{
		hanoi(n - 1, A, B, C);
		printf("%c -> %c\n",A,B);//move n,A,B
		hanoi(n - 1, C, B, A);
		printf("%c -> %c\n",B,C);//move n,B,C
		hanoi(n - 1, A, B, C);
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n;
		scanf("%d",&n);
		hanoi(n, 'A', 'B', 'C');
		printf("\n");
	}
}
