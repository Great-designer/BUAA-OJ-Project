#include<stdio.h>
int a,b,c,y,m,d;

int main()
{
    scanf("%d%d%d",&y,&m,&d);
    scanf("%d%d%d",&a,&b,&c);
    if (b==m&&c==d&&a>y)
    {
        printf("Anniversary!");
        return 0;
    }
    printf("%d",c);
    if (c==1||c==21||c==31)
        printf("st ");
    else if (c==2||c==22)
        printf("nd ");
    else if (c==3||c==23)
        printf("rd ");
    else
        printf("th ");
    if (b==1)
        printf("Jan.");
    if (b==2)
        printf("Feb.");
    if (b==3)
        printf("Mar.");
    if (b==4)
        printf("Apr.");
    if (b==5)
        printf("May.");
    if (b==6)
        printf("Jun.");
    if (b==7)
        printf("Jul.");
    if (b==8)
        printf("Aug.");
    if (b==9)
        printf("Sept.");
    if (b==10)
        printf("Oct.");
    if (b==11)
        printf("Nov.");
    if (b==12)
        printf("Dec.");
}
