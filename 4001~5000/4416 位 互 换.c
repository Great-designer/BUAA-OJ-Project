#include <stdio.h>

int main()
{
	int a, m, n;
	while (scanf("%d%d%d", &a, &m, &n) != EOF)
	{
		//分别提取第m n位
		int m_bit = (a & (1 << m)) >> m;
		int n_bit = (a & (1 << n)) >> n;
		//指定位置零
		a &= ~(1 << m);
		a &= ~(1 << n);
		//指定位置指定数
		a |= m_bit << n;
		a |= n_bit << m;
		//输出
		printf("%d\n", a);
	}
	return 0;
}