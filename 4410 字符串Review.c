#include<stdio.h>
#include<string.h>

void in_process(char *s)
{
	int len = (int)strlen(s);
	if (s[len-1] == '\r')
		s[len-1] = '\0';
	return;
}

int main()
{
	int n, i;
	char s[1000][105] = {0}, str[105000] = {0}, substr[105] = {0}, *p, *q;
	scanf("%d", &n);
	while (getchar() != '\n');
	for (i = 0; i < n; i++)
	{
		gets(s[i]);
		in_process(s[i]);
	}
	gets(substr);
	in_process(substr);

	for (i = n - 1; i >= 0; i--)
		strcat(str, s[i]);
	printf("%s\n", str);
	p = strstr(str, substr);
	q = p;
	if (p != NULL)
	{
		while (p)
		{
			q = p;
			p = strstr(p + 1, substr);
		}
		printf("%ld\n", q - str + 1);
	}
	else
	{
		printf("nothing\n");
	}
	return 0;
}