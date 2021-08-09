#include<stdio.h>

int isleap(int year)
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return 1;
	return 0;
}

int main()
{
	int year1, month1, day1, year2, month2, day2;
	int MonthOfYear[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int sum = 0;
		scanf("%d-%d-%d %d-%d-%d", &year1, &month1, &day1, &year2, &month2, &day2);
		if (year1 == year2)
		{
			if (month1 == month2)
			{
				if (day1 == day2)
				{
					printf("Today\n");
				}
				else if (day1 == day2 - 1)
				{
					printf("Yesterday\n");
				}
				else
				{
					printf("%d days ago\n", day2 - day1);
				}
			}
			else
			{
				sum -= day1;
				int t = month1, tt = isleap(year1);
				while (t != month2)
				{
					sum += MonthOfYear[tt][t];
					t++;
				}
				sum += day2;
				if (sum == 1)
					printf("Yesterday\n");
				else
					printf("%02d-%02d %d days ago\n", month1, day1, sum);
			}
		}
		else
		{
			int y = year1, yy;
			int t = 1;
			yy = isleap(year1);
			while (t != month1)
			{
				sum -= MonthOfYear[yy][t];
				t++;
			}
			sum -= day1;
			t = 1;
			while (y != year2)
			{
				if (isleap(y))
					sum += 366;
				else
					sum += 365;
				y++;
			}
			yy = isleap(year2);
			while (t != month2)
			{
				sum += MonthOfYear[yy][t];
				t++;
			}
			sum += day2;
			if (sum == 1)
				printf("Yesterday\n");
			else
				printf("%d-%02d-%02d %d days ago\n", year1, month1, day1, sum);
		}
	}
	return 0;
}

