#include<stdio.h>
#include<math.h>

int sgn(double x)
{
    if(fabs(x)<1e-6)
    {
    	return 0;
	}
    if(x<0)
    {
    	return -1;
	}
	else
	{
		return 1;
	}
}
 
struct Point
{
    double x,y; 
};

double max(double a,double b)
{
	return a>b?a:b;
}

double min(double a,double b)
{
	return a<b?a:b;
}

struct Point sub(struct Point a,struct Point b)
{
	struct Point temp;
	temp.x=a.x-b.x;
	temp.y=a.y-b.y;
    return temp;
}

double Cross(struct Point a,struct Point b)
{
    return a.x*b.y-a.y*b.x;
}

struct Line
{
    struct Point start,over;
};
     
char cs(struct Line l1,struct Line l2)
{
    return
         ( max(l1.start.x,l1.over.x)>=min(l2.start.x,l2.over.x)
         &&max(l2.start.x,l2.over.x)>=min(l1.start.x,l1.over.x)
         &&max(l1.start.y,l1.over.y)>=min(l2.start.y,l2.over.y)
         &&max(l2.start.y,l2.over.y)>=min(l1.start.y,l1.over.y)
         &&sgn(Cross(sub(l2.start,l1.start),sub(l1.over,l1.start)))*sgn(Cross(sub(l2.over,l1.start),sub(l1.over,l1.start)))<=0
         &&sgn(Cross(sub(l1.start,l2.start),sub(l2.over,l2.start)))*sgn(Cross(sub(l1.over,l2.start),sub(l2.over,l2.start)))<=0 );
}
 
struct Line line[100010];
char flag[100010];

int main()
{
    int n,i,j;
    double x1,y1,x2,y2;
    while(~scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
        {
            scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
            line[i].start.x=x1;
			line[i].start.y=y1;
			line[i].over.x=x2;
			line[i].over.y=y2;
            flag[i]=1;
        }
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
            	if(cs(line[i],line[j]))
                {
                    flag[i]=0;
                    break;
                }
			}
        }
        for(i=1;i<=n;i++)
        {
            if(flag[i])
            {
                printf("%d ",i);
            }
        }
        printf("\n");
    }
}
