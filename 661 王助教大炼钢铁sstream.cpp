#include<stdio.h>
#include<math.h>

#include<sstream>
#include<iomanip>

using namespace std;

double round(double number,unsigned int bits)
{
	stringstream ss;
	ss << fixed << setprecision(bits) << number;
	ss >> number;
	return number;
}

int s,t,a,b;

double res()
{
	double tmp=s;
	double tmp2=1.0*t;
	double ret=(log(tmp/tmp2)/log(100.0/(100.0-a)));
	return ret;
}

double res2()
{
	double tmp=s*(100.0-b)/100.0;
	double tmp2=1.0*t;
	double ret=(log(tmp/tmp2)/log(100.0/(100.0-a)));
	return ret;
}

int main()
{
	while(~scanf("%d%d%d%d",&s,&t,&a,&b))
	{
		int flag=s%2;
		double a1=res();
		double a2=res2();
		if(flag)
		{
			printf("%.1f\n",a2);
		}
		else
		{
			printf("%.1f\n",a1);
		}
	}
}
