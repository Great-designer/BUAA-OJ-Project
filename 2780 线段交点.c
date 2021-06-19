#include<stdio.h>
#include<math.h>

struct point
{
    double x,y;
};

double Cross(struct point a,struct point b)
{
	return a.x*b.y-a.y*b.x;
}

double Dot(struct point a,struct point b)
{
	return a.x*b.x+a.y*b.y;
}

double dis(struct point p)
{
    return sqrt(p.x*p.x+p.y*p.y);
}

char on_seg(struct point p1,struct point p2,struct point a)//判断点a是否在p1, p2构成的线段上，如果包括在端点也算在线段上
{
	struct point temp1;
	temp1.x=p1.x-a.x;
	temp1.y=p1.y-a.y;
	struct point temp2;
	temp2.x=p2.x-a.x;
	temp2.y=p2.y-a.y;
    return Cross(temp1,temp2)==0&&Dot(temp1,temp2)<=0;
}

char is_cross(struct point a1,struct point a2,struct point b1,struct point b2)//判断线段a1, a2与线段b1, b2是否相交（包括端点相交）
{
    if(on_seg(b1,b2,a1)||on_seg(b1,b2,a2)||on_seg(a1,a2,b1)||on_seg(a1,a2,b2))
    { 
        return 1;
    }
    struct point temp1;
	temp1.x=a2.x-a1.x;
	temp1.y=a2.y-a1.y;
	struct point temp2;
	temp2.x=b1.x-a1.x;
	temp2.y=b1.y-a1.y;
	struct point temp3;
	temp3.x=b2.x-a1.x;
	temp3.y=b2.y-a1.y;
    double d1=Cross(temp1,temp2);
    double d2=Cross(temp1,temp3);
    struct point temp4;
	temp4.x=b2.x-b1.x;
	temp4.y=b2.y-b1.y;
	struct point temp5;
	temp5.x=a1.x-b1.x;
	temp5.y=a1.y-b1.y;
	struct point temp6;
	temp6.x=a2.x-b1.x;
	temp6.y=a2.y-b1.y;
    double d3=Cross(temp4,temp5);
    double d4=Cross(temp4,temp6);
    if(d1*d2<0&&d3*d4<0)
    { 
        return 1;
    } 
    return 0;
}

struct point Projection(struct point a1,struct point a2,struct point p)
{
	struct point temp1;
	temp1.x=a2.x-a1.x;
	temp1.y=a2.y-a1.y;
    struct point e;
	e.x=temp1.x/dis(temp1);
	e.y=temp1.y/dis(temp1);
	struct point temp2;
    temp2.x=p.x-a1.x;
    temp2.y=p.y-a1.y;
    double k=Dot(e,temp2);
    struct point temp3;
    temp3.x=a1.x+k*e.x;
    temp3.y=a1.y+k*e.y;
    return temp3;
}

int main()
{
    struct point a1,a2,b1,b2;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a1.x,&a1.y,&a2.x,&a2.y,&b1.x,&b1.y,&b2.x,&b2.y)!=EOF)
    { 
	    if(is_cross(a1,a2,b1,b2))
		{
	        if(a1.x==a2.x&&a1.y==a2.y)
			{
	            if(on_seg(b1,b2,a1))
	            { 
	                printf("%f %f\n",a1.x,a1.y);
	            } 
	            else
	            { 
	                printf("none\n");
	            } 
	            continue;
	        }
	        if(b1.x==b2.x&&b1.y==b2.y)
			{
	            if(on_seg(a1,a2,b1))
	            { 
	                printf("%f %f\n",b1.x,b1.y);
	            } 
	            else
	            { 
	                printf("none\n");
	            } 
	            continue;
	        }
	        struct point temp1;
			temp1.x=a2.x-a1.x;
			temp1.y=a2.y-a1.y;
			struct point temp2;
			temp2.x=b2.x-b1.x;
			temp2.y=b2.y-b1.y;
	        if(Cross(temp1,temp2)!=0)
			{
	            struct point t1=Projection(b1,b2,a1);
	            struct point t2=Projection(b1,b2,a2);
	            struct point temp3;
				temp3.x=a1.x-t1.x;
				temp3.y=a1.y-t1.y;
				struct point temp4;
				temp4.x=a2.x-t2.x;
				temp4.y=a2.y-t2.y;
	            double d1=dis(temp3);
	            double d2=dis(temp4);
	            printf("%f %f\n",(d1/(d1+d2))*t2.x+(d2/(d1+d2))*t1.x,(d1/(d1+d2))*t2.y+(d2/(d1+d2))*t1.y);
	            continue;
	        }
	        else
			{
	            if((a1.x==b1.x&&a1.y==b1.y&&Dot(temp1,temp2)<0)||(a1.x==b2.x&&a1.y==b2.y&&Dot(temp1,temp2)>0))
	            { 
	                printf("%f %f\n",a1.x,a1.y);
	            } 
	            else if((a2.x==b1.x&&a2.y==b1.y&&Dot(temp1,temp2)>0)||(a2.x==b2.x&&a2.y==b2.y&&Dot(temp1,temp2)<0))
	            { 
	                printf("%f %f\n",a2.x,a2.y);
	            } 
	            else
	            { 
	                printf("none\n");
	            } 
	        }
	    }
	    else
	    { 
	        printf("none\n");
	    } 
    } 
}
