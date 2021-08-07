#include<stdio.h>

int a[2][3];

int main()
{
	int ThreeGreat;
	double GPA;
	while(scanf("%d%lf%d%d%d%d%d%d",&ThreeGreat,&GPA,&a[0][0],&a[0][1],&a[0][2],&a[1][0],&a[1][1],&a[1][2])!=EOF)
	{
		char isOK=0;
		double av1=(a[0][0]+a[0][1]+a[0][2])/3.0;
		double av2=(a[1][0]+a[1][1]+a[1][2])/3.0;
		if(ThreeGreat)
		{
			if(GPA>=3.5||(av1>=80.0&&av2>=80.0))
			{
				isOK=1;
			}
		}
		else
		{
			if(GPA>=3.6||(av1>85.0&&av2>85.0))
			{
				isOK=1;
			}
		}
		if(isOK)
		{
			printf("APPROVED\n");
		}
		else
		{
			printf("REJECTED\n");
		}
	}
}
