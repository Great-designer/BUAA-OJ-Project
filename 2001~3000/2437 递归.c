#include<stdio.h>
#include<stdlib.h>

int n;
int a[1055576];
int ba,bb,ta,tb;

void output(int x)
{
    int i=0;
    while(a[x])
    {
        if(a[x]&1)
        {
            printf("%d",i+1);
            putchar(' ');
        }
        i++;
        a[x]>>=1;
    }
    putchar('\n');
}

int cmp(const void *A,const void *B)
{
    ba=__builtin_popcount(ta=*(const int*)A);//ba存储的是a中1的个数，ta存储的是a
    bb=__builtin_popcount(tb=*(const int*)B);
    while((ta&1)==(tb&1)&&ta&&tb)//长度相同的情况下，则找第一个不同的位
    {
        ta>>=1,tb>>=1;
    }
    if(ta!=0&&tb==0)
    {
    	return 1;
	}
	else if(ta==0&&tb!=0)
    {
    	return -1;
	}
    return ta&1?-1:1;
}

int main()
{
    scanf("%d",&n);
    int i;
    for(i=1;i<(1<<n);i++)
    {
        a[i]=i;
    }
    qsort(a+1,(1<<n)-1,sizeof(int),cmp);
    for(i=1;i<(1<<n);i++)
    {
        output(i);
    }
    return 0;
}
