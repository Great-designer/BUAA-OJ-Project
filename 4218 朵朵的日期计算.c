#include<stdio.h>
#include<stdlib.h>

int main()
{
	int year, month = 5, day, birth_year, birth_month, birth_day, s1 = 0, s2 = 0, i, week, y, c;
	unsigned int d[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 把每个月的天数用数组储存起来
	scanf("%d", &year);
	scanf("%d%d%d", &birth_year, &birth_month, &birth_day);
	// 令day = 1，运用Zeller公式查询当年5月1日是星期几，注意Zeller公式的使用限定条件
	day = 1;
	y = year % 100;
	c = year / 100;
	week = (y + y/4 + c/4 - 2*c + 13*(month+1)/5 + day - 1) % 7;
	if (week < 0)
		week += 7;
	if (week == 0)
		day = 8;
	else
		day = 15-week;
	if((year%4 == 0 && year%100 != 0) || year%400 == 0)
		d[2] = 29;  // 若year年为闰年，修改2月的天数
	// year年母亲节，即5月day日与当年1月1日相差天数s1
	for (i = 0; i < 5; i++)
		s1 += d[i]; //相差的整月天数
	s1 += day;
	// year年母亲生日，与当年1月1日相差天数s2
	for (i = 0; i < birth_month; i++)
		s2 += d[i]; //相差的整月天数
	s2 += birth_day;
	printf("%d\n%d\n", day, abs(s1-s2));
	return 0;
}