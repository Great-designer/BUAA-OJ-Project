#include<stdio.h>
#include<math.h>

int main()
{
	double wentai, data[1000] = {0};
	int i = 0;
	scanf("%lf", &wentai);
	while (scanf("%lf", &data[i]) != EOF)
	{
		i++;
	}
	for (i = i - 1; i >= 0; i--)
	{
		// 离开误差带时跳出循环
		if (fabs(data[i] - wentai) > 0.05 * wentai)
		{
			break;
		}
	}
	printf("%.2lf\n", 0.03 * (i + 1));
	return 0;
}