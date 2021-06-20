#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct permutation
{
	char p[20];
	long long id;
};
struct permutation pl[100007];
long long pn[20], digit[256];

long long cantor(char *p, int n)
{
	long long u[20] = {0}, a, ans = 0;
	for (int i = 0; i < n; i++)
	{
		a = digit[p[i]];
		u[a] = 1;
		for (int j = 1; j <= digit[p[i]]; j++)
		{
			a -= u[j];
		}
		ans += a * pn[n - i - 1];
	}

	return ans + 1;
}

int cmp(const void *a, const void *b)
{

	struct permutation *pa = (struct permutation *) a;
	struct permutation *pb = (struct permutation *) b;
	if (pa->id < pb->id) return -1;
	else if (pa->id > pb->id) return 1;
	else return 0;
}

int lower_bound(struct permutation *p, int n)
{

	int l = 0, r = n, mid;
	while (l < r)
	{
		mid = (l + r) >> 1;
		if (cmp(p, &pl[mid]) <= 0)
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	return l;
}

void init(int n)
{

	pn[0] = 1;
	for (int i = 1; i <= n; i++)
		pn[i] = i * pn[i - 1];
	long long d = 0;
	for (char c = '0'; c <= '9'; c++)
		digit[c] = d++;
	for (char c = 'A'; c <= 'F'; c++)
		digit[c] = d++;
}

int main(int argc, const char * argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	init(n);
	for (int i = 0; i < m; i++)
	{
		scanf("%s", pl[i].p);
		pl[i].id = cantor(pl[i].p, n);
	}

	qsort(pl, m, sizeof(struct permutation), cmp);

	int q, k;
	struct permutation p;
	scanf("%d", &q);
	while (q--)
	{
		scanf("%s %d", p.p, &k);
		long long pos = cantor(p.p, n);
		long long l = pos - k < pn[1] ? pn[1] : pos - k;
		long long r = pos + k > pn[n] ? pn[n] : pos + k;
		p.id = l;
		int kl = lower_bound(&p, m);
		p.id = r + 1;
		int kr = lower_bound(&p, m);
		for (int i = kl; i < kr; i++)
		{
			printf("%s\n", pl[i].p);
		}
		if (kr <= kl)
		{
			printf("No such permutation.\n");
		}
	}
}