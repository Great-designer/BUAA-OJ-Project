#include<stdio.h>
#include<string.h>
#include<ctype.h>

char str[1010];
char ans[3][1010];
int cnt[3];

int main()
{
	int test;
	scanf("%d", &test);
	while(test --)
	{
		scanf("%s", str);
		int n = strlen(str), i, type;
		cnt[0] = cnt[1] = cnt[2] = 0;
		for(i = 0; i < n; ++ i)
		{
			if(isalpha(str[i])) type = 0;
			else if(isdigit(str[i])) type = 1;
			else type = 2;
			ans[type][cnt[type] ++] = str[i];
		}
		for(i = 0; i < 3; ++ i)
		{
			ans[i][cnt[i]] = '\0';
			printf("%s", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
