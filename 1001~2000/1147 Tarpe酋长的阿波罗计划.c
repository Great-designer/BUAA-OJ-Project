#include<stdio.h>

int main()
{
	double a,b,c,d; //输入数据可能是小数，double 类型
	while(~scanf("%lf%lf%lf%lf",&a,&b,&c,&d))
	{
		double velocity = b + c + d; //首先计算速度
		if(velocity<0.8) //速度无法达到，直接输出“Out of reach\n"
		{
			printf("Out of reach\n"); //换行符
		}
		else
		{
			double x1,x2,x3; //准备三个变量，
			if(b>c) //先假设一种情况，比如 b>c
			{
				if(b>d) //如果 b>d,确定 b 为最大值
				{
					x3 = b;
					if(d>c) //确定中间两个值
					{
						x2 = d;
						x1 = c;
					}
					else
					{
						x2 = c;
						x1 = d;
					}
				}
				else
				{
					x3 = d;
					x2 = b;
					x1 = c;
				}
			}
			else
			{
				if(c>d)
				{
					x3 = c;
					if(d>b)
					{
						x2 = d;
						x1 = b;
					}
					else
					{
						x2 = b;
						x1 = d;
					}
				}
				else
				{
					x3 = d;
					x2 = c;
					x1 = b;
				}
			}
			printf("%.1f %.1f %.1f\n",x1,x2,x3); //打印结果 注意空格和换行
			printf("%.1f\n",a/velocity);
		}
	}
}