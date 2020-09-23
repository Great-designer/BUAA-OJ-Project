#include <stdio.h>

int main()
{
    double xa,ya,xb,yb,xc,yc;
    scanf("%lf%lf%lf%lf%lf%lf",&xa,&ya,&xb,&yb,&xc,&yc);
    double d,dx,dy;
    double a,b,c;
    a=xa*xa+ya*ya;
    b=xb*xb+yb*yb;
    c=xc*xc+yc*yc;
    d=2*xa*2*yb+2*xb*2*yc+2*xc*2*ya-2*xc*2*yb-2*xb*2*ya-2*xa*2*yc;
    dx=a*2*yb+b*2*yc+c*2*ya-c*2*yb-b*2*ya-a*2*yc;
    dy=2*xa*b+2*xb*c+2*xc*a-2*xc*b-2*xb*a-2*xa*c;
    double x,y;
    x=dx/d;
    y=dy/d;
    if(-x<1e-5&&x<=0)
    {
    	x=0;
	}
    if(-y<1e-5&&y<=0)
    {
    	y=0;
	}
    printf("(%.2lf,%.2lf)",x,y);
}
