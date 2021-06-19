#include<stdio.h>
#include<math.h>

int main()
{
	double a,b,c,d,e,f;
	char sym;
	while(scanf("(%lf%lfi)%c(%lf%lfi)",&a,&b,&sym,&c,&d)!=EOF)
	{
		//吃掉每行结尾多余的\n等字符，防止读取下一行开头(时卡住
		char ctemp=getchar();
		while(ctemp!='\n'&&ctemp!=EOF)
		{
			ctemp=getchar();
		}
		//基本switch-case语句
		switch(sym)
		{
			case '+':
				e=a+c;
				f=b+d;
				break;
			case '-':
				e=a-c;
				f=b-d;
				break;
			case '*':
				e=a*c-b*d;
				f=b*c+a*d;
				break;
			case '/':
				e=(a*c+b*d)/(c*c+d*d);
				f=(b*c-a*d)/(c*c+d*d);
				break;
		}
		//以下涉及浮点数大小比较，浮点数是否为整数的判断
		//如果实部为零
		if(fabs(e)<1e-5)
		{
			//如果实部虚部都为零
			if(fabs(f)<1e-5)
			{
				printf("0");
			}
			//虚部不为零 只输出虚部，没有前导"+"号
			//虚部为1 则只输出i
			else if(fabs(f-1)<1e-5)
			{
				printf("i");
			}
			//虚部为-1 则只输出-i
			else if(fabs(f+1)<1e-5)
			{
				printf("-i");
			}
			//虚部为整数，输出整数，没有前导"+"号
			else if(fabs(round(f)-f)<1e-5)
			{
				printf("%.0fi",f);
			}
			//虚部有小数部分，保留两位小数，没有前导"+"号
			else
			{
				printf("%.2fi",f);
			}
		}
		//如果实部不为零
		else
		{
			//正常输出实部
			if(fabs(round(e)-e)<1e-5)
			{
				printf("%.0f",e);
			}
			else
			{
				printf("%.2f",e);
			}
			//输出虚部  有前导"+"-"号
			//虚部为零 不输出
			if(fabs(f)<1e-5)
			{

			}
			//虚部为1 则只输出+i
			else if(fabs(f-1)<1e-5)
			{
				printf("+i");
			}
			//虚部为-1 则只输出-i
			else if(fabs(f+1)<1e-5)
			{
				printf("-i");
			}
			//以下对虚部为整数小数进行讨论，注意有前导+号
			else if(fabs(round(f)-f)<1e-5)
			{
				printf("%+.0fi",f);
			}
			else
			{
				printf("%+.2fi",f);
			}
		}
		printf("\n");
	}
	return 0;
}