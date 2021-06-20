#include <stdio.h>

int max4(int a, int b, int c, int d)
{
	int max = a;
	max = b > max ? b : max;
	max = c > max ? c : max;
	max = d > max ? d : max;
	return max;
}

int gcd(int a, int b)
{
	if (b)
		while ((a %= b) && (b %= a));
	return a + b;
}

int main()
{
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int m1 = max4(a, b, c, d);
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int m2 = max4(a, b, c, d);
	printf("%d\n", gcd(m1, m2));
	return 0;
}