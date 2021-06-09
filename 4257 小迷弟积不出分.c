#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double a, down, up, x, y;

int main()
{
	int num = 0, i;
	scanf("%lf %lf %lf", &a, &down, &up);
	for (i = 1; i <= 3000000; i++)
	{
		x = rand() % 32768 / 32768.0 * (up - down) + down;//这里很关键，貌似oj上的随机数产生了0~INT_MAX的数字 因此取模很有必要 不然会一直wa0.333
		y = rand() % 32768 / 32768.0;
		if (y < exp(a * x * x)) num++;
	}
	printf("%lf", num / 3000000.0 * (up - down));
	return 0;
}