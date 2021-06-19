#include <stdio.h>
#include <limits.h>

#define ms 10005
//�����������½磬���ҵ�[l,r)�е�һ�����ڵ���val�����֣����������п��Բ���val���������ƻ�����˳��ĵ�һ��λ�ã�����ҿ�������ȽϺ���⣬��Ҳ�������Ապ�����Ķ��ֲ���
//�����������Ͻ磬���ҵ�[l,r)�е�һ������val�����֣����������п��Բ���val���������ƻ�����˳������һ��λ�ã��Ա�һ�º�lower_bound��ʲô��ͬ
int * upper_bound(int* l, int * r, int val)
{ 
    int * m; 
    while(l<r) 
    { 
        m=l+((r-l)>>1); 
        if (*m<=val) 
        { 
            l=m+1; 
        }
		else 
        { 
            r=m; 
        } 
    } 
    return l;
}
//�����������½磬���ҵ�[l,r)�е�һ��С�ڵ���val�����֣����������п��Բ���val���������ƻ�����˳��ĵ�һ��λ��
int * lower_bound1(int* l, int * r, int val)
{ 
    int * m; 
    while (l<r) 
    { 
        m=l+((r-l)>>1); 
        if (*m>val) 
        { 
            l=m+1; 
        } 
        else 
        { 
            r=m; 
        } 
    } 
    return l;
}
//�����������Ͻ磬���ҵ�[l,r)�е�һ��С��val�����֣����������п��Բ���val���������ƻ�����˳������һ��λ��
int a[ms], b[ms]; 
int n, m;
int main()
{ 
    int k; 
    while(~scanf("%d%d%d",&n,&m,&k))
	{ 
        for(int i=0;i<n;i++) 
        { 
            scanf("%d",a+i); 
        } 
        for(int i=0;i<m;i++) 
        { 
            scanf("%d",b+i); 
        }
		while(k--) 
        { 
            int c; 
            scanf("%d", &c); 
            int l=upper_bound(a,a+n,c)-a; 
            int r=lower_bound1(b,b+m,c)-b; //���������д���c�ķֱ���n-l����r������ΪҪ�����������������ս��+1 ? ? ? ? ? ?
            int res=n-l+r+1; //�������c����c������a[l-1]��b[r]������һ�Σ�ע��߽��������ж� ? ? ? ? ? ?
            if ((l>0&&a[l-1]==c)||(r<m&&b[r]==c)) 
            { 
                printf("%d ",res); 
            } 
            else 
            { 
                printf("-1 "); 
            } 
        }
		printf("\n"); 
    }
    return 0;
}

