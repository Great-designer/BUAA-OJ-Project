#include<stdio.h>
#include<string.h>

char laji[5];
char str[10005][505];
double score[10005];

int main()
{
	int n, m, i, flag;
	double tmp;
	char temp[5005];
	scanf("%d%d", &n, &m);
	gets(laji);
	for (i = 0; i < n; i++)
	{
		gets(str[i]);
		scanf("%lf", &score[i]);
		gets(laji);
	}
	for (i = 0; i < n - 1; i++)
	{
		flag = 0;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (score[j] < score[j + 1])
			{
				tmp = score[j];
				score[j] = score[j + 1];
				score[j + 1] = tmp;
				strcpy(temp, str[j]);
				strcpy(str[j], str[j + 1]);
				strcpy(str[j + 1], temp);
				flag = 1;
			}
		}
		if (0 == flag)
			break;
	}
	for (i = 0; i < m; i++)
	{
		puts(str[i]);
	}
}