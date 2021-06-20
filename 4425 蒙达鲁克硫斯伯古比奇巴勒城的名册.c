#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct People
{
	int age, index;
	char name[1005];
};

struct People data[200005], *dataP[200005];

int cmp(const void *a, const void *b)
{
	struct People *p, *q;
	p = *((struct People **)a);
	q = *((struct People **)b);
	if (p->age == q->age)
	{
		return p->index - q->index;
	}
	else
	{
		return p->age - q->age;
	}
}

int main()
{
	int n,m, t,i;
	scanf("%d %d", &n,&m);
	for (i = 0; i < n; ++i)
	{
		scanf("%d %s", &data[i].age, data[i].name);
		dataP[i] = data + i;
		data[i].index = i;
	}
	qsort(dataP, n, sizeof dataP[0], cmp);
	for (i = 0; i < m; ++i)
	{
		scanf("%d",&t);
		t--;
		printf("%d %s\n", dataP[t]->age, dataP[t]->name);
	}
}