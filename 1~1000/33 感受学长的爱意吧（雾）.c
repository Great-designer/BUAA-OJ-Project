#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

double *caltwo(double a1,double b1,double c1,double a2,double b2,double c2)
{
	double *res=NULL;
	if((a1==0&&b1==0)||(a2==0&&b2==0)||(a1*b2==a2*b1))
	{
		return res;
	}
	else
	{
		res=(double*)malloc(sizeof(double)*2);
		res[0]=(b1*c2-b2*c1)/(a1*b2-a2*b1);
		res[1]=(a2*c1-a1*c2)/(a1*b2-a2*b1);
	}
	return res;
}

double a[9];

int main()
{
	while(~scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8]))
	{
		double **reses=(double**)malloc(sizeof(double*)*3);
		reses[0]=caltwo(a[0],a[1],a[2],a[3],a[4],a[5]);
		reses[1]=caltwo(a[0],a[1],a[2],a[6],a[7],a[8]);
		reses[2]=caltwo(a[3],a[4],a[5],a[6],a[7],a[8]);
		int nodup[3]={-1,-1,-1};
		int cnt=0;
		int i;
		for(i=0;i<3;i++)
		{
			if(reses[i]!=NULL)
			{
				int j;
				for(j=0;j<cnt;j++)
				{
					if((reses[nodup[j]][0]==reses[i][0])&&(reses[nodup[j]][1]==reses[i][1]))
					{
						break;
					}
				}
				if(j==cnt)
				{
					nodup[cnt++]=i;
				}
			}
		}
		for(i=0;i<cnt;i++)
		{
			int j;
			for(j=i+1;j<cnt;j++)
			{
				if(reses[nodup[i]][0]-reses[nodup[j]][0]>0.00001)
				{
					int tmp=nodup[i];
					nodup[i]=nodup[j];
					nodup[j]=tmp;
				}
				else if((fabs(reses[nodup[i]][0]-reses[nodup[j]][0])<0.00001)&&(reses[nodup[i]][1]-reses[nodup[j]][1]>0.00001))
				{
					int tmp=nodup[i];
					nodup[i]=nodup[j];
					nodup[j]=tmp;
				}
			}
		}
		printf("%d\n",cnt);
		for(i=0;i<cnt;i++)
		{
			double a=fabs(reses[nodup[i]][0])<0.001?0.0:reses[nodup[i]][0];
			double b=fabs(reses[nodup[i]][1])<0.001?0.0:reses[nodup[i]][1];
			printf("%.2f %.2f\n",a,b);
		}
	}
	return 0;
}

