#include<stdio.h>

void hanoi(int n, char from, char via, char to)// 把n个盘子从柱子 a 通过 b 挪到 c 上
{
    if (n == 1)
    {
        printf("move %d from %c to %c\n", n, from, to);
        return;
    }
    hanoi(n - 1, from, to, via); // 把n-1个盘子从from通过
    printf("move %d from %c to %c\n", n, from, to);
    hanoi(n - 1, via, from, to);
}

int main()
{
    int num;
    char a, b, c;
    scanf("%d %c %c %c", &num, &a, &b, &c);
    hanoi(num, a, b, c);
    return 0;
}

