#include<stdio.h>

int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
char isRun;
int counter;

int main()
{
	int yy, mm;
	int firstDay;
	while (scanf("%d%d", &yy, &mm) != EOF)
	{
		isRun = 0;
		int yyy = yy;
		int mmm = mm;
		if (mm < 3)
		{
			yyy--;
			mmm += 12;
		}
		int century = yyy / 100;
		int y = yyy - century * 100;
		firstDay = (y + y / 4 + century / 4 - 2 * century + 26 * (mmm + 1) / 10 + 1 - 1) % 7;
		while (firstDay < 0)
		{
			firstDay += 7;
		}
		firstDay %= 7;
		isRun = ((yy % 4 == 0 && yy % 100 != 0) || yy % 400 == 0);
		if (mm == 2)
		{
			counter = a[2] + isRun;
		}
		else
		{
			counter = a[mm];
		}
		printf(" Sun Mon Tue Wed Thu Fri Sat\n");
		for (int i = 0; i < firstDay; ++i)
		{
			printf("    ");
		}
		for (int i = 1; i <= counter; ++i)
		{
			printf("%4d", i);
			firstDay++;
			if (firstDay >= 7)
			{
				putchar('\n');
				firstDay = 0;
			}
		}
		putchar('\n');
	}
}
