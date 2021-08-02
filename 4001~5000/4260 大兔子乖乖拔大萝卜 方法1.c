#include<stdio.h>
#include<string.h>

char first[10010], second[10010], third[10010], tmp[10010];
int n;

int bigger(char a[], char b[])
{
	int lena = strlen(a), lenb = strlen(b);
	if (lena != lenb)
	{
		return lena > lenb;//如果a的位数比b的位数大，那a一定比b大
	}
	//如果位数一致，直接从高到低比较
	//虽然是字符串 但是'0'到'9'的ASCII也是从小到大排列的，可以直接比较
	int i;
	for (i = 0; i < lena; ++i)
	{
		if (a[i] > b[i])
		{
			return 1;//大于
		}
		else if (a[i] < b[i])
		{
			return 0;//小于
		}
	}
	return 0;//如果相等，a不大于b，需要返回0
}

int main()
{
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", tmp);
		if (bigger(tmp, first))
		{
			strcpy(third, second);
			strcpy(second, first);
			strcpy(first, tmp);
		}
		else if (bigger(tmp, second))
		{
			strcpy(third, second);
			strcpy(second, tmp);
		}
		else if (bigger(tmp, third))
		{
			strcpy(third, tmp);
		}
	}
	puts(first);
	puts(second);
	puts(third);
}