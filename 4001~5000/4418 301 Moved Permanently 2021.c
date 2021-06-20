#include <stdio.h>

int main()
{
	freopen("301.txt", "w", stdout);
	int n, op, i;
	long long a1, b1;
	double a2, b2;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &op);
		if (op == 1 || op == 2)
		{
			scanf("%lld%lld", &a1, &b1);
			printf("%lld", a1 + b1);
		}
		else
		{
			scanf("%lf%lf", &a2, &b2);
			printf("%.4f", a2 + b2);
		}
		if (i != n)
			printf("\n");
	}
	return 0;
}