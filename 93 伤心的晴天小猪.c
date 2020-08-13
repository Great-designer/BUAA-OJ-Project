#include<stdio.h>
#include<ctype.h>

int notRun[13]={ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int Run[13]={ 0,31,29,31,30,31,30,31,31,30,31,30,31 };
int t;
int y,m,d,h,mi,s;

char isRun(int cur)
{
    return (cur%4==0&&cur%100!=0||cur%400==0);
}

char isMonth(int cur)
{
    return cur>=1&&cur<=12;
}

char isDay(int cur,int m,char flag)
{
    return flag?(cur>=1&&cur<=Run[m]):(cur>=1&&cur<=notRun[m]);
}

char all;
char flag;

int main()
{
	scanf("%d",&t);
    while(t--)
	{
		scanf("%d%d%d%d%d%d",&y,&m,&d,&h,&mi,&s);
        flag=isRun(y);
        all=isMonth(m)&&isDay(d,m,flag);
        flag=(h>=0&&h<=23)&&(mi>=0&&mi<=59)&&(s>=0&&s<=59);
        all=all&&flag;
        if(all)
		{
			printf("Good bye!\n");
		}
		else
		{
			printf("Please wait for a moment!\n");
		}
    }
}
