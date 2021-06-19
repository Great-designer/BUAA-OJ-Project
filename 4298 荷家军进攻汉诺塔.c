#include<stdio.h>

void hanoi(int n, char from, char via, char to)// 把n个盘子从柱子 a 通过 b 挪到 c 上
{
	if (n == 1)
	{
		move(n, from, to);
		return;
	}
	hanoi(n - 1, from, to, via); // 把n-1个盘子从from通过
	move(n, from, to);
	hanoi(n - 1, via, from, to);
}

void move(int n, char from, char to) // 把第n号盘子从柱子a挪到c上
{
	printf("move %d from %c to %c\n", n, from, to);
}

int main()
{
	int num;
	char a, b, c;

	// freopen("out2.txt","w",stdout);

	scanf("%d %c %c %c",&num,&a,&b,&c);
	hanoi(num, a, b, c);
	return 0;
}

