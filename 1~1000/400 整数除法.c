#include<stdio.h>
#include<math.h>

int main()
{
    long int a,b,c,d,e;
    scanf("%ld %ld",&a,&b);
    if(b==0)
    {
        printf("error");
    }
    else
    {
        c=a%b;
        if(b>0&&c<0)
        {
            c=c+abs(b);
        }
        if(b<0&&c>0)
        {
            c=c-abs(b);
        }
        d=a-c;
        e=d/b;
        printf("%ld",e);
    }
}
