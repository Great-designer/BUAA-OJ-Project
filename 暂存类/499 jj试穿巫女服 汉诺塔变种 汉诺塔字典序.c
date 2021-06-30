#include<stdio.h>

int n;

void hanoi(int n, char a, char b, char c, char isNotGet)
{
	if (n == 1)
	{
		printf("get dressup from board %c\n", a);
		if (isNotGet)
		{
			printf("dressing\n");
		}
		printf("put dressup to board %c\n", c);
	}
	else
	{
		hanoi(n - 1, a, c, b, isNotGet);
		printf("get dressup from board %c\n", a);
		if (isNotGet)
		{
			printf("dressing\n");
		}
		printf("put dressup to board %c\n", c);
		hanoi(n - 1, b, a, c, 0);
	}
}

char a = '1', b = '2', c = '3';
char isNotGet=1;

int main()
{
	while (~scanf("%d", &n))
	{
		if (n == 1)
		{
			printf("get dressup from board 1\ndressing\nput dressup to board 3\nleave\n");
		}
		else if (n == 2)
		{
			printf("get dressup from board 1\ndressing\nput dressup to board 2\nget dressup from board 1\ndressing\nput dressup to board 3\nleave\n");
		}
		else
		{
			hanoi(n - 2, a, c, b, 1);
			printf("get dressup from board 1\ndressing\nput dressup to board 3\nget dressup from board 1\ndressing\nput dressup to board 1\nleave\n");
		}
	}
}