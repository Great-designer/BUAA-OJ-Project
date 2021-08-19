#include<stdio.h>

int main()
{
	double a[10],sum=0,ave;
	int i,n=0;
	for(i=0; i<10; i++)
		scanf("%lf",&a[i]);
	for(i=0; i<10; i++)
		sum+=a[i];
	ave=sum/10.0;
	for(i=0; i<10; i++)
		if(a[i]>ave)
			n++;
	printf("%.3lf\n",ave);
	printf("%d\n",n);
	return 0;
}
