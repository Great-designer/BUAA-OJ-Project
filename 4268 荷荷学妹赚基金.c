#include <stdio.h>

int n;
double money,tax;

int main(void)
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lf",&money);
        if(money<=800)
        tax=money;
        else if(money<=1500)
        tax=800+(money-800)*0.8;
        else tax=800+700*0.8+(money-1500)*0.75;

        printf("%.2f\n",tax);
    }
    return 0;
}