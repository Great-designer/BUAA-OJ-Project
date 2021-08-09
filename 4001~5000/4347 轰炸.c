#include<stdio.h>

struct rect
{
	int x1,y1,x2,y2;
};

struct rect A[310];
int TOP;

int find(int xi,int yi)
{
	int i;
	for(i=TOP;i>=1;i--)
	{
		if(A[i].x2>=xi&&A[i].x1<=xi&&A[i].y2>=yi&&A[i].y1<=yi)
		{
			return i;
		}
	}
	return i;
}

int main()
{
	int n, m, x, y,a[310][310]={},xi,yi;
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for (int k = 1; k <= x;k++)
	{
		TOP++;
		scanf("%d%d%d%d", &A[TOP].x1, &A[TOP].y1, &A[TOP].x2, &A[TOP].y2);
		a[A[TOP].x1][A[TOP].y1]++;
		a[A[TOP].x2+1][A[TOP].y1]--;
		a[A[TOP].x1][A[TOP].y2+1]--;
		a[A[TOP].x2+1][A[TOP].y2+1]++;
	}
	for (int i = 1; i <= 300;i++)
	{
		a[i][0]=a[i][0]+a[i-1][0];
	}
	for (int j = 1; j <= 300;j++)
	{
		a[0][j]=a[0][j]+a[0][j-1];
	}
	for (int i = 1; i <= 300;i++)
	{
		for (int j = 1; j <= 300;j++)
		{
			a[i][j]=a[i][j]+a[i][j-1]+a[i-1][j]-a[i-1][j-1];
		}
	}
	while(y--)
	{
		scanf("%d%d", &xi, &yi);
		if(a[xi][yi]>0)
			printf("Y %d %d\n", a[xi][yi], find(xi,yi));
		else
			printf("N\n");
	}
}