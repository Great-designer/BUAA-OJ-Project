#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#include<math.h>
#include<algorithm>

using namespace std;

int dcmp(double x)
{
	if(fabs(x)<1e-10)
	{
		return 0;
	}
    else
	{
		return x<0?-1:1;
	}
}

struct Point
{
    double x,y;
};

int compare(const void *p1,const void *p2)
{
	struct Point *a=(struct Point*)p1;
	struct Point *b=(struct Point*)p2;
	return (a->x<b->x)||((a->x==b->x)&&(a->y<b->y));
}

bool same(struct Point a,struct Point b)
{
	return (a.x==b.x)&&(a.y==b.y);
}

double Dot(struct Point A,struct Point A0,struct Point B,struct Point B0)
{ 
	return (A.x-A0.x)*(B.x-B0.x)+(A.y-A0.y)*(B.y-B0.y);
}

double Cross(struct Point A,struct Point A0,struct Point B,struct Point B0)
{
	return (A.x-A0.x)*(B.y-B0.y)-(A.y-A0.y)*(B.x-B0.x);
}

char OnSegment(struct Point p,struct Point a,struct Point b)
{
    return (dcmp(Cross(a,p,b,p))==0)&&(dcmp(Dot(a,p,b,p))<0);
}

char SegmentIntersection(struct Point a1,struct Point a2,struct Point b1,struct Point b2)
{
    return (dcmp(Cross(a2,a1,b1,a1)*Cross(a2,a1,b2,a1))<0)&&(dcmp(Cross(b2,b1,a1,b1)*Cross(b2,b1,a2,b1))<0);
}

void ConvexHull(struct Point p[],int *topp,struct Point ch[],int *topch)
{
	qsort(p,*topp,sizeof(struct Point),compare);
	int n=unique(p,p+*topp,same)-p;
	*topp=n;
	int m=0;
	*topch=0;
	int i;
    for(i=0;i<=n+1;i++)
    {
    	struct Point temp;
		temp.x=0;
		temp.y=0; 
    	ch[*topch]=temp;
    	(*topch)++;
	}
	for(i=0;i<n;++i)
    {
        while((m>1)&&(Cross(ch[m-1],ch[m-2],p[i],ch[m-2])<=0))
		{
			m--;
		}
        ch[m++]=p[i];
    }
    int k=m;
    for(i=n-2;i>=0;--i)
    {
        while((m>k)&&(Cross(ch[m-1],ch[m-2],p[i],ch[m-2])<=0))
		{
			m--;
		}
        ch[m++]=p[i];
    }
    if(m>1)
	{
		m--;
	}
    *topch=m;
}

int IsPointInPolygon(struct Point p,struct Point poly[],int toppoly)
{
	int wn=0;
    int i;
    for(i=0;i<toppoly;++i)
    {
        if(OnSegment(p,poly[i],poly[(i+1)%toppoly]))
		{
			return -1;
		}
        int k=dcmp(Cross(poly[(i+1)%toppoly],poly[i],p,poly[i]));
        int d1=dcmp(poly[i].y-p.y);
        int d2=dcmp(poly[(i+1)%toppoly].y-p.y);
        if((k>0)&&(d1<=0)&&(d2>0))
		{
			wn++;
		}
        if((k<0)&&(d2<=0)&&(d1>0))
		{
			wn--;
		}
    }
    if(wn)
	{
		return 1;
	}
    return 0;
}

char ConvexPolygonDisjiont(struct Point ch1[],int topch1,struct Point ch2[],int topch2)
{
	int i;
    for(i=0;i<topch1;++i)
    {
    	if(IsPointInPolygon(ch1[i],ch2,topch2)!=0)
    	{
    		return 0;
		}
	}
	for(i=0;i<topch2;++i)
    {
    	if(IsPointInPolygon(ch2[i],ch1,topch1)!=0)
    	{
    		return 0;
		}
	}
	for(i=0;i<topch1;++i)
    {
    	int j;
    	for(j=0;j<topch2;++j)
    	{
    		if(SegmentIntersection(ch1[i],ch1[(i+1)%topch1],ch2[j],ch2[(j+1)%topch2]))
    		{
    			return 0;
			}
		}
	}
	return 1;
}

struct Point ch1[5005],ch2[5005];
int topch1,topch2;
struct Point p1[5005],p2[5005];
int topp1,topp2;

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        if(!n&&!m)
		{
			break;
		}
		topp1=0;
		topp2=0;
        int i;
        for(i=0;i<n;++i)
        {
            scanf("%lf%lf",&p1[topp1].x,&p1[topp1].y);
            topp1++;
        }
        for(i=0;i<m;++i)
        {
            scanf("%lf%lf",&p2[topp2].x,&p2[topp2].y);
            topp2++;
        }
        ConvexHull(p1,&topp1,ch1,&topch1);
        ConvexHull(p2,&topp2,ch2,&topch2);
        if(ConvexPolygonDisjiont(ch1,topch1,ch2,topch2))
		{
			printf("YES\n");
		}
        else
		{
			printf("NO\n");
		}
	}
	return 0;
}

