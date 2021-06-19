#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int n;

int dcmp(double x)
{
	if(fabs(x)<1e-8)
	{
		return 0;
	}
	else 
	{
		return x>0?1:-1;
	}
} 

struct Point 
{
	double x,y;
};

struct Point p[100005],ch[100005]; 

int myCmp(const void*p1,const void*p2)
{
	struct Point*A=(struct Point*)p1;
	struct Point*B=(struct Point*)p2;
	if(A->x!=B->x)
	{
		return (B->x)-(A->x);
	}
	else
	{
		return (B->y)-(A->y);
	}
}

double Cross(struct Point A,struct Point B) 
{
	return A.x * B.y - A.y * B.x;
}

int ConvexHull()
{
	qsort(p,n,sizeof(struct Point),myCmp);
	int m=0;
	int i;
	for(i=0;i<n;i++)
	{  // �������������õ���ǰ��������ұ�ʱ��ʹ�ò���жϣ���ɾ��ǰ�����Ҷ˵㣬// ѭ����ֱ�����ڣ������õ���룬�����ұߣ���ֱ�Ӽ��� 
		struct Point A;
		struct Point B;
		A.x=ch[m-1].x-ch[m-2].x;
		A.y=ch[m-1].y-ch[m-2].y;
		B.x=p[i].x-ch[m-2].x;
		B.y=p[i].y-ch[m-2].y;
		int dc=dcmp(Cross(A,B)); 
		while(m>1&&dc<=0)
		{
			m--;
			A.x=ch[m-1].x-ch[m-2].x;
			A.y=ch[m-1].y-ch[m-2].y;
			B.x=p[i].x-ch[m-2].x;
			B.y=p[i].y-ch[m-2].y;
			dc=dcmp(Cross(A,B));
		}
		ch[m++]=p[i];
	}
	int k=m;
	for(i=n-2;i>=0;i--)
	{  // �� pn-1 �Ѿ����������ʴ�n-2��ʼ // ����͹���������γɺ�Χ��Ϊ����͹��
		struct Point A;
		struct Point B;
		A.x=ch[m-1].x-ch[m-2].x;
		A.y=ch[m-1].y-ch[m-2].y;
		B.x=p[i].x-ch[m-2].x;
		B.y=p[i].y-ch[m-2].y;
		int dc=dcmp(Cross(A,B)); 
		while(m>k&&dc<=0)
		{
			m--;
			A.x=ch[m-1].x-ch[m-2].x;
			A.y=ch[m-1].y-ch[m-2].y;
			B.x=p[i].x-ch[m-2].x;
			B.y=p[i].y-ch[m-2].y;
			dc=dcmp(Cross(A,B));
		}
		ch[m++]=p[i]; 
	}
	if(n>1)
	{
		m--;  // ��Ҫ�γ�͹��������ʼ���ظ�����1
	}
	return m;  //���ض������
}

double Dis(struct Point A,struct Point B)
{
	return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

int main()
{
	int m;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		p[i].x=a;
		p[i].y=b;
	}
	m=ConvexHull();
	double ans=0.0; 
	for(i=0;i<m-1;i++)
	{
		ans+=Dis(ch[i],ch[i+1]);
	}
	ans+=Dis(ch[m-1],ch[0]);
	printf("%.2lf ",ans);
	ans=0.0; 
	ch[m]=ch[0];
	for(i=0;i<m;i++)
	{
		ans+=(ch[i].x*ch[i+1].y-ch[i+1].x*ch[i].y);
	}
	ans=ans/2;
	printf("%.2lf\n",ans); 
} 

