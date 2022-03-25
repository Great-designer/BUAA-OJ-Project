#include<stdio.h>
#include<string.h>
#include<math.h>
#include<complex.h>

#define Pi acos(-1.0)

double complex x1[200000],x2[200000];

char a[200000/2],b[200000/2];
int sum[200000];

void BRC(double complex *y,int len)
{
	int i,j;
	for(i=1,j=len/2; i<len-1; i++)
	{
		if(i<j)
		{
			double complex temp=y[i];
			y[i]=y[j];
			y[j]=temp;
		}
		int k=len/2;
		while(j>=k)
		{
			j-=k;
			k=k/2;
		}
		if(j<k)
		{
			j+=k;
		}
	}
}

void FFT(double complex *y,int len,double on)
{
	BRC(y,len);
	int h;
	for(h=2; h<=len; h<<=1)
	{
		double complex wn=cexp(on*2*Pi/h*I);
		int j;
		for(j=0; j<len; j+=h)
		{
			double complex w=1;
			int k;
			for(k=j; k<j+h/2; k++)
			{
				double complex u=y[k];
				double complex t=w*y[k+h/2];
				y[k]=u+t;
				y[k+h/2]=u-t;
                w=w*wn;
			}
		}
	}
	if(on==-1)
	{
		int i;
		for(i=0; i<len; i++)
		{
			y[i]/=len;
		}
	}
}

int sym;

int main()
{
	int len1,len2,len,i;
	getchar();
	while(scanf("%s %s",a,b)!=EOF)
	{
		sym=0;
		memset(x1,0,sizeof(x1));
		memset(x2,0,sizeof(x2));
		memset(sum,0,sizeof(sum));
		if(a[0]=='-')
		{
			sym^=1;
			a[0]='0';
		}
		if(b[0]=='-')
		{
			sym^=1;
			b[0]='0';
		}
		len1=strlen(a);
		len2=strlen(b);
		len=1;
		while(len<2*len1||len<2*len2)
		{
			len<<=1;
		}
		for(i=0; i<len1; i++)
		{
			x1[i]=a[len1-1-i]-'0';
		}
		for(; i<len1; i++)
		{
			x1[i]=0.0;
		}
		for(i=0; i<len2; i++)
		{
			x2[i]=b[len2-1-i]-'0';
		}
		for(; i<len2; i++)
		{
			x2[i]=0.0;
		}
		FFT(x1,len,1);
		FFT(x2,len,1);
		for(i=0; i<len; i++)
		{
			x1[i]=x1[i]*x2[i];
		}
		FFT(x1,len,-1);
		for(i=0; i<len; i++)
		{
			sum[i]=creal(x1[i])+0.5;
		}
		for(i=0; i<len; i++)
		{
			sum[i+1]+=sum[i]/10;
			sum[i]%=10;
		}
		len=len1+len2-1;
		while(sum[len]<=0&&len>0)
		{
			len--;
		}
		if(sym==1)
		{
			printf("-");
		}
		for(i=len; i>=0; i--)
		{
			printf("%d",sum[i]);
		}
		printf("\n");
	}
	return 0;
}
