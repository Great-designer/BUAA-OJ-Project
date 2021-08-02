#include <stdio.h>

int main()
{
	char a[100];
	int len;
	scanf("%s", a); //读入一行字符串
	for (len = 0; a[len] != '\0'; len++) //将各位数字字符转换为数值
	{
		a[len] -= '0';
	}
	int k;
	while (~scanf("%d", &k)) //循环读入k
	{
		//计算bias = 2^(k - 1) - 1
		int bias = 1;
		int i;
		for (i = 0; i < k - 1; i++)
		{
			bias *= 2;
		}
		bias -= 1;
		//计算E
		double E = 0, b = 1;
		for (i = k; i >= 1; i--)
		{
			E += a[i] * b;
			b *= 2;
		}
		//计算F
		double F = 1;
		b = 1.0 / 2;
		for (i = k + 1; i <= len; i++)
		{
			F += a[i] * b;
			b /= 2;
		}
		//计算 x = (-1)^s * F * 2^(E-bias)
		double x = (a[0] == 0 ? 1 : -1) * F, Eb = (E - bias) > 0 ? (E - bias) : (bias - E);
		b = (E - bias) > 0 ? 2 : 0.5;
		for (i = 0; i < Eb; i++)
		{
			x *= b;
		}
		//输出
		printf("%.8lf\n", x);
	}
}