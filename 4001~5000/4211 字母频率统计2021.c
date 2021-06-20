#include<ctype.h>
#include<stdio.h>

int freq[100] = {0};

int main()
{
	int c, count = 0, i;
	while ((c = getchar())!=EOF)
		if (isalpha(c))
		{
			int upper = toupper(c);
			freq[upper]++;
			count++;
		}
	for (i = 'A'; i <= 'Z'; i++)
	{
		if (!freq[i]) continue; // 忽略未出现过的字母
		double fre = freq[i] / (double)count;
		printf("%c %.2lf%%\n", i, fre * 100);
	}
}