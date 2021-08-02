#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char pl[100007][20];

//sgn == 1  next
//sgn == -1 previous

int next_prev_p(char *p, int n, int sgn)
{
	int j = n - 1, i = n - 2;
	while ((p[i] - p[j]) * sgn > 0)
	{
		i--;
		j--;
		if (i < 0)
		{
			return 0;
		}
	}
	int k;
	for (k = n - 1; k > i; k--)
	{
		if ((p[k] - p[i]) * sgn > 0)
		{
			char temp = p[k];
			p[k] = p[i];
			p[i] = temp;
			int x = j, y = n - 1;
			while (x - y < 0)
			{
				char temp = p[x];
				p[x] = p[y];
				p[y] = temp;
				x++;
				y--;
			}
			break;
		}
	}
	return 1;
}

int cmp(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}

int lower_bound(char *key, int n)
{
	int l = 0, r = n, mid;
	while (l < r)
	{
		mid = (l + r) >> 1;
		if (strcmp(key, pl[mid]) <= 0)
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

int upper_bound(char *key, int n)
{
	int l = 0, r = n, mid;
	while (l < r)
	{
		mid = (l + r) >> 1;
		if (strcmp(key, pl[mid]) >= 0)
		{
			l = mid + 1;
		}
		else
		{
			r = mid;
		}
	}
	return l;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int i;
	for (i = 0; i < m; i++)
	{
		scanf("%s", (char *)(&pl[i]));
	}
	qsort(pl, m, sizeof(pl[0]), cmp);
	int q, k;
	char l[20], r[20];
	scanf("%d", &q);
	while (q--)
	{
		scanf("%s %d", l, &k);
		strcpy(r, l);
		int rl = 1, rr = 1;
		while (k-- && (rl || rr))
		{
			rl = next_prev_p(l, n, -1);
			rr = next_prev_p(r, n, 1);
		}
		int kl = lower_bound(l, m), kr = upper_bound(r, m);
		for (i = kl; i < kr; i++)
		{
			printf("%s\n", pl[i]);
		}
		if (kr <= kl)
		{
			printf("No such permutation.\n");
		}
	}
}