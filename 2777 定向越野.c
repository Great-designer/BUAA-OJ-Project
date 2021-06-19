#include<stdio.h>

struct Point
{
    double x,y;
};

double cross(struct Point *a,struct Point *b)
{
    return a->x*b->y-a->y*b->x;
}

double direct(struct Point *a,struct Point *b,struct Point *c)
{
	struct Point temp1;
	temp1.x=b->x-a->x;
	temp1.y=b->y-a->y;
	struct Point temp2;
	temp2.x=c->x-a->x;
	temp2.y=c->y-a->y;
    return cross(&temp1,&temp2);
}

int n;
long long ans;
struct Point a[10010];

int main()
{
    while(~scanf("%d",&n))
	{
		int i;
        for(i=0;i<n;++i)
		{
			scanf("%lf%lf",&a[i].x,&a[i].y);
		}
        for(i=2;i<n;++i)
		{
            double dir=direct(&a[i-2],&a[i-1],&a[i]);
            if(dir>0)
			{
				printf("L ");
			}
            else if(dir<0)
			{
				printf("R ");
			}
        }
        printf("\n");
    }
    return 0;
}
