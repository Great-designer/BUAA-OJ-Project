#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a;
        scanf("%d",&a);
        if(a>=85&&a<=100)
        {
            printf("A\n");
        }
        if(a>=70&&a<=84)
        {
            printf("B\n");
        }
        if(a>=60&&a<=69)
        {
            printf("C\n");
        }
        if(a<60)
        {
            printf("D\n");
        }
    }
}
