#include<stdio.h>
#include<string.h>

void wr(int x)
{
	if (x < 0)
		putchar('-'), x = -x;

	if (x > 9)
		wr(x / 10);

	putchar(x % 10 + 48);
}

int rd()
{
	int k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-')
			f = -1;

		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}

void print(const char* a)
{
	int i = 0, len = strlen(a);
	while (i < len) putchar(a[i++]);
}

int heap[(114514 << 1)];
int heap_size;

void swap(int* a, int* b)
{
	if ((*a) != (*b))
		(*a) ^= (*b), (*b) ^= (*a), (*a) ^= (*b);
}

void perlocate_up(int lo, int hi)
{
	//上滤操作,堆区间为[lo,hi] hi为刚刚插入的末尾
	int son = hi;
	int dad = (hi - 1) >> 1;
	while (son > 0)
	{
		if (heap[dad] <= heap[son])
			break;
		else
		{
			swap(&heap[dad], &heap[son]);
			son = dad, dad = (son - 1) >> 1;
		}
	}
}

void perlocate_down(int lo, int hi)
{
	//下滤操作,堆区间为[lo,hi] lo为堆的根
	int dad = lo;
	int son = (dad << 1) + 1;
	while (son <= hi)
	{
		if (son + 1 <= hi && heap[son] > heap[son + 1])
			son++;//如果存在双分支,选择其中较小者进行下滤

		if (heap[dad] <= heap[son])
			break;//此时如果堆序性正确,则整个堆都正确,直接停机
		else
		{
			swap(&heap[dad], &heap[son]);
			dad = son, son = (dad << 1) + 1;
			//调整,并且根据下滤的节点继续往下看
		}
	}
}

void push(int x)
{
	heap[heap_size++] = x;
	if (heap_size > 1)
		perlocate_up(0, heap_size - 1);
}

void pop()
{
	heap[0] = heap[--heap_size];
	heap[heap_size] = 0;
	if (heap_size > 1)
		perlocate_down(0, heap_size - 1);
}

int top()
{
	return heap_size > 0 ? heap[0] : -1;
}

int T, t;
int n, k, x, i;

int main()
{
	T = rd();
	for (t = 1; t <= T; ++t)
	{
		while (heap_size) pop();
		n = rd(), k = rd();
		if (k > n)k = n;
		for (i = 1; i <= k; ++i)push(rd());
		print("Case #"), wr(t), print(":\n");
		for (i = k + 1; i <= n; ++i)
			push(rd()), wr(top()), putchar('\n'), pop();
		for (i = 1; i <= k; ++i)
			wr(top()), putchar('\n'), pop();
	}
}