#include<stdio.h>

int gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}

int a, b, l, ansa, ansb;

int main()
{
	while (scanf("%d%d%d", &a, &b, &l) != EOF)
	{
		ansa = l, ansb = 1;
		int i;
		for(i = 1; i <= l; ++i)
		{
			int j;
			for(j = 1; j <= l; ++j)
			{
				if (gcd(i, j) == 1 && i * b >= j * a && i * ansb < j * ansa)
				{
					ansa = i, ansb = j;
				}
			}
		}
		printf("%d %d\n", ansa, ansb);
	}
}