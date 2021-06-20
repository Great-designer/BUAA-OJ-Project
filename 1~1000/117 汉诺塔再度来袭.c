#include<stdio.h>
#include<math.h>
 
int f(int n,char start,char over,char middle)
{
    if(n==1)
    {
        printf("%d %c->%c\n",n,start,over);
    }
    else
    {
        f(n-1,start,middle,over);
        printf("%d %c->%c\n",n,start,over);
        f(n-1,middle,over,start);
    }
}
int main()
{
    char A='A';
    char C='B';
    char B='C';
    int n;
    while(~scanf("%d",&n))
    {
        printf("%.0lf\n",pow(2,n)-1);
        f(n,A,B,C);
    }
}

