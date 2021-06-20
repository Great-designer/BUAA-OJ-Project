#include<stdio.h>

int main()
{
	char a[20][20] = {0}, str[] = "\\duoduo!/";
	int n, i, j, k = 0, num=(sizeof(str)/sizeof(str[0]))-1;// 获取数组元素个数，由于字符串中末尾有'\0'，因此计算字符个数时应-1
	scanf("%d", &n);
	for (i = 0; i < (n + 1) / 2; i++)
	{
		for(j = i; j < n - i; j++)
		{
			a[i][j] = str[k];
			k = (k + 1) % num;
		}
		for(j = i + 1; j < n - i; j++)
		{
			a[j][n-i-1] = str[k];
			k = (k + 1) % num;
		}
		for(j = n - i - 2; j > i - 1; j--)
		{
			a[n-i-1][j] = str[k];
			k = (k + 1) % num;
		}
		for(j = n - i - 2; j > i; j--)
		{
			a[j][i] = str[k];
			k = (k + 1) % num;
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%c", a[i][j]);
		printf("\n");
	}
	return 0;
}