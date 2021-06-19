#include<stdio.h>

int n, m, Ans;
int a[10005];

int main()
{
	int i, x, y;
	scanf("%d%d", &n, &m);
	for(i=1; i<=n; ++i)
		a[i] = 1;
	while(m --)
	{
		scanf("%d%d", &x, &y);
		for(i=x; i<=y; ++i)
			a[i] = 0;
	}
	for(i=1; i<=n; ++i)
		Ans += a[i];
	printf("%d", Ans);
	return 0;
}