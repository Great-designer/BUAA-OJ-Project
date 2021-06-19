#include<stdio.h>

int main()
{
	int year, month, day, weekday, monthDays, leap, i;
	scanf("%d%d", &year, &month);
	if (month == 1 || month == 2)
	{
		year--;
		month += 12;
	}
	weekday = (year % 100 + year % 100 / 4 + year / 100 / 4 - 2 * (year / 100) + (13 * (month + 1) / 5));
	while (weekday < 0)
		weekday += 7;
	weekday %= 7;
	if (month > 12)
	{
		year++;
		month -= 12;
	}
	leap = 0;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		leap = 1;

	printf("%04d.%02d\n", year, month);
	for (int i = 0; i < 33; i++)
		printf("-");
	printf("  \n");
	printf("Sun  Mon  Tue  Wen  Thu  Fri  Sat  \n");
	for (int i = 0; i < 33; i++)
		printf("-");
	printf("  \n");

	for (i = 0; i < weekday; i = i + 1)
		printf("     ");
	if (month == 4 || month == 6 || month == 9 || month == 11)
		monthDays = 30;
	else if (month == 2)
	{
		if (leap == 1)
			monthDays = 29;
		else
			monthDays = 28;
	}
	else
		monthDays = 31;
	for (day = 1; day <= monthDays; day = day + 1)
	{
		printf("%-5d", day);
		weekday = weekday + 1;
		if (weekday == 7)
		{
			weekday = 0;
			printf("\n");
		}
	}
	return 0;
}