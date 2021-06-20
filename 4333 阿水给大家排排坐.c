#include<stdio.h>

int main()
{
	int n,i,j;
	double a[1100],temp;
	scanf("%d",&n);
	for(i=0; i<n; i++)
		scanf("%lf",&a[i]);
	for(i=0; i<n; i++)
		for(j=0; j<n-1-i; j++)
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
	for(i=0; i<n; i++)
	{
		if(a[i]==0)
		{
			printf("0.00000\n");
			continue;
		}
		printf("%.5f\n",a[i]);
	}
	return 0;
}