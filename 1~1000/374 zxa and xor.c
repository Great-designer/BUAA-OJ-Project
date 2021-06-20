#include<stdio.h> 

int a[210000];

struct data
{
    int l,r,lazy;
    int n0,n1;
};

struct data tr[2100000];

void pushdown(int k)
{
    if(tr[k].lazy)
    {
    	int temp=tr[k].n0;
    	tr[k].n0=tr[k].n1;
    	tr[k].n1=temp;
        if (tr[k].l!=tr[k].r)
		{
			tr[k<<1].lazy^=1;
			tr[k<<1|1].lazy^=1;
		}
        tr[k].lazy=0;
    }
}
void update(int k)
{
    pushdown(k<<1);
    pushdown(k<<1|1);
    tr[k].n0=tr[k<<1].n0+tr[k<<1|1].n0;
    tr[k].n1=tr[k<<1].n1+tr[k<<1|1].n1;
}

void lchange(int k,int a,int b)
{
    int l=tr[k].l,r=tr[k].r;
    pushdown(k);
    if(a==l&&b==r)
    {
        tr[k].lazy^=1;
        pushdown(k);
        return;
    }
	int mid=(l+r)>>1;
    if(b<=mid)
	{
		lchange(k<<1,a,b);
	}
    else if(a>mid)
	{
		lchange(k<<1|1,a,b);
	}
    else
	{
		lchange(k<<1,a,mid);
		lchange(k<<1|1,mid+1,b);
	}
    update(k);
}

int lask(int k,int a,int b,int c)
{
    pushdown(k);
    int l=tr[k].l,r=tr[k].r;
    if(a==l&&b==r)
    {
        if(c==0)
		{
			return tr[k].n0;
		}
        else
		{
			return tr[k].n1;
		}
    }
    int mid=(l+r)>>1;
    int tmp;
    if(b<=mid)
	{
		tmp=lask(k<<1,a,b,c);
	}
    else if(a>mid)
	{
		tmp=lask(k<<1|1,a,b,c);
	}
    else
	{
		tmp=lask(k<<1,a,mid,c)+lask(k<<1|1,mid+1,b,c);
	}
    update(k);
    return tmp;
}

void build(int k,int l,int r)
{
    tr[k].l=l;
	tr[k].r=r;
    tr[k].lazy=0;
    if(l==r)
    {
        if(a[l]==0)
		{
			tr[k].n0=1;
			tr[k].n1=0;
		}
        else
		{
			tr[k].n1=1;
			tr[k].n0=0;
		}
        return;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    update(k);
}

int q;    
long long ans;
int n;

int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&n);
        int i;
        for(i=2;i<=n+1;i++)
        {
        	scanf("%d",&a[i]);
			a[i]^=a[i-1];
		}
        n++;
        build(1,1,n);
        scanf("%d",&q);
        for(i=1;i<=q;i++)
        {
            int op,x,y;
            scanf("%d",&op);
            if(op==0)
            {
                scanf("%d %d",&x,&y);
                x++,y++;
                long long cf=0;
                int l0=lask(1,x-1,y-1,0),l1,r0=lask(1,x,y,0),r1;
                l1=(y-x+1-l0);
                r1=(y-x+1-r0);
                ans=(long long)l0*(long long)r0+(long long)l1*(long long)r1;
                if(x!=y)
                {
                    int xx=lask(1,x,y-1,0),yy;
                    yy=(y-x-xx);
                    cf=((long long)xx*(long long)xx+(long long)yy*(long long)yy+(long long)y-(long long)x)/2LL;
                }
                ans-=cf;
                printf("%lld\n",ans);
            }
            else if(op==1)
            {
                scanf("%d %d",&x,&y);
                x++,y++;
                long long cf=0;
                int l0=lask(1,x-1,y-1,0),l1,r0=lask(1,x,y,0),r1;
                l1=(y-x+1-l0);
                r1=(y-x+1-r0);
                ans=(long long)l0*(long long)r1+(long long)l1*(long long)r0;
                if(x!=y)
                {
                	int xx=lask(1,x,y-1,0),yy;
                	yy=(y-x-xx);
                    cf=((long long)xx*(long long)yy+(long long)xx*(long long)yy)/2LL;
                }
                ans-=cf;
                printf("%lld\n",ans);
            }
            else 
            {
                scanf("%d",&x);
                x++;
                lchange(1,x,n);
            }
        }
    }
    return 0;
}

