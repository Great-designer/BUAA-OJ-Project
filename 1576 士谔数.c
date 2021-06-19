#include<stdio.h>

int s(int n)
{
	int c,a,b;
	c=0;
	b=n/10;
	c+=b;
	c*=4;
	a=n%10;
	if(a>=1&&a<3)
		c++;
	if(a>=3&&a<7)
		c+=2;
	if(a==7)
		c+=3;
	if(a>=8)
		c+=4;
	return c;
}

int main()
{
    int l,r;
    scanf("%d %d",&l,&r);
    printf("%d",s(r)-s(l-1));
}
