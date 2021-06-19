#include<stdio.h>
#include<string.h>
#include<math.h>

double Pi=acos(-1.0); 

struct complex
{
	double re,im;
};

struct complex x1[200000],x2[200000];

char a[200000/2],b[200000/2];
int sum[200000];

void BRC(struct complex *y,int len)
{
	int i,j,k;
	for(i=1,j=len/2;i<len-1;i++)
	{
    	if(i<j)
		{
			struct complex temp;
			temp.re=y[i].re;
			temp.im=y[i].im;
			y[i].re=y[j].re;
			y[i].im=y[j].im;
			y[j].re=temp.re;
			y[j].im=temp.im;
		}
	    k=len/2;
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

void FFT(struct complex *y,int len,double on)
{
	int i,j,k,h;
	struct complex u,t;
	BRC(y,len);
	for(h=2;h<=len;h<<=1)
	{
		struct complex wn;
		wn.re=cos(2*Pi/h);
		wn.im=sin(on*2*Pi/h);
		for(j=0;j<len;j+=h)
	    {
			struct complex w;
			w.re=1;
			w.im=0;
	        for(k=j;k<j+h/2;k++)
	    	{
	            u=y[k];
	            t.re=w.re*y[k+h/2].re-w.im*y[k+h/2].im;
	            t.im=w.re*y[k+h/2].im+w.im*y[k+h/2].re;
	            y[k].re=u.re+t.re;
	            y[k].im=u.im+t.im;
	            y[k+h/2].re=u.re-t.re;
	            y[k+h/2].im=u.im-t.im;
	            struct complex temp;
	            temp.re=w.re*wn.re-w.im*wn.im;
	            temp.im=w.re*wn.im+w.im*wn.re;
	            w.re=temp.re;
	            w.im=temp.im;
	        }    
	    }
	}
	if(on==-1)
	{
		for(i=0;i<len;i++)
		{
			y[i].re/=len;
		}
	}
}

void Conv(struct complex a[],struct complex b[],int len)
{
	FFT(a,len,1);
	FFT(b,len,1);
	int i;
	for(i=0;i<len;i++)
	{
	    struct complex temp;
	    temp.re=a[i].re*b[i].re-a[i].im*b[i].im;
	    temp.im=a[i].re*b[i].im+a[i].im*b[i].re;
	    a[i].re=temp.re;
	    a[i].im=temp.im;
	}
	FFT(a,len,-1);
}

int sym;

int main()
{
	int len1,len2,len,i;
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
    	for(i=0;i<len1;i++)
	    { 
			x1[i].re=a[len1-1-i]-'0';
			x1[i].im=0.0;
		}
	    for(;i<len1;i++)
	    {
			x1[i].re=x1[i].im=0.0;
		}
	    for(i=0;i<len2;i++)
	    { 
			x2[i].re=b[len2-1-i]-'0';
			x2[i].im=0.0;
		}
	    for(;i<len2;i++)
	    {
			x2[i].re=x2[i].im=0.0;
		}
		Conv(x1,x2,len);
	    for(i=0;i<len;i++)
	    {
	    	sum[i]=x1[i].re+0.5;
		}
	    for(i=0;i<len;i++)
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
	    for(i=len;i>=0;i--)
		{
	    	printf("%d",sum[i]);
	    }
		printf("\n");
	}
	return 0;
}
