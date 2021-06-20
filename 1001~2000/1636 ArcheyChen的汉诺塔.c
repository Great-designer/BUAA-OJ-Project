#include<stdio.h>

char t[]={"XABC"};
long long r(int l,int f,int o)
{
    if(l==1)
    {
        printf("%c --> %c\n",t[f],t[o]);
        return 1;
    }
    long long a=0;
    a+=r(l-1,f,6-f-o);
    a+=r(1,f,o);
    a+=r(l-1,6-f-o,o);
    return a;
}
int main()
{
    int n;
    scanf("%d",&n);
    r(n,1,3);
}
