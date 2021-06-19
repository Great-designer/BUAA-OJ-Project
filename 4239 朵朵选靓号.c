#include <stdio.h>

int main()
{
	long long num;
	int flag_233 = 0, cnt5 = 0;
	scanf("%lld", &num);
	while (num != 0)
	{
		if (num % 1000 == 233)
		{
			flag_233 = 1;
		}
		if (num % 10 == 5)
		{
			cnt5++;
		}
		num /= 10;
	}
	if (flag_233)
	{
		if (cnt5 < 3)
		{
			printf("Wonderful:%d", cnt5);
		}
		else
		{
			printf("Great:%d", cnt5);
		}
	}
	else
	{
		printf("Not good:%d", cnt5);
	}
	return 0;
}