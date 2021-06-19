#include<stdio.h>
#include<string.h>

char first[10010], second[10010], third[10010], tmp[10010];
int n;

int bigger(char *a, char *b)
{
	int lena = strlen(a), lenb = strlen(b);
	if (lena != lenb) return lena > lenb;
	else return strcmp(a, b) > 0;
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