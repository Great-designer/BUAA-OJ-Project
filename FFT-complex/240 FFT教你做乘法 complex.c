#include<stdio.h>
#include<math.h>
#include<string.h>
#include<complex.h>

#define PI acos(-1.0)

void bitrev(complex double *a,int loglen,int len)
{
	int i;
	for(i=0; i<len; ++i)
	{
		int t=i,p=0;
		int j;
		for(j=0; j<loglen; ++j)
		{
			p<<=1;
			p=p|(t&1);
			t>>=1;
		}
		if(p<i)
		{
			complex double temp=a[p];
			a[p]=a[i];
			a[i]=temp;
		}
	}
}

void FFT(complex double *a,int loglen,int len,int on)
{
	bitrev(a,loglen,len);
	int s,m;
	for(s=1,m=2; s<=loglen; ++s,m<<=1)
	{
		complex double wn=cos(2*PI*on/m)+sin(2*PI*on/m)*I;
		int i;
		for(i=0; i<len; i+=m)
		{
			complex double w=1;
			int j;
			for(j=0; j<m/2; ++j)
			{
				complex double u=a[i+j];
				complex double v;
				v=w*a[i+j+m/2];
				a[i+j]=u+v;
				a[i+j+m/2]=u-v;
				complex double temp;
				temp=w*wn;
				w=temp;
			}
		}
	}
	if(on==-1)
	{
		int i;
		for(i=0; i<len; ++i)
		{
			a[i]/=len;
		}
	}
}

char a[505050*2],b[505050*2];
complex double pa[505050*2],pb[505050*2];
int ans[505050*2];

int main()
{
	while(~scanf("%s%s",a,b))
	{
		int lena=strlen(a);
		int lenb=strlen(b);
		int n=1,loglen=0;
		while(n<lena+lenb)
		{
			n<<=1,loglen++;
		}
		int i,j;
		for(i=0,j=lena-1; i<n; ++i,--j)
		{
			pa[i]=(j>=0?a[j]-'0':0);
		}
		for(i=0,j=lenb-1; i<n; ++i,--j)
		{
			pb[i]=(j>=0?b[j]-'0':0);
		}
		for(i=0; i<=n; ++i)
		{
			ans[i]=0;
		}
		FFT(pa,loglen,n,1);
		FFT(pb,loglen,n,1);
		for(i=0; i<n; ++i)
		{
			complex double temp;
			temp=pa[i]*pb[i];
			pa[i]=temp;
		}
		FFT(pa,loglen,n,-1);
		for(i=0; i<n; ++i)
		{
			ans[i]=creal(pa[i])+0.5;
		}
		for(i=0; i<n; ++i)
		{
			ans[i+1]+=ans[i]/8;
			ans[i]%=8;
		}
		int pos=lena+lenb-1;
		while(pos>0&&ans[pos]<=0)
		{
			--pos;
		}
		for(; pos>=0; --pos)
		{
			printf("%d",ans[pos]);
		}
		printf("\n");
	}
	return 0;
}
