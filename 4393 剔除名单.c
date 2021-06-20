#include <stdio.h>
#include <string.h>

int decbj(char *str, int n)
{
	int i, j = 0;
	int pos[3] = {0};
	char *cbj = "cbj";
	for (i = 0; i < n; i++)
	{
		if (str[i] == cbj[j])
		{
			pos[j] = i;
			j++;
			if (j >= 3)
			{
				str[pos[0]] = '\t';
				str[pos[1]] = '\t';
				str[pos[2]] = '\t';
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	char str[1024] = {0};
	fgets(str, 1024, stdin);
	int i, l = strlen(str);
	while (decbj(str, l)) ;
	for (i = 0; str[i]; i++)
	{
		if (str[i] != '\t')
			putchar(str[i]);
	}
	return 0;
}