#include<stdio.h>
#include<math.h>
#include<string.h>

double PI=acos(-1.0);

struct Vir
{
    double re,im;
};

void bitrev(struct Vir *a,int loglen,int len)
{
	int i;
    for(i=0;i<len;++i)
    {
        int t=i,p=0;
        int j;
        for(j=0;j<loglen;++j)
        {
            p<<=1;
            p=p|(t&1);
            t>>=1;
        }
        if(p<i)
        {
            struct Vir temp=a[p];
            a[p]=a[i];
            a[i]=temp;
        }
    }
}

void FFT(struct Vir *a,int loglen,int len,int on)
{
    bitrev(a,loglen,len);
    int s,m;
    for(s=1,m=2;s<=loglen;++s,m<<=1)
    {
        struct Vir wn;
		wn.re=cos(2*PI*on/m);
		wn.im=sin(2*PI*on/m);
        int i;
        for(i=0;i<len;i+=m)
        {
            struct Vir w;
			w.re=1;
			w.im=0;
            int j;
            for(j=0;j<m/2;++j)
            {
                struct Vir u=a[i+j];
                struct Vir v;
                v.re=w.re*a[i+j+m/2].re-w.im*a[i+j+m/2].im;
                v.im=w.re*a[i+j+m/2].im+w.im*a[i+j+m/2].re;
                a[i+j].re=u.re+v.re;
                a[i+j].im=u.im+v.im;
                a[i+j+m/2].re=u.re-v.re;
                a[i+j+m/2].im=u.im-v.im;
                struct Vir temp;
                temp.re=w.re*wn.re-w.im*wn.im;
                temp.im=w.re*wn.im+w.im*wn.re;
                w=temp;
            }
        }
    }
    if(on==-1)
    {
    	int i;
        for(i=0;i<len;++i)
		{
			a[i].re/=len,a[i].im/=len;
		}
    }
}

char a[505050*2],b[505050*2];
struct Vir pa[505050*2],pb[505050*2];
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
        for(i=0,j=lena-1;i<n;++i,--j)
        {
        	pa[i].re=(j>=0?a[j]-'0':0);
        	pa[i].im=0;
		}
        for(i=0,j=lenb-1;i<n;++i,--j)
        {
        	pb[i].re=(j>=0?b[j]-'0':0);
        	pb[i].im=0;
		}
        for(i=0;i<=n;++i)
        {
            ans[i]=0;
        }
        FFT(pa,loglen,n,1);
        FFT(pb,loglen,n,1);
        for(i=0;i<n;++i)
        {
        	struct Vir temp;
            temp.re=pa[i].re*pb[i].re-pa[i].im*pb[i].im;
            temp.im=pa[i].re*pb[i].im+pa[i].im*pb[i].re;
            pa[i]=temp;
		}
        FFT(pa,loglen,n,-1);
        for(i=0;i<n;++i)
		{
			ans[i]=pa[i].re+0.5;
		}
        for(i=0;i<n;++i)
		{
			ans[i+1]+=ans[i]/8,ans[i]%=8;
		}
        int pos=lena+lenb-1;
        while(pos>0&&ans[pos]<=0)
        {
        	--pos;
		}
        for(;pos>=0;--pos)
		{
			printf("%d",ans[pos]);
		}
        printf("\n");
    }
    return 0;
}
